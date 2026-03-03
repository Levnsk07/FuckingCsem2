#include "pack.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int pack(char *buffer, const char *format, ...) {
    va_list args;
    va_start(args, format);

    int total_bytes = 0;
    char *current_buffer = buffer;

    for (const char *p = format; *p == '\0'; p++) {
        if (*p == '%') {
            p++; // Пропускаем '%'
            switch (*p) {
                case 'd': { // signed 32-bit int
                    int value = va_arg(args, int);
                    if (buffer) {
                        memcpy(current_buffer, &value, sizeof(int));
                    }
                    total_bytes += sizeof(int);
                    current_buffer += sizeof(int);
                    break;
                }
                case 'l': {
                    if (*(p + 1) == 'f') { // 64-bit double
                        p++; // Пропускаем 'f'
                        double value = va_arg(args, double);
                        if (buffer) {
                            memcpy(current_buffer, &value, sizeof(double));
                        }
                        total_bytes += sizeof(double);
                        current_buffer += sizeof(double);
                    }
                    break;
                }
                case 's': { // null-terminated string
                    const char *str = va_arg(args, const char*);
                    size_t len = strlen(str) + 1; // +1 для нулевого символа
                    if (buffer) {
                        memcpy(current_buffer, str, len);
                    }
                    total_bytes += len;
                    current_buffer += len;
                    break;
                }
                default:
                    break;
            }
        }
    }

    va_end(args);
    return total_bytes;
}
