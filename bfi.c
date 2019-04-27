#include <stdio.h>
#define SOURCE_SIZE 8192
#define TAPE_SIZE 8192

/* TODO?: dynamically sized */
char source[SOURCE_SIZE];
char tape[TAPE_SIZE];

int
main(int argc, char *argv[])
{
	FILE *src;
	int parens;
	char *ptr, *pc;

	/* check args and usage */
	if (argc != 2) {
		printf("usage: bfi <input>\n");
		return 1;
	}

	/* read source file into memory */
	src = fopen(argv[1], "r");
	if (!src) {
		printf("bfi: error reading file\n");
		return 1;
	}
	for (pc = source; (*pc = getc(src)) != EOF; pc++);
	fclose(src);

	/* TODO: optimize?
         - remove comments from source
	     - compacted instructions
	       - 2 bit opcode
	         - 00 add
	         - 01 jmp
	         - 10 jz
	         - 11 jnz
	       - 1 bit extend flag
	       - 5 bit signed int
	       ...
	       - 1 bit extend flag
	       - 7 bit signed int
	       ...
	     - multipass optimization
	       1. remove comments
	       2. compact add & jmp
	       3. precalculate jz/jnz
	*/

	/* iterate through program, processing stdin */
	for (pc = source, ptr = tape; *pc != EOF; pc++) {
		switch (*pc) {
		case '>': /* jmp +1 */
			ptr++;
			break;
		case '<': /* jmp -1 */
			ptr--;
			break;
		case '+': /* add +1 */
			(*ptr)++;
			break;
		case '-': /* add -1 */
			(*ptr)--;
			break;
		case '.': /* putc */
			putc(*ptr, stdout);
			break;
		case ',': /* getc */
			if ((*ptr = getc(stdin)) == EOF)
				return 1;
			break;
		case '[': /* jz ->] */
			if (*ptr)
				break;
			for (parens = 1; parens; pc++)
				if (*(pc+1) == '[')
					parens++;
				else if (*(pc+1) == ']')
					parens--;
			break;
		case ']': /* jnz <-[ */
			if (!*ptr)
				break;
			for (parens = 1; parens; pc--)
				if (*(pc-1) == '[')
					parens--;
				else if (*(pc-1) == ']')
					parens++;
			break;
		}
	}
	return 0;
}
