/* Excercise 1-20
 *
 * Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop.  Assume a
 * fixed set of tab stops, say every n columns.  Should n be a variable
 * or a symbolic parameter?
 */
    
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TABSTOP 4 /* tabstop every n columns */

int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%s", line);
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == '\t') {
            while (i % TABSTOP != 3) {
                s[i] = ' ';
                i++;
            }
            s[i] = ' ';

        } else {
            s[i] = c;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
