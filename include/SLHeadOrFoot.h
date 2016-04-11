//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_SLHEADORFOOT_H
#define MALLOC_3_CPP_SLHEADORFOOT_H

enum EMExistStatus
{
    BUSY = 0x0,
    RETURNED = 0x1,
    FREE = 0x2,
};


struct SLHeadOrFoot
{
private:
    unsigned long m_ulChunkSize:60;
    int m_undefined:2;
    EMExistStatus m_emChunkStatus:2;
public:
    SLHeadOrFoot(void* pvChunkHeadOrFoot);
    SLHeadOrFoot(SLHeadOrFoot& rHeadOrFoot);
    SLHeadOrFoot(unsigned long ulChunkSize = 0,EMExistStatus emStatus = FREE);
public:
    void SetExistStatus(EMExistStatus emStatus);
    void SetChunkSize(unsigned long ulChunkSize);
    EMExistStatus GetExistStatus();
    unsigned long GetChunkSize();
public:
    void FlushToMemory(void * pvAddress);
};

#endif //MALLOC_3_CPP_SLHEADORFOOT_H
