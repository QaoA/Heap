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

void CLDoubleLinkListChunk::AppenNewChunk(CLDoubleLinkListChunk & rPreviousChunk,CLDoubleLinkListChunk & rNewChunk)
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