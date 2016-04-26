//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLCHUNK_H
#define MALLOC_3_CPP_CLCHUNK_H

#include "SLHeadOrFoot.h"
#include "define.h"

class CLChunk
{
protected:
    void * m_pvChunk;
    SLHeadOrFoot m_headOrFoot;
public:
    CLChunk();//for array
    explicit CLChunk(void * pvChunk);//for restore
    CLChunk(void * pvChunk, unsigned long ulChunkSize, EMExistStatus emChunkStatus);//for normal initial
    virtual ~CLChunk();
public:
    virtual unsigned long GetSize();
    virtual EMExistStatus GetStatus();
    virtual void * GetChunkPointer();
protected:
    virtual void * GetHead();
    virtual void * GetFoot();
    virtual void * GetPhysicalNextNodeHeadAddress();
    virtual void * GetPhysicalPreviousNodeAddress();
public:
    virtual void * GetValidMemoryAddress() = 0;
    virtual void FlushToMemory() = 0;
public:
    static void PutData(void * pvAddress, unsigned long ulData);
    static void * CountAddress(void * pvAddress, unsigned long ulDelta,bool bIsAdd = true);
};
#endif //MALLOC_3_CPP_CLCHUNK_H
