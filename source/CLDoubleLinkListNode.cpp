//
// Created by mq on 16-4-9.
//

#include <stddef.h>
#include "../include/CLDoubleLinkListNode.h"


CLDoubleLinkListNode::CLDoubleLinkListNode():
m_pNext(NULL),
m_pPrevious(NULL)
{

}

CLDoubleLinkListNode::CLDoubleLinkListNode(CLDoubleLinkListNode *pNextNode, CLDoubleLinkListNode *pPreviousNode):
m_pNext(pNextNode),m_pPrevious(pPreviousNode)
{

}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetPreviousNode()
{
    return this->m_pPrevious;
}

void CLDoubleLinkListNode::AppendToList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode & rNextNode)
{
    rPreviousNode.m_pNext = &rCurrentNode;
    rNextNode.m_pPrevious = &rCurrentNode;
    rCurrentNode.m_pNext = &rNextNode;
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