//
// Created by mq on 16-4-12.
//

#ifndef MALLOC_3_CPP_CLFREECHUNKSMANAGER_H
#define MALLOC_3_CPP_CLFREECHUNKSMANAGER_H

#include "CLChunk.h"
#include "define.h"

class CLFreeChunksManager {
private:
    CLChunk m_FreeLists[FREE_LISTS_SIZE];
    CLChunk m_LargeList;
public:
    CLFreeChunksManager(void * InitMemory, const unsigned long ulInitMemorySize = DEFAULT_ALLOCATE_MEMORY_SIZE);
public:
    void AppendChunk(CLChunk & rNewChunk);
    void GetAChunk(unsigned long ulChunkSize);
};


#endif //MALLOC_3_CPP_CLFREECHUNKSMANAGER_H
