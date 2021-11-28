#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NMEM 0x10000
#define NCODE 0x1000

void (* *inst_handlers)(int *, int*);

char *mem;
char *code;
int *table;
int len = 0;

void win() {
    execve("/bin/sh", NULL, NULL);
}

void handle_start_loop(int *ip, int *head) {
    if (mem[*head] == 0) *ip = table[*ip] + 1;
    else *ip += 1;
}
void handle_end_loop(int *ip, int *head) {
    if (mem[*head] != 0) *ip = table[*ip] + 1;
    else *ip += 1;
}
void handle_inc_mem(int *ip, int *head) {
    mem[*head]++;
    *ip += 1;
}
void handle_dec_mem(int *ip, int *head) {
    mem[*head]--;
    *ip += 1;
}
void handle_inc_ptr(int *ip, int *head) {
    *head+=1;
    *ip += 1;
}
void handle_dec_ptr(int *ip, int *head) {
    *head-=1;
    *ip += 1;
}
void handle_write(int *ip, int *head) {
    write(1, mem + *head, 1);
    *ip += 1;
}
void handle_read(int *ip, int *head) {
    read(0, mem + *head, 1);
    *ip += 1;
}

void init_table() {
    inst_handlers['['] = handle_start_loop;
    inst_handlers[']'] = handle_end_loop;
    inst_handlers['+'] = handle_inc_mem;
    inst_handlers['-'] = handle_dec_mem;
    inst_handlers['>'] = handle_inc_ptr;
    inst_handlers['<'] = handle_dec_ptr;
    inst_handlers['.'] = handle_write;
    inst_handlers[','] = handle_read;
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


int parse_idx = 0;
int parse(int pos) {
    while (parse_idx < len) {
        int cur = parse_idx++;
        switch(code[cur]) {
            case '[': {
                int p = parse(cur);
                if (p < 0) return -1;
                table[cur] = p;
                break;
            }
            case ']': {
                if (pos < 0) return -1;
                table[cur] = pos;
                return cur;
            }
            case '>':
            case '<':
            case '+':
            case '-':
            case '.':
            case ',':
                break;
            default:
                return -1;
        }
    }
    if (pos == -1) {
        return 0;
    }
    return -1;
}


void interp() {
    int ip = 0;
    int head = 0;
    while (ip < len) {
        inst_handlers[code[ip]](&ip, &head);
    }
}

int main(void) {
    inst_handlers = calloc(sizeof(void*), 256);
    mem = calloc(sizeof(char), NMEM);
    code = calloc(sizeof(char), NCODE);
    table = calloc(sizeof(int), NCODE);

    len = readn(code, NCODE);
    int r = parse(-1);
    if (r < 0) {
        puts("parse failed");
        exit(1);
    }
    init_table();
    interp();
    return 0;
}
