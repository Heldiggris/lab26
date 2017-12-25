#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

int main(void)
{
    Deque *d = deque_create();
    char str[24];
    printf("Введите h для получения справки.\n");
    while (scanf("%23s", str) == 1) {
        if (!strcmp(str, "psF") || !strcmp(str, "pushFront")) {
            Item a;
            scanf("%lf", &a);
            deque_pushFront(d, a);
        } else if (!strcmp(str, "psB") || !strcmp(str, "pushBack")) {
            Item a;
            scanf("%lf", &a);
            deque_pushBack(d, a);
        } if (!strcmp(str, "pF") || !strcmp(str, "popFront")) {
            if (!deque_empty(d)) {
                printf("%lf\n", deque_popFront(d));
            } else {
                printf("Дек пустой\n");
            }
        } if (!strcmp(str, "pB") || !strcmp(str, "popBack")) {
            if (!deque_empty(d)) {
                printf("%lf\n", deque_popBack(d));
            } else {
                printf("Дек пустой\n");
            }
        } else if (!strcmp(str, "p") || !strcmp(str, "print")) {
            for (int i = 0; i < deque_size(d); ++i) {
                Item a = deque_popFront(d);
                printf("%lf ", a);
                deque_pushBack(d, a);
            }
            printf("\n");
        } else if (!strcmp(str, "h") || !strcmp(str, "help")) {
            printf("\t'psF' или 'pushFront' - добавить в начало\n");
            printf("\t'psB' или 'pushBack'  - добавить в конец\n");
            printf("\t'pB'  или 'popFront'  - взять с начала\n");
            printf("\t'pB'  или 'popBack'   - взять с конца\n");
            printf("\t'p'   или 'print'     - просмотреть дек\n");
            printf("\t'st'  или 'sort'      - сортировать дек\n");
            printf("\t's'   или 'size'      - размер дека\n");
            printf("\t'q'   или 'quit'      - выйти\n");
        } else if (!strcmp(str, "st") || !strcmp(str, "sort")) {
            deque_sort(d);
        } else if (!strcmp(str, "q") || !strcmp(str, "quit")) {
            break;
        } else  if (!strcmp(str, "s") || !strcmp(str, "size")) {
            printf("%lu\n", deque_size(d));
        }
    }
    deque_destroy(d);
    return 0;
}