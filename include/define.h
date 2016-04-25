//
// Created by mq on 16-4-9.
//

#include <stddef.h>

#ifndef MALLOC_3_CPP_DEFINE_H
#define MALLOC_3_CPP_DEFINE_H

const unsigned int ALIGN_BIT_LENGTH = 4;
const unsigned int MAX_ALLOCATE_BLOCK_SIZE = 1024;
const unsigned int MIN_ALLOCATE_BLOCK_SIZE = 1 << ALIGN_BIT_LENGTH;
const unsigned int FREE_LISTS_SIZE = MAX_ALLOCATE_BLOCK_SIZE/MIN_ALLOCATE_BLOCK_SIZE;

const unsigned int PER_CONTROL_UNIT_SIZE = static_cast<unsigned int>(sizeof(void*));
const unsigned long DEFAULT_ALLOCATE_BLOCK_SIZE = 2*1024*1024;
const unsigned long DEFAULT_ALLOCATE_MEMORY_SIZE = DEFAULT_ALLOCATE_BLOCK_SIZE + 2*PER_CONTROL_UNIT_SIZE;

const unsigned int MAX_ALLOCATE_CHUNK_SIZE = MAX_ALLOCATE_BLOCK_SIZE + 3*PER_CONTROL_UNIT_SIZE;
const unsigned int MIN_ALLOCATE_CHUNK_SIZE = MIN_ALLOCATE_BLOCK_SIZE + 3*PER_CONTROL_UNIT_SIZE;

inline void * GetNewPointerByOffset(void * pvPointer, unsigned long ulOffset)
{
    return reinterpret_cast<void *>(reinterpret_cast<unsigned long>(pvPointer) + ulOffset);
}

inline unsigned long AlignSize(unsigned long ulChunkSize)
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

#endif //MALLOC_3_CPP_DEFINE_H
