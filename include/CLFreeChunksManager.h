//
// Created by mq on 16-4-12.
//

#ifndef MALLOC_3_CPP_CLFREECHUNKSMANAGER_H
#define MALLOC_3_CPP_CLFREECHUNKSMANAGER_H

#include "define.h"
#include "CLDoubleLinkListChunk.h"

class CLFreeChunksManager {
private:
    CLDoubleLinkListChunk m_FreeLists[FREE_LISTS_SIZE + 1];
public:
    CLFreeChunksManager();
    ~CLFreeChunksManager();
private:
    int CountIndex(unsigned long ulChunkSize);
public:
    void AppendChunk(CLDoubleLinkListChunk & rNewChunk);
    CLChunk GetChunk(unsigned long ulChunkSize);
};


#endif //MALLOC_3_CPP_CLFREECHUNKSMANAGER_H
