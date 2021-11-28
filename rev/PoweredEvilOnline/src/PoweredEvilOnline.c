#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ptrace.h>

#define __STDC_WANT_LIB_EXT1__ 1
#define FILENAME "power"

void _t() {
    asm("mov rax, 0x24; mov rbx, 0xa1; mov rcx, 0x72; mov rdx, 0x9a");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x26; mov rbx, 0x1d; mov rcx, 0x22; mov rdx, 0xa4");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x84; mov rbx, 0x2c; mov rcx, 0x52; mov rdx, 0xcd");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x25; mov rbx, 0x1a; mov rcx, 0x28; mov rdx, 0x97");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x84; mov rbx, 0xf1; mov rcx, 0x92; mov rdx, 0x74");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x93; mov rbx, 0x29; mov rcx, 0x62; mov rdx, 0x56");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xf4; mov rbx, 0x30; mov rcx, 0x59; mov rdx, 0x34");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x38; mov rbx, 0x45; mov rcx, 0x68; mov rdx, 0x64");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x28; mov rbx, 0x21; mov rcx, 0x2b; mov rdx, 0x84");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x13; mov rbx, 0x19; mov rcx, 0xcb; mov rdx, 0x14");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");

    asm("mov rax, 0x14; mov rbx, 0xa0; mov rcx, 0x82; mov rdx, 0x97");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x26; mov rbx, 0x1d; mov rcx, 0x12; mov rdx, 0x94");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xe4; mov rbx, 0x7c; mov rcx, 0x5a; mov rdx, 0x0d");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x25; mov rbx, 0x9a; mov rcx, 0x2e; mov rdx, 0x87");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xc4; mov rbx, 0xf1; mov rcx, 0xc2; mov rdx, 0x76");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x83; mov rbx, 0x2f; mov rcx, 0xa2; mov rdx, 0x52");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x04; mov rbx, 0x3e; mov rcx, 0x99; mov rdx, 0x14");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x68; mov rbx, 0xc5; mov rcx, 0x78; mov rdx, 0x34");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x18; mov rbx, 0x91; mov rcx, 0x2b; mov rdx, 0x74");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x73; mov rbx, 0xf9; mov rcx, 0xc7; mov rdx, 0x12");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");

    asm("mov rax, 0x24; mov rbx, 0xa1; mov rcx, 0x72; mov rdx, 0x90");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x86; mov rbx, 0xdd; mov rcx, 0x26; mov rdx, 0xa4");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x8c; mov rbx, 0x2c; mov rcx, 0x52; mov rdx, 0xcd");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x2a; mov rbx, 0xca; mov rcx, 0x28; mov rdx, 0xe7");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x84; mov rbx, 0xf1; mov rcx, 0x9c; mov rdx, 0x74");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xe3; mov rbx, 0x59; mov rcx, 0x62; mov rdx, 0xd6");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xf4; mov rbx, 0x30; mov rcx, 0xe9; mov rdx, 0x34");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x39; mov rbx, 0x35; mov rcx, 0x68; mov rdx, 0xa4");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x28; mov rbx, 0x21; mov rcx, 0x6b; mov rdx, 0x84");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x13; mov rbx, 0x19; mov rcx, 0x9b; mov rdx, 0xc4");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");

    asm("mov rax, 0x24; mov rbx, 0xa1; mov rcx, 0x52; mov rdx, 0x6a");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x36; mov rbx, 0x17; mov rcx, 0xc2; mov rdx, 0x84");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xc4; mov rbx, 0x2c; mov rcx, 0xe2; mov rdx, 0xcd");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x2d; mov rbx, 0x8a; mov rcx, 0x2d; mov rdx, 0x07");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x84; mov rbx, 0xf1; mov rcx, 0x9c; mov rdx, 0x74");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0x9c; mov rbx, 0x2f; mov rcx, 0x62; mov rdx, 0xc6");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
    asm("mov rax, 0xf4; mov rbx, 0xff; mov rcx, 0x5e; mov rdx, 0x34");
    asm("xor rax, rbx; xor rax, rcx; xor rax, rdx; nop; nop; ret");
}

void _(){
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        printf("evil> It's so bright. Where's the shade.\n");
        sleep(2);
        printf("evil> But that weak light is not enough to hurt me.\n");
        exit(1);
    }
    return;
}

char __(char word1, int i) {
    char word2 = 0;
    char s[0x40];
    asm("push rcx");
    asm("push rbx");
    asm("lea r8, [0x40086b]"); // check this value
    asm("mov eax, dword[rbp - 0x6c]; mov rcx, 0x28"); // *1
    asm("mul rcx");
    asm("lea rdx, [r8 + rax]");
    asm("call rdx");
    asm("mov byte[rbp - 0x52], al"); //*2
    asm("pop rbx");
    asm("pop rcx");
    word1 = word1 ^ word2;
    return word1;

    // *1 と *2はなぜかコンパイルすると[rbp-*]の値が変わってしまうので、変わった後に正しく動くような値にしている。
    // ソースコードを出すとミスリードしてしまうかも。それに静的解析で突破されないように美しくないコードになっているのでソースコードは出さないかな。
}

char* ___(char power[], char true_word[]) {
    for(int i = 0; i < 37; i++) {
        true_word[i] = __(true_word[i], i);
        if(true_word[i] == power[i]) {
            continue;
        }
        else {
            printf("evil> Your power is just a sham\n");
            printf("      Die\n");
            sleep(2);
            printf("you>  Aaaaaaaaaaaaaaah!\n");
            sleep(5);
            printf("system> You LOSE...\n");
            exit(1);
        }
    }
    return true_word;
}

void ____() {
    FILE *r2, *gdb;
    char r2_cnt[8], gdb_cnt[8];
    r2 = popen("ls /usr/local/bin/* | grep radare2 -c", "r");
    fgets(r2_cnt, 8, r2);
    if (r2_cnt[0] != '0' || r2_cnt[1] != '\n') {
        printf("system> The use of weapons is forbidden.\n");
        printf("        Transfer to out side immediately.\n");
        exit(1);
    }
    gdb = popen("ls /usr/bin/* | grep gdb -c", "r");
    fgets(gdb_cnt, 8, gdb);
    if (gdb_cnt[0] != '0' || gdb_cnt[1] != '\n') {
        printf("system> The use of weapons is forbidden.\n");
        printf("        Transfer to out side immediately.\n");
        exit(1);
    }
    return;
}

int main()
{
    char power[37];
    char true_word[37] = "\x39\xee\x70\xc3\xc7\xc8\xd2\x3d\x97\xb2\xc9\x8a\xa1\x27\xef\x3b\xe8\xd2\xae\x2f\x57\xaa\x0c\x5c\xc2\x3d\x6f\xf3\x94\x2c\x8a\x0f\xf6\xe3\xfa\x6a\x61";
    int *p;
    p = 0x40116b; // check this value

    FILE *fd;
    ____();

    printf("evil> Not a ray of light reaches here.\n");
    printf("      What the hell can you do?\n");
    sleep(2);

    printf("you>  The true light is in my heart.\n");
    printf("      I shall reveal your sins.\n");
    sleep(2);

    _();
    if ((fd = fopen(FILENAME, "r")) == NULL) {
        fprintf(stderr, "evil> You have no \"%s\" here.\n", FILENAME);
        exit(1);
    }
    fgets(power, 37, fd);
    if (*p != 0xfffcc6e8) { // check this value
        printf("evil> Gah! My Right eye!\n");
        sleep(2);
        printf("evil> But that puny light is not enough to defeat me.\n");
        exit(1);
    } else {
        if(ptrace(PTRACE_TRACEME, 0, 1 ,0) != -1){
            printf("evil> Gah! My Left eye!\n");
            sleep(2);
            printf("      But that level of light is not enough to defeat me.\n");
            exit(1);
        } else {
            strncpy(true_word, ___(power, true_word), 37);
            printf("evil> GYAAAAAAAAAAAAAAAA!!!!!!\n");
            sleep(1);
            printf("evil> I DON'T WANNA DIEEEEEEEEE!!\n");
            sleep(1);
            printf("evil> I DON'T WANNA GO TO HELLLLLLLLLLL!!\n");
            sleep(1);
            printf("evil> GYAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!\n");
            sleep(5);
            printf("system> You WIN!\n");
            sleep(2);
            printf("you>  %s\n", true_word);
        }
    }
    fclose(fd);
    return 0;
}
