//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLCHUNK_H
#define MALLOC_3_CPP_CLCHUNK_H

#include "SLHeadOrFoot.h"
#include "CLSingleLinkListNode.h"
#include "CLDoubleLinkListNode.h"

class CLChunk
{
private:
    void * m_pvChunk;
    SLHeadOrFoot m_headOrFoot;
    union
    {
        CLSingleLinkListNode m_singleListNode;
        CLDoubleLinkListNode m_doubleListNode;
    };
public:
    explicit CLChunk(void * pvChunk);
    CLChunk(void * pvChunk, unsigned long ulChunkSize);
public:
    //TODO split merge remove append get set
};


#endif //MALLOC_3_CPP_CLCHUNK_H
