//
// Created by mq on 16-4-15.
//

#ifndef MALLOC_3_CPP_ILFLUSHTOMEMORY_H
#define MALLOC_3_CPP_ILFLUSHTOMEMORY_H

class ILMemoryFlusher
{
private:
    void * pvMemoryAddress;
public:
    ILMemoryFlusher(void * pvMemoryAddress);
    virtual void flushToMemory() = 0;
};

#endif //MALLOC_3_CPP_ILFLUSHTOMEMORY_H
