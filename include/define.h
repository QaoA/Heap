//
// Created by mq on 16-4-9.
//

#include <stddef.h>

#ifndef MALLOC_3_CPP_DEFINE_H
#define MALLOC_3_CPP_DEFINE_H

const unsigned int ALIGN_BIT_LENGTH = 4;
const unsigned int MAX_ALLOCATE_BLOCK_SIZE = 1024;
const unsigned int MIN_ALLOCATE_BLOCK_SIZE = 1 << ALIGN_BIT_LENGTH;
const unsigned int FREE_LIST_SIZE = MAX_ALLOCATE_BLOCK_SIZE/MIN_ALLOCATE_BLOCK_SIZE;

const unsigned int PER_CONTROL_UNIT_SIZE = static_cast<unsigned int>(sizeof(void*));
const unsigned long DEFAULT_ALLOCATE_BLOCK_SIZE = 2*1024*1024;
const unsigned long DEFAULT_ALLOCATE_MEMORY_SIZE = DEFAULT_ALLOCATE_BLOCK_SIZE + 2*PER_CONTROL_UNIT_SIZE;

#endif //MALLOC_3_CPP_DEFINE_H
