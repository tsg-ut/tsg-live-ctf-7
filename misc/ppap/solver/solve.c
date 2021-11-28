#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  const char *characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  char password[16] = {};

  printf("%ld\n", time(NULL));

  srand(1637532722);
  for (size_t i = 0; i < 15; i++) {
    password[i] = characters[rand() % strlen(characters)];
  }
  password[15] = '\0';

  puts(password);

  return 0;
}
