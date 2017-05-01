#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

int main(void)
{
    Deque *d = deque_create();
    while (1) {
        char str[24];
        scanf("%23s", &str);
        if (!strcmp(str, "pushFront")) {
            int a;
            scanf("%d", &a);
            deque_pushFront(d, a);
        } else if (!strcmp(str, "pushBack")) {
            int a;
            scanf("%d", &a);
            deque_pushBack(d, a);
        } if (!strcmp(str, "popFront")) {
            printf("%d\n", deque_popFront(d));
        } if (!strcmp(str, "popBack")) {
            printf("%d\n", deque_popBack(d));
        } else if (!strcmp(str, "print")) {
            for (int i = 0; i < deque_size(d); ++i) {
                int a = deque_popFront(d);
                printf("%d ", a);
                deque_pushBack(d, a);
            }
            printf("\n");
        } else if (!strcmp(str, "help")) {
            printf("\tpushFront - добавить в начало\n");
            printf("\tpushBack - добавить в конец\n");
            printf("\tpopFront - взять с начала\n");
            printf("\tpopBack - взять с конца\n");
            printf("\tprint - просмотреть дек\n");
            printf("\tsort - сортировать дек\n");
            printf("\tsize - размер дека\n");
            printf("\texit - выйти\n");
        } else if (!strcmp(str, "sort")) {
            deque_sort(d);
        } else if (!strcmp(str, "exit")) {
            deque_destroy(d);
            return 0;
        } else  if (!strcmp(str, "size")) {
            printf("%d\n", deque_size(d));
        }
    }
    return 0;
}