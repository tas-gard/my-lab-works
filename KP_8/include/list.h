#ifndef LIST_DOUBLE_H
#define LIST_DOUBLE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ListItem ListItem;
typedef struct List List;

typedef struct {
    ListItem *current;
    ListItem *prev;
} ListIterator;

List* List_create();
void List_destroy(List *l);

size_t List_size(const List *l);
bool List_empty(const List *l);
void List_print(List *l);

ListIterator List_begin(List *l);
ListIterator List_end(List *l);
ListIterator ListIterator_next(ListIterator it);
bool ListIterator_equal(ListIterator lhs, ListIterator rhs);

double ListIterator_get(ListIterator it);
void ListIterator_set(ListIterator it, double value);
ListIterator getIteratorAt(List *l, size_t pos);

ListIterator List_insert(List *l, ListIterator it, double data);

ListIterator List_remove(List *l, ListIterator it);

void List_isolate_value(List *l, double targetValue);

#endif // !LIST_DOUBLE_H