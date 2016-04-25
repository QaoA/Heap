//
// Created by mq on 16-4-20.
//

#ifndef MALLOC_3_CPP_CLSINGLELINKLISTCHUNK_H
#define MALLOC_3_CPP_CLSINGLELINKLISTCHUNK_H

#include "CLChunk.h"

class CLSingleLinkListChunk:public CLChunk
{
private:
    void * m_pvNextChunk;
private:
    void * GetNexChunkAddress();
public:
    CLSingleLinkListChunk();
    explicit CLSingleLinkListChunk(void * pvChunk);
    CLSingleLinkListChunk(void * pvChunk,EMExistStatus emChunkStatus,unsigned long ulChunkSize);
    virtual ~CLSingleLinkListChunk();
    virtual void FlushToMemory() override;
public:
    void SetStatus(EMExistStatus status);
    void * GetLogicNextChunk();
public:
    static void AppendNode(CLSingleLinkListChunk & rPreviousChunk,CLSingleLinkListChunk & rNewNode);
    static void * RemoveNode(CLSingleLinkListChunk & rPreviousChunk);
};

#endif //MALLOC_3_CPP_CLSINGLELINKLISTCHUNK_H
