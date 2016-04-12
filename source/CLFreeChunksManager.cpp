//
// Created by mq on 16-4-12.
//

#include <assert.h>
#include "../include/CLFreeChunksManager.h"

CLFreeChunksManager::CLFreeChunksManager(void * InitMemory, const unsigned long ulInitMemorySize):
{
    assert((ulInitMemorySize - 2*PER_CONTROL_UNIT_SIZE)% DEFAULT_ALLOCATE_BLOCK_SIZE == 0);
    SLHeadOrFoot InitMemoryControlBlock(ulInitMemorySize,BUSY);
    InitMemoryControlBlock.FlushToMemory(InitMemory);
    InitMemoryControlBlock.FlushToMemory(GetNewPointerByOffset(InitMemory,ulInitMemorySize - PER_CONTROL_UNIT_SIZE));

    CLChunk largeChunk(GetNewPointerByOffset(InitMemory,PER_CONTROL_UNIT_SIZE),
                       ulInitMemorySize - 2*PER_CONTROL_UNIT_SIZE);
    CLChunk::AppendToDoubleLinkList()
}
