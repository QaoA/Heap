//
// Created by mq on 16-4-9.
//

#include "../include/CLChunk.h"
#include "../include/define.h"
#include <assert.h>

CLChunk::CLChunk():
m_pvChunk(nullptr),
m_headOrFoot(2*PER_CONTROL_UNIT_SIZE,FREE)
{
}

CLChunk::CLChunk(void * pvChunk):
m_pvChunk(pvChunk),
m_headOrFoot(pvChunk)
{
}

CLChunk::CLChunk(void * pvChunk, unsigned long ulChunkSize, EMExistStatus emChunkStatus):
m_pvChunk(pvChunk),
m_headOrFoot(ulChunkSize,emChunkStatus)
{

}

virtual CLChunk::~CLChunk()
{
}

unsigned long CLChunk::GetSize()
{
    return m_headOrFoot.GetChunkSize();
}

EMExistStatus CLChunk::GetStatus()
{
    return m_headOrFoot.GetExistStatus();
}

void * CLChunk::GetChunkPointer()
{
    return m_pvChunk;
}

void * CLChunk::GetHead()
{
    if(m_pvChunk)
    {
        return m_pvChunk;
    }

    return nullptr;
}

void * CLChunk::GetFoot()
{
    if(m_pvChunk)
    {
        unsigned long foot = (*reinterpret_cast<unsigned long *>(m_pvChunk) + m_headOrFoot.GetChunkSize() - PER_CONTROL_UNIT_SIZE);
        return reinterpret_cast<void *>(foot);
    }

    return nullptr;
}

void * CLChunk::GetPhysicalNextNodeHeadAddress()
{
    if(m_pvChunk)
    {
        return reinterpret_cast<void *>((*reinterpret_cast<unsigned long *>(m_pvChunk)) - PER_CONTROL_UNIT_SIZE);
    }

    return nullptr;
}

void * CLChunk::GetPhysicalPreviousNodeFootAddress()
{
    if(m_pvChunk)
    {
        return reinterpret_cast<void *>((*reinterpret_cast<unsigned long *>(m_pvChunk)) + m_headOrFoot.GetChunkSize());
    }

    return nullptr;
}

void CLChunk::PutData(void * pvAddress, unsigned long ulData)
{
    *reinterpret_cast<unsigned long *>(pvAddress) = ulData;
}

void * CLChunk::CountAddress(void * pvAddress, unsigned long ulDelta,bool bIsAdd)
{
    if(bIsAdd)
    {
        return reinterpret_cast<void *>((reinterpret_cast<unsigned long>(pvAddress)) + ulDelta);
    }

    return reinterpret_cast<void *>((reinterpret_cast<unsigned long>(pvAddress)) - ulDelta);
}