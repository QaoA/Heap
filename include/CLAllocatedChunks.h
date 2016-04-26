//
// Created by mq on 16-4-12.
//

#ifndef MALLOC_3_CPP_CLALLOCATEDCHUNKS_H
#define MALLOC_3_CPP_CLALLOCATEDCHUNKS_H

#include "CLSingleLinkListChunk.h"

class CLAllocatedChunks
{
private:
    CLSingleLinkListChunk m_allocatedChunkHead;
    void * m_pvListCurrentPointer;
public:
    CLAllocatedChunks();
public:
    CLChunk GetReturnedChunk();
    void AppendChunk(CLSingleLinkListChunk & newChunk);
    void ReturnChunk(CLSingleLinkListChunk & returnChunk);
};


#endif //MALLOC_3_CPP_CLALLOCATEDCHUNKS_H
