#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void ascci_table(char *ascci_s);
char *chartobin (unsigned char c);

int main(int argc, char **argv){
  puts("******");
  printf("argc: %d | ", argc);

  for (int i = 0; i < argc; i++)
    printf("argv: %s\n", argv[i]);
  puts("------");

  char *ascci_s = "abcdefgh";
  ascci_table(ascci_s);

  return EXIT_SUCCESS;
}

void ascci_table(char *ascci_s){
  printf("mensagem: %s\n", ascci_s);
  puts    ("+-------------------------------------------------+");
  printf  ("| char |  binary  | octal | decimal | hexadecimal |\n");
  puts    ("+-------------------------------------------------+");
  for (int i = 0; i < strlen(ascci_s); i++) {
    printf("| %-4c | %s | %-5o | %-7d | %-11x |\n",
        ascci_s[i], chartobin(ascci_s[i]), ascci_s[i], ascci_s[i], ascci_s[i]);
  }
  puts    ("+-------------------------------------------------+");
}

/* thanks Prelude
 * cboard.cprogramming.com/c-programming/42817-convert-char-binary.html
 */
char *chartobin (unsigned char c){
  static char bin[CHAR_BIT + 1] = {0};
  int i;

  for (i = CHAR_BIT - 1; i >= 0; i--) {
    bin[i] = (c % 2) + '0';
    c /= 2;
  }

  return bin;
}
