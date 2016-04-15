//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_SLHEADORFOOT_H
#define MALLOC_3_CPP_SLHEADORFOOT_H

#include "ILMemoryFlusher.h"

enum EMExistStatus
{
    BUSY = 0x0,
    RETURNED = 0x1,
    FREE = 0x2,
};


struct SLHeadOrFoot:public ILMemoryFlusher
{
private:
    unsigned long m_ulChunkSize:60;
    int m_undefined:2;
    EMExistStatus m_emChunkStatus:2;
public:
    SLHeadOrFoot();//for array
    SLHeadOrFoot(void * pvChunkHeadOrFoot);//for restore
    SLHeadOrFoot(void * pvChunkHeadOrFoot,unsigned long ulChunkSize = 0,EMExistStatus emStatus = FREE);//for normal initial
public:
    void SetExistStatus(EMExistStatus emStatus);
    void SetChunkSize(unsigned long ulChunkSize);
    EMExistStatus GetExistStatus();
    unsigned long GetChunkSize();
public:
    void FlushToMemory();
};

#endif //MALLOC_3_CPP_SLHEADORFOOT_H
