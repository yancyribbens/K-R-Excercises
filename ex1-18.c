/* Excercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely the blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void sanatize(char line[], int len);

main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        sanatize(line, len);
        printf("%s", line);
    }

    return 0;
}

void sanatize(char line[], int len) {
    // len - 2:
    // * last char is the null terminator
    // * 2nd to last char is newline char
    while((line[len - 2] == ' ' || line[len - 2] == '\t') && len > 0) {
        --len;
    }
    line[len - 1] = '\n';
    line[len] = '\0';
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
