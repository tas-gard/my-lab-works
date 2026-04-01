#include <stdbool.h>

typedef int set; 

set Set_create();
set Set_create_fromString(const char *);

set Set_add(set, char);
set Set_remove(set, char);

set Set_intersect(set, set);
set Set_union(set, set);
set Set_diff(set, set);

bool Set_in(set, char);
bool isSpace(int);