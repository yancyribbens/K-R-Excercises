/* 
 * Excercise 1-8
 *
 * Write a program to count blanks, tabs and newlines.
 */

#include <stdio.h>

main()
{
    int c, n1, t1, blanks;

    n1 = t1 = blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++n1;
        if (c == '\t')
            ++t1;
        if (c == ' ')
            ++blanks;
    }

    printf("lines %d\n tabs %d\n blanks %d", n1, t1, blanks);
}
