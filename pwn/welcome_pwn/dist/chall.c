#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 0x20

void win() {
    execve("/bin/sh", NULL, NULL);
}

void init() {
    alarm(60);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

unsigned readn(char *buf, unsigned size) {
    unsigned i;
    for (i = 0; i < size - 1; i++) {
        unsigned x = read(0, buf + i, 1);
        if (x != 1 || buf[i] == '\n') break;
    }
    buf[i] = '\x00';
    return i;
}

int main(void) {
    init();

    char buf[BUFSIZE] = {};
    unsigned size;
    printf("how long is your name? > ");
    scanf("%u", &size);
    if (size + 8 > BUFSIZE) {
        puts("too long. sorry");
        return 0;
    }
    printf("what's your name? > ");
    size = readn(buf, size);
    strcpy(buf + size, "-san :)");
    puts(buf);

    return 0;
}
