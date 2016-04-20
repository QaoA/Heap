//
// Created by mq on 16-4-20.
//

#ifndef MALLOC_3_CPP_CLDOUBLELINKLISTCHUNK_H
#define MALLOC_3_CPP_CLDOUBLELINKLISTCHUNK_H

#include "SLHeadOrFoot.h"
#include "CLChunk.h"

class CLDoubleLinkListChunk: public CLChunk
{
private:
    void * m_pvNextChunk;
    void * m_pvPreviousChunk;
public:
    CLDoubleLinkListChunk();
    CLDoubleLinkListChunk(void * pvChunk);
    CLDoubleLinkListChunk(void * pvChunk,unsigned long ulChunkSize,EMExistStatus emChunkStatus);
    ~CLDoubleLinkListChunk();
public:
    static void AppenNewChunk(CLDoubleLinkListChunk & rPreviousChunk,CLDoubleLinkListChunk & rCurrentChunk);
    static void RemoveChunk(CLDoubleLinkListChunk & rCurrentChunk)
};

#endif //MALLOC_3_CPP_CLDOUBLELINKLISTCHUNK_H