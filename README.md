bfi
====
A simple Brainfuck interpreter written in C.

The Brainfuck program is inputted as an argument, while the program's input is handled through stdin. It is recommended to either pipe or redirect the input to allow for a clean output.

Usage
-----
1. `make`
2. `./bfi <filename>`

Known Issues
------------
* Static arrays are used, so larger programs may segfault.
* Execution is quite inefficient, as comments (and even whitespace!) are "executed"

License
-------

    Copyright (c) 2019 William Sengir <wsengir@asu.edu>

    Permission to use, copy, modify, and/or distribute this software for any
    purpose with or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
