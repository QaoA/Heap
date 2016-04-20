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