gcc -w ./test.c \
    ./zlib/*.c \
    ./zlib/minizip/ioapi.c \
    ./zlib/minizip/unzip.c \
    ./zlib/minizip/zip.c \
    -I./zlib \
    -I./zlib/minizip \
    -o ./test-out