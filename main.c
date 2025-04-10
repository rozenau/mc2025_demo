#include "msg.h"
#include "com.h"
#include "process.h"

#include <stdbool.h>
#include <stdlib.h>


static void processMsg(const msg_t* msg)
{
    int32_t result = 0;
    switch (msg->kind) {
        case INT32:
            result = processInt(msg->data.i);
            break;
        case FLOAT:
            result = processFloat(msg->data.f);
            break;
        case VOID:
        	return;
        default:
            break;
    }
    printStatus(result);
}

static void main_loop(void)
{
    while (true) {
        int32_t* i = getInt();
        if (i != NULL) { // Explicit comparison to NULL
            msg_t msg = createIntMsg(*i);
            processMsg(&msg);
        }
        float* f = getFloat();
        if (f != NULL) { // Explicit comparison to NULL
            msg_t msg = createFloatMsg(*f);
            processMsg(&msg);
        }
        if (i == NULL && f == NULL) { // Explicit comparison to NULL
            return;
        }
    }
}

int main(void)
{
	main_loop();
	return 0;
}

