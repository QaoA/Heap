//
// Created by mq on 16-4-12.
//

#ifndef MALLOC_3_CPP_CLMEMORYALLOCATOR_H
#define MALLOC_3_CPP_CLMEMORYALLOCATOR_H

#include "CLFreeChunksManager.h"
#include "CLAllocatedChunks.h"

class CLMemoryAllocator {
private:
    int m_allocatedCount;
    CLFreeChunksManager m_freeChunkManager;
    CLAllocatedChunks m_allocatedChunks;
public:
    CLMemoryAllocator();
    ~CLMemoryAllocator();
public:
    void AppendLargeFreeChunk(void * pvChunk, unsigned long ulChunkSize);
    void * GetValidMemory(unsigned long ulBlockSize);
    void ReturnChunk(void * pvBlockPointer);
};


#endif //MALLOC_3_CPP_CLMEMORYALLOCATOR_H
