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
    EMExistStatus m_emChunkStatus;
    unsigned long m_ulChunkSize;
public:
    SLHeadOrFoot();//array
    SLHeadOrFoot(void * pvChunkHeadOrFoot);//for restore
    SLHeadOrFoot(unsigned long ulChunkSize,EMExistStatus emStatus);//for normal initial
public:
    void SetExistStatus(EMExistStatus emStatus);
    void SetChunkSize(unsigned long ulChunkSize);
    EMExistStatus GetExistStatus();
    unsigned long GetChunkSize();
public:
    unsigned long GetPackedData();
};

#endif //MALLOC_3_CPP_SLHEADORFOOT_H
