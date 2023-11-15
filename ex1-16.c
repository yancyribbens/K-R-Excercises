/* Excercise 1-16
 *
 * Revise the main routine of the longest-line program so
 * it will correctly print the length of arbitrary long
 * input lines, and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/*print the longest line */
main()
{
    int len;            /* current line length */
    int total_len;      /* the total length when line spans multiple reads */
    int copied_size;    /* the size of the line copied */
    int max;            /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    total_len = 0;
    copied_size = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        total_len += len;
        if (total_len > max) {
            max = total_len;
            if (len > copied_size) {
                copy(longest, line);
                copied_size = len;
            }
        }

        if (line[len - 1] == '\n') {
            total_len = 0;
        }
    }

    if (max > 0) /* there was a line */
        printf("%d: %s", max, longest);

    return 0;
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
