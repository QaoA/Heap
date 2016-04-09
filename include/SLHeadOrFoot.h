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
    SLHeadOrFoot(void* chunkHeadOrFoot);
    SLHeadOrFoot(SLHeadOrFoot& headOrFoot);
    SLHeadOrFoot(unsigned long chunkSize = 0,EMExistStatus status = FREE);
public:
    void SetExistStatus(EMExistStatus existStatus);
    void SetChunkSize(unsigned long chunkSize);
    EMExistStatus GetExistStatus();
    unsigned long GetChunkSize();
};

#endif //MALLOC_3_CPP_SLHEADORFOOT_H
