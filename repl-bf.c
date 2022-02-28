/*
 * version 1.0
 * no licence :)
 *
 * info:
 * en.wikipedia.org/wiki/Brainfuck
 * brainfuck.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_SIZE 4096

unsigned short cell = 0, loop_counter = 0, program_couter = 0;
unsigned char tape[PROGRAM_SIZE], input[PROGRAM_SIZE];
char loop = 1;

int main(void){

  while (loop){
    printf("\nbranfuck[%u]: ", loop_counter);
    memset(input, 0, sizeof(input)); /* reset input */
    fgets(input, PROGRAM_SIZE, stdin);

    for(int i = 0; i < PROGRAM_SIZE; i++){
      switch (input[program_couter]){
        case '+': tape[cell] += 1; break;
        case '-': tape[cell] -= 1; break;
        case '>': cell == PROGRAM_SIZE-1 ? cell = 0 : cell++; break;
        case '<': cell == 0 ? cell = PROGRAM_SIZE-1 : cell--; break;
        case '.': putc(tape[cell], stdout); break;
        case ',': tape[cell] = getc(stdin); break;
        case '[': {
                    int n = 1;
                    if(tape[cell] == 0)
                      for(++program_couter; n; ++program_couter){
                        if(input[program_couter] == '[') ++n;
                        if(input[program_couter] == ']') --n;
                    }
                    break;
                  }
        case ']': {
                    int n = 1;
                    if(tape[cell] != 0)
                      for(--program_couter; n; --program_couter){
                        if(input[program_couter] == ']') ++n;
                        if(input[program_couter] == '[') --n;
                    }
                    break;
                  }
      case 'q': loop = 0; break;
      }
      ++program_couter;
    }
    ++loop_counter;
  }
  return EXIT_SUCCESS;
}
