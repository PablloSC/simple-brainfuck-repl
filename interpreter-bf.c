#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ascci_table(char *ascci_s);

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
      puts    ("+------------------------------+");
      printf  ("| char | decimal | hexadecimal |\n");
      puts    ("+------------------------------+");
      for (int i = 0; i < strlen(ascci_s); i++)
        printf("| %c    | %-7d | %-11x |\n",
              ascci_s[i], ascci_s[i], ascci_s[i]);
      puts    ("+------------------------------+");
}
