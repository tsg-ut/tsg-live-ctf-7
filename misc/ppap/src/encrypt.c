#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

/* apt install libzip-dev */
#include <zip.h>

int main(int argc, char *argv[]) {
  const char *flag;
  const char *characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  char password[16] = {};
  zip_t *za;
  zip_source_t *s;
  int errorp;

  if (argc < 2) {
    fprintf(stderr, "usage: %s <flag>\n", argv[0]);
    return 1;
  }
  flag = argv[1];

  if ((za = zip_open("flag.zip", ZIP_CREATE, &errorp)) == NULL) {
    fprintf(stderr, "can't open zip: %d\n", errorp);
    return 1;
  }

  srand(time(NULL));
  for (size_t i = 0; i < 15; i++) {
    password[i] = characters[rand() % strlen(characters)];
  }
  password[15] = '\0';

  s = zip_source_buffer(za, flag, strlen(flag), 0);
  zip_file_add(za, "flag.txt", s, ZIP_FL_ENC_UTF_8);

  if (zip_file_set_encryption(za, 0, ZIP_EM_AES_256, password) < 0) {
    fputs(zip_strerror(za), stderr);
    return 1;
  }

  if (zip_set_default_password(za, password) < 0) {
    fputs(zip_strerror(za), stderr);
    return 1;
  }

  if (zip_close(za) < 0) {
    fputs(zip_strerror(za), stderr);
    return 1;
  }

  return 0;
}
