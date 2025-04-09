#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef enum msg_kind {
    INT32,
    FLOAT,
	VOID
} msg_kind;

typedef struct msg_t {
    msg_kind kind;
    union {
        int32_t i;
        float f;
    } data;
} msg_t;

extern msg_t createIntMsg(int32_t i);
extern msg_t createFloatMsg(float f);

extern int32_t processInt(int32_t i);
extern int32_t processFloat(float f);

extern void printStatus(int32_t status);

#endif

