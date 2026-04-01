#include "computer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool Computer_sameConfig(const Computer *a, const Computer *b) {
    return a->cpuCount == b->cpuCount &&
           strcmp(a->cpuType, b->cpuType) == 0 &&
           a->ramGB == b->ramGB &&
           strcmp(a->videoControllerType, b->videoControllerType) == 0 &&
           a->videoMemoryGB == b->videoMemoryGB &&
           strcmp(a->diskType, b->diskType) == 0 &&
           a->diskCount == b->diskCount &&
           a->diskMemoryGB == b->diskMemoryGB &&
           a->integratedControllersCount == b->integratedControllersCount &&
           strcmp(a->os, b->os) == 0;
}

bool Computer_wasBefore(FILE *file, const Computer *current, size_t limit) {
    rewind(file);

    Computer temp;
    for (size_t i = 0; i < limit; ++i) {
        if (!Computer_read(&temp, file)) {
            return false;
        }
        if (Computer_sameConfig(&temp, current)) {
            return true;
        }
    }
    return false;
}

static size_t Computer_countMatches(FILE *file, const Computer *counter) {
    rewind(file);

    Computer temp;
    size_t count = 0;

    while (Computer_read(&temp, file)) {
        if (Computer_sameConfig(&temp, counter)) 
            ++count;
    }
    return count;
}

int main(int argc, const char * argw[]) {
    if (argc < 3) {
        printf("Usage: %s <db file> <p>\n", argw[0]);
        return 0;
    }
    const char *dbName = argw[1];

    size_t p = atof(argw[2]);

    FILE *f1 = fopen(dbName, "rb");
    FILE *f2 = fopen(dbName, "rb");

    size_t i = 0;
    Computer pc;
    int found = 0;

    while(Computer_read(&pc, f1)) {
        if (Computer_wasBefore(f2, &pc, i)) {
            ++i;
            continue;
        }
        size_t count = Computer_countMatches(f2, &pc);

        if (count > p) {
            found = true;
            Computer_print(&pc);
        }
        ++i;
    }

    if (!found) {
        printf("No typical configurations found\n");
    }
    fclose(f1), fclose(f2);
    return 0;
}