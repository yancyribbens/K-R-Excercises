/* Exercise 1-9
 *
 * Write a program to copy its input to its output,
 * replacing each string of one or more blanks by
 * a single blank.
 */

#include <stdio.h>

main() {
    int c;
    int blank_flag;

    blank_flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (blank_flag == 0) {
                putchar(c);
                blank_flag = 1;
            }
        } else {
            blank_flag = 0;
            putchar(c);
        }
    }
}
