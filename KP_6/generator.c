#include "computer.h"
#include <stdlib.h>
#include <string.h>

const char *cpuTypes[] = {
    "Intel_Core_i3",
    "Intel_Core_i5",
    "Intel_Core_i7",
    "Intel_Xeon",
    "AMD_Ryzen_5",
    "AMD_Ryzen_7",
    "AMD_Ryzen_9",
    "AMD_EPYC",
};

const char *videoControllerTypes[] = {
    "integrated",
    "discrete",
    "video_bus"
};

const char *diskTypes[] = {
    "SAS",
    "SATA"
};

const char *osTypes[] = {
    "Windows",
    "Linux",
    "macOS"
};

const size_t rams[] = {8, 16, 32, 64};

const size_t diskMemories[] = {128, 256, 512, 1024};
// без констант с такой проверкой получить совпадения можно только с огромных файлах


void Computer_generator(Computer *c) {
    c->lastName[0] = rand() % 26 + 'A';
    size_t nameLen = rand() % 10 + 7;
    for (size_t i = 1; i < nameLen; ++i)
        c->lastName[i] = rand() % 26 + 'a';
    c->lastName[nameLen] = 0;

    c->cpuCount = rand() % 2 + 1;
    strcpy(c->cpuType, cpuTypes[rand() % 10]);
    
    c->ramGB = rams[rand() % 4];
    strcpy(c->videoControllerType, videoControllerTypes[rand() % 3]);
    c->videoMemoryGB = rams[rand() % 4];

    strcpy(c->diskType, diskTypes[rand() % 2]);
    c->diskCount = rand() % 3 + 1;
    c->diskMemoryGB = diskMemories[rand() % 4];

    c->integratedControllersCount = rand() % 5 + 1;
    strcpy(c->os,osTypes[rand() % 3]);
}

int main(int argc, const char * argw[]) {
    if(argc < 2) {
        printf("Usage: %s <number of students to generate>\n", argw[0]);
        return 0;
    }
  
    int n = atoi(argw[1]);

    Computer pc;
    for (int i = 0; i < n; ++i) {
        Computer_generator(&pc);
        Computer_print(&pc);
    }
    return 0;
}