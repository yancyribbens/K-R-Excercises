/* Exercise 1-14
 *
 * Write a program to print a histogram of the frequencies of
 * different characters it its input.
 */

#include <stdio.h>

main()
{
    int c, i, j, word_len;

    // Histogram of ascii chars up to 127.
    int histogram[127];

    word_len = i = 0;
    for (i = 0; i < 127; i++) {
        histogram[i] = 0;
    }

    while ((c = getchar()) != EOF){
        histogram[c] = histogram[c] + 1;
    }

    for(i = 0; i < 127; ++i) {
        if (histogram[i] != 0) {
            printf("%d: ", i);
            for (j = 0; j < histogram[i]; j++) {
                printf("|");
            }
            printf("\n");
        }
    }
}
