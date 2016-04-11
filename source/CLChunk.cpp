//
// Created by mq on 16-4-9.
//

#include "../include/CLChunk.h"
#include "../include/define.h"
#include <assert.h>


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

CLChunk::~CLChunk()
{
    FlushToMemory();
}

void CLChunk::SetChunkPointer(void * pvChunk)
{
    this->m_pvChunk = pvChunk;
}

void CLChunk::SetSize(unsigned long ulSize)
{
    this->m_headOrFoot.SetChunkSize(ulSize);
}

void CLChunk::SetExistStatus(EMExistStatus status)
{
    this->m_headOrFoot.SetExistStatus(status);
}

void * CLChunk::GetChunkPointer()
{
    return m_pvChunk;
}

unsigned long CLChunk::GetSize()
{
    return m_headOrFoot.GetChunkSize();
}

EMExistStatus CLChunk::GetExistStatus()
{
    return m_headOrFoot.GetExistStatus();
}

void * CLChunk::GetPysicalNextChunk()
{
    unsigned long ulNextChunkHead = static_cast<unsigned long>(m_pvChunk) + m_headOrFoot.GetChunkSize();
    return static_cast<void *>(ulNextChunkHead);
}

void * CLChunk::GetPysicalPreviousChunkFoot()
{
    unsigned long ulPreviousChunkFoot = static_cast<unsigned long>(m_pvChunk) - PER_CONTROL_UNIT_SIZE;
    return static_cast<void *>(ulPreviousChunkFoot);
}
//TODO complete this function
void CLChunk::FlushToMemory()
{
    if(m_pvChunk != NULL)
    {

    }
}

static void CLChunk::Split(const unsigned long ulNewChunkSize,CLChunk & oldChunk,CLChunk & rRestChunk)
{
    assert(ulNewChunkSize < oldChunk.GetSize() + MIN_ALLOCATE_BLOCK_SIZE);

    oldChunk.SetSize(ulNewChunkSize);

    rRestChunk.SetChunkPointer(oldChunk.GetPysicalNextChunk());
    rRestChunk.SetSize(oldChunk.GetSize() - ulNewChunkSize);
    rRestChunk.SetExistStatus(FREE);
}

static void CLChunk::Merge(CLChunk & rPreviousChunk,CLChunk & rNextChunk)
{
    assert(rPreviousChunk.GetPysicalNextChunk() == rNextChunk.GetChunkPointer());

    rPreviousChunk.SetSize(rPreviousChunk.GetSize() + rNextChunk.GetSize());
    rNextChunk.SetChunkPointer(NULL);
    rNextChunk.SetSize(NULL);
}

static void CLChunk::RemoveFromDoubleLinkList()
{

}