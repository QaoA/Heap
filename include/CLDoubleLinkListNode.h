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
    void SetPreviousNode(CLDoubleLinkListNode * pPreviousNode);
    void SetNextNode(CLDoubleLinkListNode * pNextNode);
    CLDoubleLinkListNode * GetNextNode();
    CLDoubleLinkListNode * GetPreviousNode();
public:
    static void AppendToList(CLDoubleLinkListNode & rPreviousNode,CLDoubleLinkListNode & rCurrentNode,CLDoubleLinkListNode & rNextNode);
    static void RemoveFromList(CLDoubleLinkListNode & rCurrentNode);
};

#endif //MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
