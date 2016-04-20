//
// Created by mq on 16-4-9.
//

#include "../include/CLChunk.h"
#include "../include/define.h"
#include <assert.h>

CLChunk::CLChunk():
m_pvChunk(),
m_headOrFoot(),
m_doubleListNode()
{

}

CLChunk::CLChunk(void * pvChunk):
m_pvChunk(pvChunk),
m_headOrFoot(pvChunk),
m_singleListNode(pvChunk),
m_doubleListNode(pvChunk)
{

}

CLChunk::CLChunk(void * pvChunk, unsigned long ulChunkSize):
m_pvChunk(pvChunk),
m_headOrFoot(pvChunk,ulChunkSize),
m_singleListNode(pvChunk),
m_doubleListNode(pvChunk)
{

}

CLChunk::~CLChunk()
{

}

void * CLChunk::GetHead()
{
    if(!m_pvChunk)
    {
        return nullptr;
    }
    return m_pvChunk;
}

void * CLChunk::GetFoot()
{
    if(!m_pvChunk)
    {
        return nullptr;
    }
    return reinterpret_cast<void *>(reinterpret_cast<unsigned long>(m_pvChunk) + m_headOrFoot.GetChunkSize() - PER_CONTROL_UNIT_SIZE);
}

void * CLChunk::GetNextNodeAddress()
{
    if(!m_pvChunk)
    {
        return nullptr;
    }
    return reinterpret_cast<void *>(reinterpret_cast<unsigned long>(m_pvChunk) + PER_CONTROL_UNIT_SIZE);
}

void * CLChunk::GetPreviousNodeAddress()
{
    if(!m_pvChunk)
    {
        return nullptr;
    }
    return reinterpret_cast<void *>(reinterpret_cast<unsigned long>(m_pvChunk) + 2*PER_CONTROL_UNIT_SIZE);
}

void CLChunk::SetChunkPointer(void * pvChunk)
{
    this->m_pvChunk = pvChunk;
}

void CLChunk::SetSize(unsigned long ulSize)
{
    this->m_headOrFoot.SetChunkSize(ulSize);
    m_headOrFoot.FlushToMemory(GetHead());
    m_headOrFoot.FlushToMemory(GetFoot());
}

void CLChunk::SetExistStatus(EMExistStatus status)
{
    this->m_headOrFoot.SetExistStatus(status);
    m_headOrFoot.FlushToMemory(GetHead());
    m_headOrFoot.FlushToMemory(GetFoot());
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

void * CLChunk::GetLogicNextChunkBySingleLinkList()
{
    return GetChunkByNode(m_singleListNode.GetNextNode());
}

void * CLChunk::GetLogicNextChunkByDoubleLinkList()
{
    return GetChunkByNode(m_doubleListNode.GetNextNode());
}

void * CLChunk::GetLogicPreviousChunk()
{
    return GetChunkByNode(m_doubleListNode.GetPreviousNode());
}

void * CLChunk::GetPhysicalNextChunk()
{
    unsigned long ulNextChunkHead = reinterpret_cast<unsigned long>(m_pvChunk) + m_headOrFoot.GetChunkSize();
    return reinterpret_cast<void *>(ulNextChunkHead);
}

void * CLChunk::GetPhysicalPreviousChunkFoot()
{
    unsigned long ulPreviousChunkFoot = reinterpret_cast<unsigned long>(m_pvChunk) - PER_CONTROL_UNIT_SIZE;
    return reinterpret_cast<void *>(ulPreviousChunkFoot);
}
//TODO complete this function
void CLChunk::FlushToMemory(bool isSingleLinkList)
{
    if(m_pvChunk != nullptr)
    {
        if(isSingleLinkList)
    }
}

void * CLChunk::GetChunkByNode(CLSingleLinkListNode *pSingleNode)
{
    unsigned long ulOffset = GET_OFFSET(CLChunk,m_singleListNode);
    return reinterpret_cast<void *>(static_cast<unsigned long>(pSingleNode) - ulOffset);
}

void * CLChunk::GetChunkByNode(CLDoubleLinkListNode *pDoubleNode)
{
    unsigned long ulOffset = GET_OFFSET(CLChunk,m_doubleListNode);
    return reinterpret_cast<void *>(static_cast<unsigned long>(pDoubleNode) - ulOffset);
}

void CLChunk::Split(const unsigned long ulNewChunkSize,CLChunk & oldChunk,CLChunk & rRestChunk)
{
    assert(ulNewChunkSize < oldChunk.GetSize() + MIN_ALLOCATE_BLOCK_SIZE);

    oldChunk.SetSize(ulNewChunkSize);

    rRestChunk.SetChunkPointer(oldChunk.GetPhysicalNextChunk());
    rRestChunk.SetSize(oldChunk.GetSize() - ulNewChunkSize);
    rRestChunk.SetExistStatus(FREE);
}

void CLChunk::Merge(CLChunk & rPreviousChunk,CLChunk & rNextChunk)
{
    assert(rPreviousChunk.GetPhysicalNextChunk() == rNextChunk.GetChunkPointer());

    rPreviousChunk.SetSize(rPreviousChunk.GetSize() + rNextChunk.GetSize());
    rNextChunk.SetChunkPointer(NULL);
    rNextChunk.SetSize(NULL);
}

void CLChunk::AppendToSingleLinkList(CLChunk & rPreviousChunk,CLChunk & rCurrentChunk)
{
    CLSingleLinkListNode::AppendNextNode(rPreviousChunk.m_singleListNode,rCurrentChunk.m_singleListNode);
    rPreviousChunk.m_singleListNode.FlushToMemory(rPreviousChunk.GetNextNodeAddress());
    rCurrentChunk.m_singleListNode.FlushToMemory(rCurrentChunk.GetNextNodeAddress());
}

void CLChunk::RemoveFromSingleLinkList(CLChunk & rPreviousChunk)
{
    CLChunk currentChunk(rPreviousChunk.GetLogicNextChunkBySingleLinkList());
    CLSingleLinkListNode::RemoveFromList(rPreviousChunk.m_singleListNode,currentChunk.m_singleListNode);
    rPreviousChunk.m_singleListNode.FlushToMemory(rPreviousChunk.GetNextNodeAddress());
    currentChunk.m_singleListNode.FlushToMemory(currentChunk.GetNextNodeAddress());
}

void CLChunk::AppendToDoubleLinkList(CLChunk & rPreviousChunk,CLChunk & rCurrentChunk)
{
    CLChunk nextChunk(rPreviousChunk.GetLogicNextChunkByDoubleLinkList());
    CLDoubleLinkListNode::AppendToList(rPreviousChunk.m_doubleListNode,rCurrentChunk.m_doubleListNode,nextChunk.m_doubleListNode);
    rPreviousChunk.FlushToMemory(false);
    rCurrentChunk.FlushToMemory(false);
    nextChunk.FlushToMemory(false);
}

void CLChunk::RemoveFromDoubleLinkList(CLChunk & rCurrentChunk)
{
    CLChunk previousChunk(rCurrentChunk.GetLogicPreviousChunk());
    CLChunk nextChunk(rCurrentChunk.GetLogicNextChunkByDoubleLinkList());
    CLDoubleLinkListNode::RemoveFromList(previousChunk.m_doubleListNode,rCurrentChunk.m_doubleListNode,&nextChunk.m_doubleListNode);
}