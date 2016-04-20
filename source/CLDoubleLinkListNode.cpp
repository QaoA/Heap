//
// Created by mq on 16-4-9.
//

#include <stddef.h>
#include <assert.h>
#include "../include/CLDoubleLinkListNode.h"
#include "../include/define.h"


CLDoubleLinkListNode::CLDoubleLinkListNode():
m_pNext(NULL),
m_pPrevious(NULL)
{

}

CLDoubleLinkListNode::CLDoubleLinkListNode(void * pvDoubleListNodeAddress):
m_pNext(pvDoubleListNodeAddress?
        (*reinterpret_cast<CLDoubleLinkListNode **>(pvDoubleListNodeAddress)):
        nullptr),
m_pPrevious(pvDoubleListNodeAddress?
            (*reinterpret_cast<CLDoubleLinkListNode **>(GetNewPointerByOffset(pvDoubleListNodeAddress,PER_CONTROL_UNIT_SIZE))):
            nullptr)
{

}

CLDoubleLinkListNode::CLDoubleLinkListNode(CLDoubleLinkListNode *pNextNode, CLDoubleLinkListNode *pPreviousNode):
m_pNext(pNextNode),m_pPrevious(pPreviousNode)
{

}

void CLDoubleLinkListNode::FlushToMemory(void * pvFlushStartAddress)
{
    *reinterpret_cast<unsigned long *>(pvFlushStartAddress) = reinterpret_cast<unsigned long>(m_pNext);
    *reinterpret_cast<unsigned long *>(reinterpret_cast<unsigned long>(pvFlushStartAddress + PER_CONTROL_UNIT_SIZE))
            = reinterpret_cast<unsigned long>(m_pPrevious);
}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetPreviousNode()
{
    return this->m_pPrevious;
}

void CLDoubleLinkListNode::AppendToList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode * pNextNode)
{
    assert(rPreviousNode.GetNextNode() == pNextNode);
    rPreviousNode.m_pNext = &rCurrentNode;
    rCurrentNode.m_pPrevious = &rPreviousNode;
    rCurrentNode.m_pNext = pNextNode;
    if(pNextNode)
    {
        pNextNode->m_pPrevious = &rCurrentNode;
    }
}

void CLDoubleLinkListNode::RemoveFromList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode * pNextNode)
{
    assert(rPreviousNode.GetNextNode() == &rCurrentNode && rCurrentNode.GetNextNode() == pNextNode);

    rCurrentNode.m_pNext = nullptr;
    rCurrentNode.m_pPrevious = nullptr;
    rPreviousNode.m_pNext = pNextNode;
    if(pNextNode)
    {
        pNextNode->m_pPrevious = &rPreviousNode;
    }
}