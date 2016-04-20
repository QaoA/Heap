//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
#define MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H

#include "ILMemoryFlusher.h"

class CLDoubleLinkListNode:ILMemoryFlusher
{
private:
    CLDoubleLinkListNode * m_pNext;
    CLDoubleLinkListNode * m_pPrevious;
public:
    CLDoubleLinkListNode();
    CLDoubleLinkListNode(void * pvDoubleListNodeAddress);
    CLDoubleLinkListNode(CLDoubleLinkListNode * pNextNode,CLDoubleLinkListNode * pPreviousNode);
public:
    void FlushToMemory(void * pvFlushStartAddress);
    CLDoubleLinkListNode * GetNextNode();
    CLDoubleLinkListNode * GetPreviousNode();
public:
    static void AppendToList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode * pNextNode);
    static void RemoveFromList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode * pNextNode);
};

#endif //MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
