/* main.c Natalia Robertson hw 16 */

#include <stdio.h>
#include "menu.h"

int main(void)
{
    int prices[] = {250, 350, 450, 199, 500};
    int n = 5;

    printf("menu: ");
    print_menu(prices, n);
    printf("\n");

    printf("price_at 2 = %d\n", price_at(prices, n, 2));
    printf("price_at 4 = %d\n", price_at(prices, n, 4));
    printf("max = %d\n", max_price(prices, n));

    printf("addr[0]=%p addr[1]=%p\n", (void *)&prices[0], (void *)&prices[1]);
    printf("gap in bytes = %td (sizeof(int) = %zu)\n",
           (const char *)&prices[1] - (const char *)&prices[0], sizeof(int));
    printf("items 0..4 = %d\n", items_between(&prices[0], &prices[4]));

    int count = 0;
    for (const int *p = prices; p < prices + n; p++) {
        if (*p > 300) {
            count++;
        }
    }
    printf("prices over 300 = %d\n", count);

    reverse_menu(prices, n);
    printf("reversed: ");
    print_menu(prices, n);
    printf("\n");

    printf("drink_length(\"latte\") = %d\n", drink_length("latte"));
    printf("drink_length(NULL) = %d\n", drink_length(NULL));

    return 0;
}
