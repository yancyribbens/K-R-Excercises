/* Exercise 1-13
 *
 * Write a program to print a histogram of the lengths of words
 * in its input.  It is easy to draw the histogram with bars
 * horizontal; a vertical orientation is more challenging.
 */

#include <stdio.h>

main()
{
    int c, i, j, word_len;
    int histogram[45];

    word_len = i = 0;
    for (i = 0; i < 45; i++) {
        histogram[i] = 0;
    }

    while ((c = getchar()) != EOF){
        if (c == '\n' || c == ' ' || c == '\t') {
            histogram[word_len] = histogram[word_len] + 1;
            word_len = 0;
        } else {
            ++word_len;
        }
    }

    for(i = 0; i < 45; ++i) {
        if (histogram[i] != 0) {
            printf("%d: ", i);
            for (j = 0; j < histogram[i]; j++) {
                printf("|");
            }
            printf("\n");
        }
    }
}
