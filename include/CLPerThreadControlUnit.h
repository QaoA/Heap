//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLPERTHREADCONTROLUNIT_H
#define MALLOC_3_CPP_CLPERTHREADCONTROLUNIT_H

#include "CLFreeLists.h"
#include "CLLargeList.h"
#include "CLAllocatedList.h"
#include "define.h"

class CLPerThreadControlUnit
{
private:
    CLFreeLists m_freeList;
    CLLargeList m_largeList;
    CLAllocatedList m_allocatedList;
public:

};


#endif //MALLOC_3_CPP_CLPERTHREADCONTROLUNIT_H
