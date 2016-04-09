//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
#define MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H

class CLDoubleLinkListNode
{
private:
    CLDoubleLinkListNode * m_pNext;
    CLDoubleLinkListNode * m_pPrevious;
public:
    CLDoubleLinkListNode();
    CLDoubleLinkListNode(CLDoubleLinkListNode * pNextNode,CLDoubleLinkListNode * pPreviousNode);
public:
    void AppendToList(CLDoubleLinkListNode * pPreviousNode,CLDoubleLinkListNode * pNextNode);
    void RemoveFromList();
    void SetPreviousNode(CLDoubleLinkListNode * pPreviousNode);
    void SetNextNode(CLDoubleLinkListNode * pNextNode);
    CLDoubleLinkListNode * GetNextNode();
    CLDoubleLinkListNode * GetPreviousNode();
};

#endif //MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
