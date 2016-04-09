//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_DEFINE_H
#define MALLOC_3_CPP_DEFINE_H

const unsigned int ALIGN_BIT_LENGTH = 4;
const unsigned int MAX_ALLOCATE_BLOCK_SIZE = 1024;
const unsigned int MIN_ALLOCATE_BLOCK_SIZE = 1 << ALIGN_BIT_LENGTH;
const unsigned int FREE_LIST_SIZE = MAX_ALLOCATE_BLOCK_SIZE/MIN_ALLOCATE_BLOCK_SIZE;

#endif //MALLOC_3_CPP_DEFINE_H
