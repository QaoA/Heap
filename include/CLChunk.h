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
private:

public:
    explicit CLChunk(void * pvChunk);
    CLChunk(void * pvChunk, unsigned long ulChunkSize);
    ~CLChunk();
public:
    //TODO split merge remove append
    void SetChunkPointer(void * pvChunk);
    void SetSize(unsigned long ulSize);
    void SetExistStatus(EMExistStatus status);
    void * GetChunkPointer();
    unsigned long GetSize();
    EMExistStatus GetExistStatus();
public:
    void * GetPysicalNextChunk();
    void * GetPysicalPreviousChunkFoot();
    void FlushToMemory();
public:
    static void Split(const unsigned long ulNewChunkSize,CLChunk & roldChunk,CLChunk & rRestChunk);
    static void Merge(CLChunk & rPreviousChunk,CLChunk & rNextChunk);
    static void AppendToSingleLinkList(CLChunk & rPrivousChunk,CLChunk & rCurrentChunk);
    static void RemoveFromSingleLinkList(CLChunk & rPreviousChunk);
    static void AppendToDoubleLinkList(CLChunk & rPreviousChunk,CLChunk & rCurrentChunk,CLChunk & rNextChunk);
    static void RemoveFromDoubleLinkList(CLChunk & rCurrentChunk);
};



#endif //MALLOC_3_CPP_CLCHUNK_H
