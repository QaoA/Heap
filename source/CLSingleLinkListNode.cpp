//
// Created by mq on 16-4-9.
//

#include "../include/CLSingleLinkListNode.h"
#include <assert.h>

CLSingleLinkListNode::CLSingleLinkListNode(CLSingleLinkListNode * pNext):
m_pNext(pNext)
{

}

explicit CLSingleLinkListNode::CLSingleLinkListNode(void * pvSingleListNodeAddress):
m_pNext(*reinterpret_cast<CLSingleLinkListNode **>(pvSingleListNodeAddress))
{

}

CLSingleLinkListNode * CLSingleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}

void CLSingleLinkListNode::AppendNextNode(CLSingleLinkListNode & rPreviousNode,CLSingleLinkListNode & rCurrentNode)
{
    CLSingleLinkListNode * pOriginNextNode = rPreviousNode.m_pNext;
    rPreviousNode.m_pNext = &rCurrentNode;
    rCurrentNode.m_pNext = pOriginNextNode;
}

void CLSingleLinkListNode::RemoveFromList(CLSingleLinkListNode & pPreviousNode)
{
    CLSingleLinkListNode * pCurrentNode = pPreviousNode.m_pNext;
    CLSingleLinkListNode * pNextNode = pCurrentNode->m_pNext;
    pPreviousNode.m_pNext = pNextNode;
    pCurrentNode->m_pNext = NULL;
}
