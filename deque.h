#ifndef _DEQUE_H_
#define _DEQUE_H_

typedef struct _deque Deque;
typedef struct _deque_node Deque_node;
typedef int Item;

bool deque_empty(Deque *d);
Deque *deque_create();
void deque_pushBack(Deque *d, Item value);
void deque_pushFront(Deque *d, Item value);
Item deque_popBack(Deque *d);
Item deque_popFront(Deque *d);
void deque_destroy(Deque *d);

#endif