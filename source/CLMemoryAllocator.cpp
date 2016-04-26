//
// Created by mq on 16-4-12.
//

#include "../include/CLMemoryAllocator.h"

CLMemoryAllocator::CLMemoryAllocator():
m_allocatedCount(0),
m_freeChunkManager(),
m_allocatedChunks()
{
}

CLMemoryAllocator::~CLMemoryAllocator()
{
}

void CLMemoryAllocator::AppendLargeFreeChunk(void * pvChunk, unsigned long ulChunkSize)
{
    CLDoubleLinkListChunk largeFreeChunk(pvChunk,ulChunkSize,FREE);
    m_freeChunkManager.DirectAppendChunk(largeFreeChunk);
}
//TODO complete GetValidMemory
void * CLMemoryAllocator::GetValidMemory(unsigned long ulBlockSize)
{
    unsigned long ulChunkSize = ulBlockSize + MIN_CHUNK_META_DATA_SIZE;
    CLDoubleLinkListChunk freeChunk = m_freeChunkManager.GetChunk(ulChunkSize);
    return
}