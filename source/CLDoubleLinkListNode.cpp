//
// Created by mq on 16-4-9.
//

#include "../include/CLDoubleLinkListNode.h"

CLDoubleLinkListNode::CLDoubleLinkListNode():
m_pNext(this),
m_pPrevious(this)
{

}

CLDoubleLinkListNode::CLDoubleLinkListNode(CLDoubleLinkListNode *pNext, CLDoubleLinkListNode *pPrevious):
m_pNext(pNext),m_pPrevious(pPrevious)
{

}