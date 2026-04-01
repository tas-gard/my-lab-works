#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void print_menu() {
    printf("1. Print list\n");
    printf("2. Insert item\n");
    printf("3. Remove item\n");
    printf("4. Calc lenth\n");
    printf("5. Isolated element\n");
}

int main() {
    List *myList = List_create();
    int choice;
    double value;
    print_menu();
    while (scanf("%d", &choice) != EOF) {
        switch (choice) {
            case 1: //печать
                List_print(myList);
                break;

            case 2: { // вставка
                size_t pos;
                double x;
                printf("Введите позицию вставки: ");
                scanf("%zu", &pos);
                if (pos > List_size(myList)) {
                    printf("Wrong position\n");
                    break;
                }
                printf("Введите элемент: ");
                scanf("%lf", &x);
                ListIterator it = getIteratorAt(myList, pos);
                List_insert(myList, it, x);
                printf("Inserted\n");
                break;
            }

            case 3: { // удаление
                if (List_empty(myList)) {
                    printf("List is empty\n");
                    break;
                }
                size_t pos;
                printf("Введите позицию для удаления: ");
                scanf("%zu", &pos);
                if (pos >= List_size(myList)) {
                    printf("Wrong position\n");
                    break;
                }
                ListIterator it = getIteratorAt(myList, pos);
                List_remove(myList, it);
                printf("Removed\n");
                break;
            }

            case 4: // длина
                printf("Lenth = %zu\n", List_size(myList));
                break;

            case 5: // нестандартное действие
                printf("Введите заданное значение: ");
                scanf("%lf", &value);
                List_isolate_value(myList, value);
                break;

            default:
                printf("Unknown command\n");
        }
    }
    List_destroy(myList);
    return 0;
}