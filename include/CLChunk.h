//
// Created by mq on 16-4-9.
//

#ifndef MALLOC_3_CPP_CLCHUNK_H
#define MALLOC_3_CPP_CLCHUNK_H

#include "SLHeadOrFoot.h"
#include "CLSingleLinkListNode.h"
#include "CLDoubleLinkListNode.h"

#define GET_OFFSET(CLASS,MEMBER) reinterpret_cast<unsigned long>(&(reinterpret_cast<CLASS *>(0) -> MEMBER))

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
    void * GetHead();
    void * GetFoot();
    void * GetNextNodeAddress();
    void * GetPreviousNodeAddress();
public:
    CLChunk();//for array
    explicit CLChunk(void * pvChunk);//for restore
    CLChunk(void * pvChunk, unsigned long ulChunkSize);//for normal initial
    ~CLChunk();
public:
    void SetChunkPointer(void * pvChunk);
    void SetSize(unsigned long ulSize);
    void SetExistStatus(EMExistStatus status);
    void * GetChunkPointer();
    unsigned long GetSize();
    EMExistStatus GetExistStatus();
public:
    void * GetLogicNextChunkBySingleLinkList();
    void * GetLogicNextChunkByDoubleLinkList();
    void * GetLogicPreviousChunk();
    void * GetPhysicalNextChunk();
    void * GetPhysicalPreviousChunkFoot();
    void FlushToMemory(bool isSingleLinkList = false);
public:
    static void * GetChunkByNode(CLSingleLinkListNode *pSingleNode);
    static void * GetChunkByNode(CLDoubleLinkListNode *pDoubleNode);
    static void Split(const unsigned long ulNewChunkSize,CLChunk & rOldChunk,CLChunk & rRestChunk);
    static void Merge(CLChunk & rPreviousChunk,CLChunk & rNextChunk);
    static void AppendToSingleLinkList(CLChunk & rPreviousChunk,CLChunk & rCurrentChunk);
    static void RemoveFromSingleLinkList(CLChunk & rPreviousChunk);
    static void AppendToDoubleLinkList(CLChunk & rPreviousChunk,CLChunk & rCurrentChunk);
    static void RemoveFromDoubleLinkList(CLChunk & rCurrentChunk);
};
#endif //MALLOC_3_CPP_CLCHUNK_H
