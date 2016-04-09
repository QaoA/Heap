//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
#define MALLOC_3_CPP_CLSINGLELINKLISTNODE_H

#include <stddef.h>
#include "CLDoubleLinkListNode.h"

class CLSingleLinkListNode
{
private:
    CLSingleLinkListNode * m_pNext;
public:
    CLSingleLinkListNode(CLSingleLinkListNode * pNext = this);
};

#endif //MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
