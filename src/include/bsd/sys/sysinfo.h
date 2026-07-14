#pragma once

#include <errno.h>
#include <stdint.h>

#define SI_LOAD_SHIFT 16

struct sysinfo {
        long loads[3];
        unsigned long totalram;
        unsigned long freeram;
        unsigned long sharedram;
        unsigned long bufferram;
        unsigned long totalswap;
        unsigned long freeswap;
        uint16_t procs;
        unsigned long totalhigh;
        unsigned long freehigh;
        unsigned int mem_unit;
        char _f[20-2*sizeof(long)-sizeof(int)];
};

static inline int sysinfo(struct sysinfo *info) {
        (void)info;
        errno = ENOSYS;
        return -1;
}
