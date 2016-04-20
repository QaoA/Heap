//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
#define MALLOC_3_CPP_CLSINGLELINKLISTNODE_H

#include <stddef.h>
#include "CLDoubleLinkListNode.h"
#include "ILMemoryFlusher.h"

class CLSingleLinkListNode:public ILMemoryFlusher
{
private:
    CLSingleLinkListNode * m_pNext;
public:
    explicit CLSingleLinkListNode(void * pvSingleListNodeAddress);
    explicit CLSingleLinkListNode(CLSingleLinkListNode * pNext = nullptr);
public:
    CLSingleLinkListNode * GetNextNode();
    void FlushToMemory(void * pvWriteStartAddress) override;
public:
    static void AppendNextNode(CLSingleLinkListNode & rPreviousNode,CLSingleLinkListNode & rCurrentNode);
    static void RemoveFromList(CLSingleLinkListNode & rPreviousNode,CLSingleLinkListNode & rCurrentNode);
};

#endif //MALLOC_3_CPP_CLSINGLELINKLISTNODE_H
