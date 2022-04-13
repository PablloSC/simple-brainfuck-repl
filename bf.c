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

#define PROGRAM_SIZE 65535

unsigned short cell = 0, loop_counter = 0, program_couter = 0;
unsigned char tape[PROGRAM_SIZE], input[PROGRAM_SIZE];

void eval     (void);
// commands
void sum      (void);
void less     (void);
void right    (void);
void left     (void);
void dot      (void);
void comma    (void);
void r_bracket(void);
void l_bracket(void);

int main(void) {
    // repl
    for(;;) {
        printf("\nbranfuck[%u]: ", loop_counter);
        memset(input, 0, sizeof(input)); /* reset input */
        fgets(input, PROGRAM_SIZE, stdin);
        if(input[0] == ':' && input[1] == 'q') return EXIT_SUCCESS;
        eval();
    }
    return EXIT_SUCCESS;
}

void eval(void) {
    // token + exec
    for(unsigned int i = 0; i < PROGRAM_SIZE; i++) {
        switch(input[program_couter]) {
            case '+': sum();       break;
            case '-': less();      break;
            case '>': right();     break;
            case '<': left();      break;
            case '.': dot();       break;
            case ',': comma();     break;
            case '[': r_bracket(); break;
            case ']': l_bracket(); break;
        }
        ++program_couter;
    }
    ++loop_counter;
}

void sum(void) {
    tape[cell] += 1;
}

void less(void) {
    tape[cell] -= 1;
}

void right(void) {
    cell == PROGRAM_SIZE-1 ? cell = 0 : cell++;
}

void left(void) {
    cell == 0 ? cell = PROGRAM_SIZE-1 : cell--;
}


void dot(void) {
    putc(tape[cell], stdout);
}

void comma(void) {
    tape[cell] = getc(stdin);
}

void r_bracket(void) {
    int n = 1;
    if(tape[cell] == 0)
        for(++program_couter; n; ++program_couter){
            if(input[program_couter] == '[') ++n;
            if(input[program_couter] == ']') --n;
        }
}

void l_bracket(void) {
    int n = 1;
    if(tape[cell] != 0)
        for(--program_couter; n; --program_couter){
            if(input[program_couter] == ']') ++n;
            if(input[program_couter] == '[') --n;
        }
}
