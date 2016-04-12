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
    CLSingleLinkListNode * GetNextNode();
public:
    static void AppendNextNode(CLSingleLinkListNode & rPreviousNode,CLSingleLinkListNode & rCurrentNode);
    static void RemoveFromList(CLSingleLinkListNode & rPreviousNode);
};

#endif //MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
