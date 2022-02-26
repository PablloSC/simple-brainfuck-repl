/*
 * info:
 * en.wikipedia.org/wiki/Brainfuck
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PROGRAM_SIZE 4096

unsigned short cell_index = 0;
unsigned char tape[PROGRAM_SIZE], input[PROGRAM_SIZE];

int main(void){
  unsigned short loop_counter = 0, program_couter = 0;

  while (true){
    printf("\nbranfuck[%u]: ", loop_counter);
    program_couter = 0;
    scanf("%s", input);
    // brackets_stack(input);

    for(int i = 0; i < strlen(input); i++){
      switch (input[program_couter]) {
        case '+': tape[cell_index] += 1;     break;
        case '-': tape[cell_index] -= 1;     break;
        case '>': cell_index++;              break;
        case '<': cell_index--;              break;
        case '.': printf("%c", tape[cell_index]); break;
        case ',': scanf("%c", tape[cell_index]); break;
        case '[': break;
        case ']': break;
      }
      ++program_couter;
      //printf("\ntape index: %d | tape char: %c | program_couter: %d\n", tape[cell_index], tape[cell_index], program_couter);
    }
    ++loop_counter;
  }
  return EXIT_SUCCESS;
}
