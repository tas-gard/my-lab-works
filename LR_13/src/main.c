#include "set.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    set vowels = Set_create_fromString("aeyuio");
    int c;
    size_t count = 0;

    while ((c = getchar()) != EOF) {
        if (isSpace(c))
            continue;
        set word = Set_create();
        word = Set_add(word, c);
        bool fits = false;

        while (!isSpace(c = getchar())) {
            if (!Set_in(vowels, c))
                continue;
            
            if (!Set_in(word, c))
                word = Set_add(word, c);
            else 
                fits = true;
        }

        if (fits)
            ++count;
    }

    printf("fits word = %zu\n", count);

    return 0;
}