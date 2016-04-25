//
// Created by mq on 16-4-20.
//

#include "../include/CLDoubleLinkListChunk.h"

CLDoubleLinkListChunk::CLDoubleLinkListChunk():
m_pvNextChunk(nullptr),
m_pvPreviousChunk(nullptr),
CLChunk()
{
}

CLDoubleLinkListChunk::CLDoubleLinkListChunk(void *pvChunk):
m_pvNextChunk(CountAddress(pvChunk,PER_CONTROL_UNIT_SIZE)),
m_pvPreviousChunk(CountAddress(pvChunk,2*PER_CONTROL_UNIT_SIZE)),
CLChunk(pvChunk)
{
}

CLDoubleLinkListChunk::CLDoubleLinkListChunk(void *pvChunk, unsigned long ulChunkSize, EMExistStatus emChunkStatus):
m_pvNextChunk(nullptr),
m_pvPreviousChunk(nullptr),
CLChunk(pvChunk,ulChunkSize,emChunkStatus)
{
}

CLDoubleLinkListChunk::~CLDoubleLinkListChunk()
{
}

void * CLDoubleLinkListChunk::GetLogicNextChunk()
{
    return m_pvNextChunk;
}

void * CLDoubleLinkListChunk::GetLogicPreviousChunk()
{
    return m_pvPreviousChunk;
}

void CLDoubleLinkListChunk::SplitChunk(unsigned long ulChunkSize,CLDoubleLinkListChunk & originChunk,CLDoubleLinkListChunk & restChunk)
{
    unsigned long originChunkSize = originChunk.GetSize();
    unsigned long ulAlignChunkSize = AlignSize(ulChunkSize);
    if((ulAlignChunkSize + MIN_ALLOCATE_CHUNK_SIZE >= originChunkSize) || !originChunk.m_pvChunk)
    {
        restChunk.m_pvChunk = nullptr;
        restChunk.m_headOrFoot.SetChunkSize(0);
        return;
    }

    unsigned long restChunkSize = originChunk.GetSize() - ulAlignChunkSize;
    originChunk.m_headOrFoot.SetChunkSize(ulAlignChunkSize);
    restChunk.m_headOrFoot.SetChunkSize(restChunkSize);
    restChunk.m_pvChunk = CountAddress(originChunk.GetChunkPointer(),ulAlignChunkSize);
    restChunk.m_headOrFoot.SetExistStatus(FREE);

    originChunk.FlushToMemory();
    restChunk.FlushToMemory();
}

CLDoubleLinkListChunk CLDoubleLinkListChunk::MergeNearChunk(CLDoubleLinkListChunk & currentChunk)
{
    void * pvPreviousChunk = currentChunk.GetPhysicalPreviousNodeAddress();
    void * pvNextChunk = currentChunk.GetPhysicalNextNodeHeadAddress();
    CLDoubleLinkListChunk previousChunk(pvPreviousChunk);
    CLDoubleLinkListChunk nextChunk(pvNextChunk);
    unsigned long chunkSize = currentChunk.GetSize();
    void * pvReturnChunk = currentChunk.m_pvChunk;
    if(previousChunk.GetStatus() == FREE || previousChunk.GetStatus() == RETURNED)
    {
        pvReturnChunk = previousChunk.m_pvChunk;
        chunkSize += previousChunk.GetSize();
        CLDoubleLinkListChunk::RemoveChunk(previousChunk);
    }
    if(nextChunk.GetSize() == FREE || nextChunk.GetSize() == RETURNED)
    {
        chunkSize += nextChunk.GetSize();
        CLDoubleLinkListChunk::RemoveChunk(nextChunk);
    }

    CLDoubleLinkListChunk returnChunk(pvReturnChunk,chunkSize,FREE);
    return returnChunk;
}

void CLDoubleLinkListChunk::AppendNewChunk(CLDoubleLinkListChunk & rPreviousChunk,CLDoubleLinkListChunk & rNewChunk)
{
    CLDoubleLinkListChunk nextChunk(rPreviousChunk.m_pvNextChunk);

    rPreviousChunk.m_pvNextChunk = rNewChunk.m_pvChunk;
    rNewChunk.m_pvPreviousChunk = rPreviousChunk.m_pvChunk;
    rNewChunk.m_pvNextChunk = nextChunk.m_pvChunk;
    nextChunk.m_pvPreviousChunk = rNewChunk.m_pvChunk;

    rPreviousChunk.FlushToMemory();
    rNewChunk.FlushToMemory();
    nextChunk.FlushToMemory();
}

void CLDoubleLinkListChunk::RemoveChunk(CLDoubleLinkListChunk & rCurrentChunk)
{
    CLDoubleLinkListChunk previousChunk(rCurrentChunk.m_pvPreviousChunk);
    CLDoubleLinkListChunk nextChunk(rCurrentChunk.m_pvNextChunk);

    previousChunk.m_pvNextChunk = nextChunk.m_pvChunk;
    nextChunk.m_pvPreviousChunk = previousChunk.m_pvChunk;
    rCurrentChunk.m_pvNextChunk = nullptr;
    rCurrentChunk.m_pvPreviousChunk = nullptr;

    previousChunk.FlushToMemory();
    nextChunk.FlushToMemory();
    rCurrentChunk.FlushToMemory();
}