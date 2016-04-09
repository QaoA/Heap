//
// Created by mq on 16-4-9.
//

#include "../include/CLSingleLinkListNode.h"
#include <assert.h>

CLSingleLinkListNode::CLSingleLinkListNode(CLSingleLinkListNode * pNext):
m_pNext(pNext)
{

}
void CLSingleLinkListNode::AppendNextNode(CLSingleLinkListNode * pNextNode)
{
    CLSingleLinkListNode * pOriginNextNode = this->m_pNext;
    SetNextNode(pNextNode);
    if(pNextNode)
    {
        pNextNode->SetNextNode(pOriginNextNode);
    }
}

void CLSingleLinkListNode::RemoveFromList(CLSingleLinkListNode * pPreviousNode)
{
    assert(pPreviousNode && pPreviousNode->GetNextNode() == this);
    pPreviousNode->SetNextNode(this->GetNextNode());
    this->SetNextNode(NULL);
}

void CLSingleLinkListNode::SetNextNode(CLSingleLinkListNode *pNextNode)
{
    this->m_pNext = pNextNode;
}

CLSingleLinkListNode * CLSingleLinkListNode::GetNextNode()
{
    return this->m_pNext;
}