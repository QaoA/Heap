//
// Created by mq on 16-4-12.
//

#include "../include/CLAllocatedChunks.h"

CLAllocatedChunks::CLAllocatedChunks():
m_allocatedChunkHead(),
m_pvListCurrentPointer(nullptr)
{

}

CLChunk CLAllocatedChunks::GetReturnedChunk()
{
    if(m_pvListCurrentPointer)
    {
        return CLChunk();
    }

    for(;m_pvListCurrentPointer != nullptr;)
    {
        CLSingleLinkListChunk currentChunk(m_pvListCurrentPointer);
        if(currentChunk.GetStatus() == RETURNED || currentChunk.GetStatus() == FREE)
        {
            return currentChunk;
        }
        m_pvListCurrentPointer = currentChunk.GetLogicNextChunk();
    }
}

void CLAllocatedChunks::AppendChunk(CLSingleLinkListChunk & newChunk)
{
    CLSingleLinkListChunk::AppendNode(m_allocatedChunkHead,newChunk);
}

void CLAllocatedChunks::ReturnChunk(CLSingleLinkListChunk & returnChunk)
{
    returnChunk.SetStatus(RETURNED);
}