/* Excercise 1-19
 *
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

void reverse(char s[], int len);

main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (line[len - 1] == '\n') {
            reverse(line, len - 1);
            printf("%s", line);
        }
    }

    return 0;
}

void reverse(char s[], int len) {
    int i;
    int middle = len / 2;
    for (i=0; i < len / 2; ++i) {
        int j = len - i;
        char front = s[i];
        char back = s[j - 1];
        s[i] = back;
        s[j - 1] = front;
    } 
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
