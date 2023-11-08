/* Exercise 1-6
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>

main()
{
    int c;

    while((c = getchar()) != EOF) {
        c = getchar();
        printf("%d", c);
    }

    // pressing ctrl-D sends the EOF char.  Since the loop breaks, 
    // when sending ctrl-D, and otherwise prints c, we can conclude 
    // that the expression getchar() != EOF results in true of false, 
    // 0 or 1.
    printf("%d", c);
}
