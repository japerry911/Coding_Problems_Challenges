#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
---New Cashier---
Some new cashiers started to work at your restaurant.

They are good at taking orders, but they don't know how to capitalize words, or use a space bar!

All the orders they create look something like this:

"milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"

The kitchen staff are threatening to quit, because of how difficult it is to read the orders.

Their preference is to get the orders as a nice clean string with spaces and capitals like so:

"Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"

The kitchen staff expect the items to be in the same order as they appear in the menu.

The menu items are fairly simple, there is no overlap in the names of the items:

1. Burger
2. Fries
3. Chicken
4. Pizza
5. Sandwich
6. Onionrings
7. Milkshake
8. Coke
 */

char *get_order(const char *input);
int parseItem(char *str, const char *sub);
void record_item(char *str, const char *item, int *current_index);

int main() {
    char *input1 = "milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza";
    char *input2 = "pizzachickenfriesburgercokemilkshakefriessandwich";

    char *output1 = get_order(input1);
    char *output2 = get_order(input2);

    char *expected_output1 = "Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke";
    char *expected_output2 = "Burger Fries Fries Chicken Pizza Sandwich Milkshake Coke";

    if (strcmp(output1, expected_output1) != 0) {
        printf("Test 1 Failed -> Output: %s || Expected_Output: %s\n", output1, expected_output1);
    } else {
        printf("Test 1 Passed.\n");
    }

    if (strcmp(output2, expected_output2) != 0) {
        printf("Test 2 Failed -> Output: %s || Expected_Output: %s\n", output2, expected_output2);
    } else {
        printf("Test 2 Passed.\n");
    }

    return 0;
}

char *get_order(const char *input) {
    char *parsed_orders = (char *)malloc(sizeof(char) * (strlen(input) + 100));
    char *input_copy = (char *)malloc(sizeof(char) * strlen(input));
    char menu_item_order[8][10] = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};
    size_t menu_item_order_index_counter = 0;
    int parsed_index_counter = 0;

    strcpy(input_copy, input);

    while (menu_item_order_index_counter < 8) {
        char *lookup_menu_item = menu_item_order[menu_item_order_index_counter];
        lookup_menu_item[0] = tolower(lookup_menu_item[0]);

        int quantity = parseItem(input_copy, lookup_menu_item);
        printf("%d - %s\n", quantity, lookup_menu_item);
        for (size_t i = 0; i < quantity; ++i) {
            record_item(parsed_orders, lookup_menu_item, &parsed_index_counter);
        }

        ++menu_item_order_index_counter;
    }

    parsed_orders[strlen(parsed_orders) - 1] = '\0';

    free(input_copy);

    return parsed_orders;
}

int parseItem(char *str, const char *sub) {
    int times_found = 0;
    size_t len = strlen(sub);

    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            ++times_found;
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }

    return times_found;
}

void record_item(char *str, const char *item, int *current_index) {
    size_t item_index = 0;

    for (int i = *current_index; i < strlen(item) + *current_index; ++i) {
        if (i == *current_index) {
            str[i] = toupper(item[item_index]);
        } else {
            str[i] = item[item_index];
        }

        ++item_index;
    }

    str[strlen(item) + *current_index] = ' ';
    *current_index = strlen(item) + *current_index + 1;
}