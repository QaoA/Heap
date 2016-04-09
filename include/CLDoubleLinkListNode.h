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
    CLDoubleLinkListNode(CLDoubleLinkListNode * pNext,CLDoubleLinkListNode * pPrevious);
};

#endif //MALLOC_3_CPP_CLDOUBLELINKLISTNODE_H
