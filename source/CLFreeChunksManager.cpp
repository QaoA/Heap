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

void CLFreeChunksManager::AppendChunk(CLDoubleLinkListChunk & rNewChunk)
{
    unsigned long ulChunkSize = rNewChunk.GetSize();
    CLDoubleLinkListChunk::AppendNewChunk(m_FreeLists[CountIndex(ulChunkSize)],rNewChunk);
}

//TODO complete this function,continue with find chunk from FREELIST
CLChunk CLFreeChunksManager::GetChunk(unsigned long ulChunkSize)
{
    CLChunk newChunk;
    unsigned long ulAlignChunkSize = AlignSize(ulChunkSize);
    if(ulAlignChunkSize > MAX_ALLOCATE_BLOCK_SIZE)
    {
        return newChunk;
    }

    int index = CountIndex(ulAlignChunkSize);
    void * pvReturnChunk;
    for(int i = index;i <= FREE_LISTS_SIZE;i++)
    {
        pvReturnChunk = m_FreeLists[index].GetLogicNextChunk();
        if(pvReturnChunk)
        {
            CLDoubleLinkListChunk restChunk;
            CLDoubleLinkListChunk returnChunk(pvReturnChunk);
            CLDoubleLinkListChunk::RemoveChunk(returnChunk);
            CLDoubleLinkListChunk::SplitChunk(ulAlignChunkSize,returnChunk,restChunk);
        }
    }
}