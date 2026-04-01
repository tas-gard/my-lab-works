#include "../include/set.h"


set Set_create() {
    return 0;
}

set Set_intersect(set s1, set s2) {
    return s1 & s2;
}

set Set_union(set s1, set s2) {
    return s1 | s2;
}

set Set_diff(set s1, set s2) {
    return s1 & (~s2);
}

set Set_create_fromString(const char *s) {  // const чтобы не изменять элементы строки
    set res = Set_create();
    const char *c = s;  // с - локальный указатель, чтобы не трогать s
    // с - указатель, а *с - элемент строки 
    while (*c != '\0') {  // пока не встретим конец строки
        res = Set_add(res, *c);  // добавляем элемент в множество
        ++c;
    }
    return res;
}

set Set_add(set s, char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z')
        return s; // ничего не делаем, если не лат. буква

    set cSet = 1 << (c - 'a');

    return s | cSet;
}

set Set_remove(set s, char c) {  // аналогично add
    c = tolower(c);
    if (c < 'a' || c > 'z') 
        return s;

    set cSet = 1 << (c - 'a');
    return s & (~cSet);
}


bool Set_in(set s, char c) { 
    c = tolower(c);
    set cSet = 1 << (c - 'a');

    return s & cSet;
}

bool isSpace(int c) {
    return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}