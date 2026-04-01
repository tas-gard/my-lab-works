#include "computer.h"

int main(int argc, const char * argw[]) {
    if(argc < 2) {
        printf("Usage: %s <db file to write>\n", argw[0]);
        return 0;
    }
 
    FILE *file = fopen(argw[1], "ab");
    Computer c;

    while (scanf("%49s %zu %49s %zu %19s %zu %19s %zu %zu %zu %19s",
        c.lastName, 
        &c.cpuCount, 
        c.cpuType,
        &c.ramGB, 
        c.videoControllerType, 
        &c.videoMemoryGB,
        c.diskType,
        &c.diskCount,
        &c.diskMemoryGB,
        &c.integratedControllersCount,
        c.os)  != EOF) {
            Computer_write(&c, file);
    }
    fclose(file);
    return 0;
}