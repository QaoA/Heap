//
// Created by mq on 16-4-20.
//

#include "../include/CLSingleLinkListChunk.h"

CLSingleLinkListChunk::CLSingleLinkListChunk():
        m_pvNextChunk(nullptr),
        CLChunk()
{
}

CLSingleLinkListChunk::CLSingleLinkListChunk(void * pvChunk):
        m_pvNextChunk(CountAddress(pvChunk,PER_CONTROL_UNIT_SIZE)),
        CLChunk(pvChunk)
{
}

CLSingleLinkListChunk::CLSingleLinkListChunk(void * pvChunk,EMExistStatus emChunkStatus,unsigned long ulChunkSize):
m_pvChunk(pvChunk),
CLChunk(pvChunk,ulChunkSize,emChunkStatus)
{
}

CLSingleLinkListChunk::~CLSingleLinkListChunk()
{
}

void * CLSingleLinkListChunk::GetNexChunkAddress()
{
    if(m_pvChunk)
    {
        return nullptr;
    }

    return CountAddress(m_pvChunk,PER_CONTROL_UNIT_SIZE);
}

void CLSingleLinkListChunk::FlushToMemory()
{
    if(!m_pvChunk)
    {
        return;
    }

    unsigned long ulHeadData = m_headOrFoot.GetPackedData();
    PutData(GetHead(),ulHeadData);
    PutData(GetFoot(),ulHeadData);
    PutData(GetNexChunkAddress(), reinterpret_cast<unsigned long>(m_pvNextChunk));
}

void CLSingleLinkListChunk::SetStatus(EMExistStatus status)
{
    m_headOrFoot.SetExistStatus(status);
    FlushToMemory();
}

void * CLSingleLinkListChunk::GetLogicNextChunk()
{
    if(m_pvChunk)
    {
        return nullptr;
    }

    return m_pvNextChunk;
}

void CLSingleLinkListChunk::AppendNode(CLSingleLinkListChunk & rPreviousChunk,CLSingleLinkListChunk & rNewNode)
{
    void * pvNextNode = rPreviousChunk.m_pvNextChunk;

    rPreviousChunk.m_pvNextChunk = rNewNode.m_pvChunk;
    rNewNode.m_pvNextChunk = pvNextNode;

    rPreviousChunk.FlushToMemory();
    rNewNode.FlushToMemory();
}

void * CLSingleLinkListChunk::RemoveNode(CLSingleLinkListChunk & rPreviousChunk)
{
    void * pvNextNode = rPreviousChunk.m_pvNextChunk;
    if(!pvNextNode)
    {
        return nullptr;
    }

    CLSingleLinkListChunk nextNode(pvNextNode);
    void * pvNewNextNode = nextNode.m_pvNextChunk;
    nextNode.m_pvNextChunk = nullptr;
    rPreviousChunk.m_pvNextChunk = pvNewNextNode;

    rPreviousChunk.FlushToMemory();
    nextNode.FlushToMemory();

    return pvNextNode;
}