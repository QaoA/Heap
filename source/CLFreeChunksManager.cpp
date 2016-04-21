//
// Created by mq on 16-4-12.
//

#include <assert.h>
#include "../include/CLFreeChunksManager.h"

CLFreeChunksManager::CLFreeChunksManager()
{
}

CLFreeChunksManager::~CLFreeChunksManager()
{
}

int CLFreeChunksManager::CountIndex(unsigned long ulChunkSize)
{
    assert(ulChunkSize - 2*PER_CONTROL_UNIT_SIZE >= MIN_ALLOCATE_BLOCK_SIZE);
    int index = static_cast<int>((ulChunkSize - 2*PER_CONTROL_UNIT_SIZE)/MIN_ALLOCATE_BLOCK_SIZE) - 1;

    if(index >= FREE_LISTS_SIZE)
    {
        return FREE_LISTS_SIZE;
    }

    return index;
}

unsigned long CLFreeChunksManager::AlignSize(unsigned long ulChunkSize)
{
    if(ulChunkSize == 0)
    {
        return MIN_ALLOCATE_BLOCK_SIZE;
    }
    unsigned long ulAlignSize = ulChunkSize & ~(0x1 << ALIGN_BIT_LENGTH);
    if(ulAlignSize == ulChunkSize)
    {
        return ulChunkSize;
    }

    return ulAlignSize + 1;
}

void CLFreeChunksManager::AppendChunk(CLDoubleLinkListChunk & rNewChunk)
{
    unsigned long ulChunkSize = rNewChunk.GetSize();
    CLDoubleLinkListChunk::AppenNewChunk(m_FreeLists[CountIndex(ulChunkSize)],rNewChunk);
}

//TODO complete this function,continue with find chunk from FREELIST
CLChunk CLFreeChunksManager::GetChunk(unsigned long ulChunkSize)
{
    CLChunk newChunk;
    if(ulChunkSize > MAX_ALLOCATE_BLOCK_SIZE)
    {
        return newChunk;
    }

    for()
}