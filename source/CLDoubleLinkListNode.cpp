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

void CLDoubleLinkListNode::AppendToList(CLDoubleLinkListNode * pPreviousNode,CLDoubleLinkListNode * pNextNode)
{
    SetNextNode(pNextNode);
    SetPreviousNode(pPreviousNode);

    if(pPreviousNode)
    {
        pPreviousNode->SetNextNode(this);
    }
    if(pNextNode)
    {
        pNextNode->SetPreviousNode(this);
    }
}

void CLDoubleLinkListNode::RemoveFromList()
{
    CLDoubleLinkListNode * pPreviousNode = GetPreviousNode();
    CLDoubleLinkListNode * pNextNode = GetNextNode();

    if(pPreviousNode)
    {
        pPreviousNode->SetNextNode(pNextNode);
    }
    if(pNextNode)
    {
        pNextNode->SetPreviousNode(pPreviousNode);
    }

    SetNextNode(NULL);
    SetPreviousNode(NULL);
}

void CLDoubleLinkListNode::SetPreviousNode(CLDoubleLinkListNode * pPreviousNode)
{
    this->m_pPrevious = pPreviousNode;
}

void CLDoubleLinkListNode::SetNextNode(CLDoubleLinkListNode *pNextNode)
{
    this->m_pNext = pNextNode;
}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}

CLDoubleLinkListNode * CLDoubleLinkListNode::GetPreviousNode()
{
    return this->m_pPrevious;
}
