/*
 * info:
 * en.wikipedia.org/wiki/Brainfuck
 * brainfuck.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define PROGRAM_SIZE 4096

void print_tape(void);

unsigned short cell_index = 0;
unsigned char tape[PROGRAM_SIZE], input[PROGRAM_SIZE];

/* {{{ stack define */
//char *brackets_stack[256];
//int count_stack = 0;
//void push(char *input);
//void pop();
/* }}} stack define */

/* {{{ hash define */
//#define HASH_SIZE 256
//int brackets_hash[HASH_SIZE];
//
//typedef struct {
//  int open;
//  int close;
//} brackets;
//
//brackets *hash_table[HASH_SIZE];
//
//bool insert_hash(brackets *h){
//  if (h == NULL) return false;
//  int index = 
//}
//
//void print_hash(){
//  for(int i = 0; i < HASH_SIZE; i++){
//    if (hash_table[i] == NULL){
//      printf("\t%d\t---\n", i);
//    } else {
//      printf("\t%d\t%d\n", i, hash_table[i]->open);
//    }
//  }
//}
//
//void init_hash(){
//  for(int i = 0; i < HASH_SIZE; i++){
//    hash_table[i] = NULL;
//  }
//}
//
//unsigned int hash(int open){
//
//}
//
/* }}} hash table define */

int main(void){
  unsigned short loop_counter = 0, program_couter = 0, save_program_couter;

  /* {{{ repl loop */
  while (true){
    printf("\nbranfuck[%u]: ", loop_counter);
    program_couter = 0;
    fgets(input, PROGRAM_SIZE, stdin);
    // brackets_stack(input);

    /* {{{ exec loop */
    for(int i = 0; i < PROGRAM_SIZE; i++){
      switch (input[program_couter]) {
        case '+': tape[cell_index] += 1;
                  break;
        case '-': tape[cell_index] -= 1;
                  break;
        case '>': cell_index == PROGRAM_SIZE-1 ? cell_index = 0 : cell_index++;
                  break;
        case '<': cell_index == 0 ? cell_index = PROGRAM_SIZE-1 : cell_index--;
                  break;
        case '.': putc(tape[cell_index], stdout);
                  break;
        case ',': tape[cell_index] = getc(stdin);
                  break;
        case '[': save_program_couter = program_couter;
                  break;
        case ']': if (tape[cell_index] != 0)
                    program_couter = save_program_couter;
                  break;
      }
      ++program_couter;
    }
    /* }}} exec loop */
    ++loop_counter;
    print_tape(); /* debug */
  }
  /* }}} repl loop */

  return EXIT_SUCCESS;
}

/* {{{ debug */
void print_tape(void){
  printf("\n> %d\n", cell_index);
  for(int i = 0; i < 10; i++)
    printf("i:%d c:%c d:%d |", i, tape[i], tape[i]);
}
/* }}} debug */

/* {{{ stack func */
//void push(char *input){
//  for(int i = 0; i < strlen(input); i++)
//    brackets_stack[count_stack++] = &input[i];
//}
//
//void pop(){
//
//}
/* }}} stack func */
