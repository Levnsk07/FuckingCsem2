#include <stdio.h>

int main() {
#if defined(_MSC_VER)
    printf("Compiler: MSVC\n");
#elif defined(__GNUC__)
#if defined(__clang__)
    printf("Compiler: clang\n");
#else
    printf("Compiler: GCC\n");
#endif
#elif defined(__TINYC__)
    printf("Compiler: TCC\n");
#else
    printf("Compiler: unknown\n");
#endif

#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__) || defined(__aarch64__)
    printf("Bitness: 64\n");
#else
    printf("Bitness: 32\n");
#endif

#ifdef NDEBUG
    printf("Asserts: disabled\n");
#else
    printf("Asserts: enabled\n");
#endif

    return 0;
}
