#ifndef COMPUTER_H_
#define COMPUTER_H_
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

typedef size_t timestamp;

typedef struct {
    char lastName[50];

    size_t cpuCount;
    char cpuType[50];

    size_t ramGB;

    char videoControllerType[20];
    size_t videoMemoryGB;

    char diskType[20];
    size_t diskCount;
    size_t diskMemoryGB;

    size_t integratedControllersCount;

    char os[20];
} Computer;

void Computer_write(Computer *computer, FILE * file);
bool Computer_read(Computer *computer, FILE * file);
void Computer_print(Computer *computer);

#endif // !COMPUTER_H_