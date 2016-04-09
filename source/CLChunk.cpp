//
// Created by mq on 16-4-9.
//

#include "../include/CLChunk.h"


CLChunk::CLChunk(void * pvChunk):
m_pvChunk(pvChunk),
m_headOrFoot(pvChunk)
{

}

CLChunk::CLChunk(void * pvChunk, unsigned long ulChunkSize):
m_pvChunk(pvChunk),
m_headOrFoot(ulChunkSize)
{

}