#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX 100

struct stack{
    int32_t data;
    struct stack *top;
};

struct stack* initstack();
void push(struct stack *s, int data);
struct stack *createStack();

#endif