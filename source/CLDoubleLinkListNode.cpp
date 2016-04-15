//
// Created by mq on 16-4-9.
//

#include <stddef.h>
#include "../include/CLDoubleLinkListNode.h"
#include "../include/define.h"


CLDoubleLinkListNode::CLDoubleLinkListNode():
m_pNext(NULL),
m_pPrevious(NULL)
{

}

CLDoubleLinkListNode::CLDoubleLinkListNode(void * pvDoubleListNodeAddress):
m_pNext(*reinterpret_cast<CLDoubleLinkListNode **>(pvDoubleListNodeAddress)),
m_pPrevious(*reinterpret_cast<CLDoubleLinkListNode **>(GetNewPointerByOffset(pvDoubleListNodeAddress,PER_CONTROL_UNIT_SIZE)))
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

void CLDoubleLinkListNode::AppendToList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode)
{
    CLDoubleLinkListNode * pNextNode = rPreviousNode.m_pNext;
    rPreviousNode.m_pNext = &rCurrentNode;
    if(pNextNode)
    {
        pNextNode->m_pPrevious = &rCurrentNode;
    }
    rCurrentNode.m_pNext = pNextNode;
    rCurrentNode.m_pPrevious = &rPreviousNode;
}

void CLDoubleLinkListNode::RemoveFromList(CLDoubleLinkListNode & rCurrentNode)
{
    CLDoubleLinkListNode * pPreviousNode = rCurrentNode.m_pPrevious;
    CLDoubleLinkListNode * pNextNode = rCurrentNode.m_pNext;
    pPreviousNode->m_pNext = pNextNode;
    pNextNode->m_pPrevious = pPreviousNode;
    rCurrentNode.m_pPrevious = NULL;
    rCurrentNode.m_pNext = NULL;
}