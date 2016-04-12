//
// Created by mq on 16-4-9.
//

#include "../include/CLSingleLinkListNode.h"
#include <assert.h>

CLSingleLinkListNode::CLSingleLinkListNode(CLSingleLinkListNode * pNext):
m_pNext(pNext)
{

}

CLSingleLinkListNode * CLSingleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}

static explicit void CLSingleLinkListNode::AppendNextNode(CLSingleLinkListNode & rPreviousNode,CLSingleLinkListNode & rCurrentNode)
{
    CLSingleLinkListNode * pOriginNextNode = rPreviousNode.m_pNext;
    rPreviousNode.m_pNext = &rCurrentNode;
    rCurrentNode.m_pNext = pOriginNextNode;
}

static void CLSingleLinkListNode::RemoveFromList(CLSingleLinkListNode & pPreviousNode)
{
    CLSingleLinkListNode * pCurrentNode = pPreviousNode.m_pNext;
    CLSingleLinkListNode * pNextNode = pCurrentNode->m_pNext;
    pPreviousNode.m_pNext = pNextNode;
    pCurrentNode->m_pNext = NULL;
}
