#include "msg.h"

msg_t createIntMsg(int32_t i)
{
    msg_t msg;
    msg.kind = INT32;
    msg.data.i = i;
    return msg;
}

msg_t createFloatMsg(float f)
{
    msg_t msg;
    msg.kind = INT32;
    msg.data.f = f;
    return msg;
}
