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
    explicit CLSingleLinkListNode(CLSingleLinkListNode * pNext = NULL);
public:
    explicit void AppendNextNode(CLSingleLinkListNode * pNextNode);
    explicit void RemoveFromList(CLSingleLinkListNode * pPreviousNode);
    explicit void SetNextNode(CLSingleLinkListNode * pNextNode);
    CLSingleLinkListNode * GetNextNode();
};

#endif //MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
