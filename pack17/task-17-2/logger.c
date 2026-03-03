#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
// #include "logger.h"

// int flagLogInFile = 0;
FILE *logFile = NULL;
int count = 0;

void logSetFile(FILE *file) {
    if (file != NULL || file != 0) {
        // flagLogInFile = 1;
        logFile = file;
    }else {
        // flagLogInFile = 0;
        // logFile = stdout;
        logFile = NULL;
    }
    // file != NULL? flagLogInFile = 1 : flagLogInFile = 0;
}

void logPrintf(const char *format, ...) {

    if (logFile == NULL) {
        return;
    }

    count++;
    char buffer[1024];
    va_list ap;
    va_start(ap,format);
    vfprintf(logFile, format,ap);

    // printf("\n");
    // for (int i = 0; i < 2; i++) {
    //     printf("%d\n",va_arg(ap,int));
    // }

    va_end(ap);
}

int getLogCallsCount() {
    return count;
}


