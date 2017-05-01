#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

typedef struct _deque_node{
    struct dq_node *prev;
    struct dq_node *next;
    int value;
};

typedef struct _deque{
    Deque_node *first;
    Deque_node *last;
    int size;
};


Deque_node *deque_node_create(void)
{
    Deque_node *dq = (Deque_node *)malloc(sizeof(Deque_node));
    dq->next = NULL;
    dq->prev = NULL;
    return dq;
}

Deque *deque_create(void)
{
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->first = NULL;
    dq->last = NULL;
    dq->size = 0;
    return dq;
}

void deque_pushBack(Deque *d, Item value)
{
    Deque_node *dq = deque_node_create();
    dq->value = value;
    if (d->last) {
        d->last->next = dq;
        dq->prev = d->last;
        d->last = dq;
        d->size += 1;
    } else {
        d->last = dq;
        d->first = dq;
        d->size += 1;
    }
}

Item deque_popBack(Deque *d)
{
    Item a;
    if(d->last) {
        a = d->last->value;
        Deque_node *dq = d->last->prev;
        free(d->last);
        d->last = dq;
        if (d->size == 1) {
            d->first = NULL;
        }
        if (dq) {
            dq->next = NULL;
        }
        d->size -= 1;
        return a;
    } else {
        printf("Вышли за пределы\n");
        return;
    }
}

Item deque_popFront(Deque *d)
{
    Item a;
    if(d->first) {
        a = d->first->value;
        Deque_node *dq = d->first->next;
        free(d->first);
        d->first = dq;
        if (d->size == 1) {
            d->last = NULL;
        }
        if (dq) {
            dq->prev = NULL;
        }
        d->size -= 1;
        return a;
    } else {
        printf("Вышли за пределы\n");
        return;
    }
}

void deque_pushFront(Deque *d, Item value)
{
    Deque_node *dq = deque_node_create();
    dq->value = value;
    if (d->first != NULL) {
        d->first->prev = dq;
        dq->next = d->first;
        d->first = dq;
        d->size += 1;
    } else {
        d->last = dq;
        d->first = dq;
        d->size += 1;
    }
}

bool deque_empty(Deque *d)
{
    return d->size == 0;
}

void deque_destroy(Deque *d)
{
    for(int i = 0; i < d->size; ++i) {
        deque_popFront(d);
    }
    free(d);
}

Item deque_size(Deque *d)
{
    return d->size;
}

void deque_sort(Deque *d)
{
    int min = deque_popFront(d);
    deque_pushFront(d, min);
    int size = deque_size(d);
    int a;
    int num = 0;

    for (int i = 0; i < size; ++i) {
        a = deque_popFront(d);
        deque_pushBack(d, a);
        if (a < min) {
            min = a;
        }
    }
    int min_prev = min - 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a = deque_popFront(d);
            if (a < min && a > min_prev) {
                min = a;
            }
            deque_pushBack(d, a);
        }
        num = 0;
        for (int j = 0; j < size; ++j) {
            a = deque_popFront(d);
            if (a == min) {
                num++; 
            } else {
                deque_pushBack(d, a);
            }
        }

        for(int k = 0; k < num; ++k) {
            deque_pushBack(d, min);
        }
        i += num - 1;
        min_prev = min;
        min = deque_popFront(d);
        deque_pushFront(d, min);
    }
}