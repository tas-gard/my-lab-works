#include "computer.h"
#include <stdio.h>

void Computer_write(Computer *computer, FILE * file) {
    if(fwrite(computer, sizeof(Computer), 1, file) != 1)
    perror("can`t write to file!");
}

bool Computer_read(Computer *computer, FILE * file) {
    if(fread(computer, sizeof(Computer), 1, file) == 1)
        return true;
    return false;
}

void Computer_print(Computer *c) {
    // printf("%s | cpuCount=%zu | cpuType=%s | ram=%zuGB | video=%s | videoMem=%zuGB | disk=%s | diskCount=%zu | diskMem=%zuGB | integrated=%zu | os=%s\n",
    printf("%s %zu %s %zu %s %zu %s %zu %zu %zu %s\n",
           c->lastName,
           c->cpuCount,
           c->cpuType,
           c->ramGB,
           c->videoControllerType,
           c->videoMemoryGB,
           c->diskType,
           c->diskCount,
           c->diskMemoryGB,
           c->integratedControllersCount,
           c->os);
}

// вывести типичные конфигурации, я так понимаю нужно сравнить все кроме имени (придется открыть два раза и каждого с каждым), если совпадают более чем у р студентов, вывести эту конфигу   как будто будет минимум совпадений при таком сравнении