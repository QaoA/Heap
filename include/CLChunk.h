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
    //TODO split merge remove append
    void SetChunkPointer(void * pvChunk);
    void SetSize(unsigned long ulSize);
    void SetExistStatus(EMExistStatus status);
    void * GetChunkPointer();
    void * GetNextChunk();
    void * GetPreviousChunkFoot();
    unsigned long GetSize();
    EMExistStatus GetExistStatus();
public:
    static
    static void Split(const unsigned long ulNewChunkSize,CLChunk & roldChunk,CLChunk & rNewChunk,CLChunk & rRestChunk);
    //void Merge(const CLChunk & rPreviousChunk,const CLChunk & rChunk_2,CLChunk & rNewChunk);
    //void RemoveFromList();
    //void AppendToList(CLChunk & rPreviousChunk, CLChunk & rNextChunk);
};



#endif //MALLOC_3_CPP_CLCHUNK_H
