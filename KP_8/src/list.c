#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListItem {
    double data;
    struct ListItem *next;
};

struct List {
    ListItem *head;
    ListItem *tail;   // указатель на последний реальный узел
    size_t size;
};

List* List_create() {
    List *l = (List*)malloc(sizeof(List));
    l->head = (ListItem*)malloc(sizeof(ListItem));
    l->head->next = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void List_destroy(List *l) {
    ListItem *cur = l->head;
    while (cur != NULL) {
        ListItem *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(l);
}

size_t List_size(const List *l) {
    return l->size;
}

bool List_empty(const List *l) {
    return l->size == 0;
}

ListIterator List_begin(List *l) {
    return (ListIterator){l->head->next, l->head};
}

ListIterator List_end(List *l) {
    return (ListIterator){NULL, l->tail ? l->tail : l->head};
}

ListIterator ListIterator_next(ListIterator it) {
    if (it.current != NULL) {
        return (ListIterator){it.current->next, it.current};
    }
    return it;
}

bool ListIterator_equal(ListIterator lhs, ListIterator rhs) {
    return lhs.current == rhs.current;
}

double ListIterator_get(ListIterator it) {
    return it.current->data;
}

void ListIterator_set(ListIterator it, double value) {
    it.current->data = value;
}

ListIterator getIteratorAt(List *l, size_t pos) {
    ListIterator it = List_begin(l);
    size_t i = 0;
    while (i < pos && !ListIterator_equal(it, List_end(l))) {
        ++i;
        it = ListIterator_next(it);
    }
    return it;
}

ListIterator List_insert(List *l, ListIterator it, double data) {
    ListItem *newItem = (ListItem*)malloc(sizeof(ListItem));
    newItem->data = data;

    if (it.current == NULL) {
        if (l->tail == NULL) {
            l->head->next = newItem;
            newItem->next = NULL;
            l->tail = newItem;
            l->size++;
            return (ListIterator){newItem, l->head};
        } else {
            l->tail->next = newItem;
            newItem->next = NULL;
            ListItem *oldTail = l->tail;
            l->tail = newItem;
            l->size++;
            return (ListIterator){newItem, oldTail};
        }
    } else {
        ListItem *prev = it.prev;
        newItem->next = it.current;
        if (prev == NULL) 
            l->head->next = newItem;
        else
            prev->next = newItem;
        l->size++;
        return (ListIterator){newItem, prev};
    }
}

ListIterator List_remove(List *l, ListIterator it) {
    if (it.current == NULL) 
        return List_end(l);

    ListItem *prev = it.prev;
    ListItem *nextNode = it.current->next;

    if (prev == NULL) 
        l->head->next = nextNode;
    else 
        prev->next = nextNode;

    if (it.current == l->tail) 
        l->tail = (prev == l->head) ? NULL : prev;
    
    free(it.current);
    l->size--;

    return (ListIterator){nextNode, (nextNode == NULL) ? l->tail : prev};
}

void List_print(List *l) {
    printf("[");
    ListIterator it = List_begin(l);
    bool first = true;
    while (!ListIterator_equal(it, List_end(l))) {
        double x = ListIterator_get(it);
        if (!first) printf(", ");
        printf("%lf", x);
        first = false;
        it = ListIterator_next(it);
    }
    printf("]\n");
}

void List_isolate_value(List *l, double targetValue) {
    ListIterator it = List_begin(l);
    ListIterator end = List_end(l);
    int found = 0;
    while (!ListIterator_equal(it, end)) {
        if (fabs(ListIterator_get(it) - targetValue) < 1e-9) {
            found = 1;
            break;
        }
        it = ListIterator_next(it);
    }

    if (!found) {
        printf("Not found meaning\n");
        return;
    }

    it = List_begin(l);
    while (!ListIterator_equal(it, end)) {
        if (fabs(ListIterator_get(it) - targetValue) > 1e-9)
            it = List_remove(l, it);
        else
            it = ListIterator_next(it);
    }
    printf("Success\n");
}