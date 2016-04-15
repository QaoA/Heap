//
// Created by mq on 16-4-9.
//
#include "../include/SLHeadOrFoot.h"
#include "../include/define.h"

#include <string.h>

SLHeadOrFoot::SLHeadOrFoot():
ILMemoryFlusher(nullptr),
m_emChunkStatus(FREE),
m_ulChunkSize(NULL),
m_undefined(0)
{
}

SLHeadOrFoot::SLHeadOrFoot(void * pvChunkHeadOrFoot):
ILMemoryFlusher(pvChunkHeadOrFoot),
m_ulChunkSize((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) >> ALIGN_BIT_LENGTH),
m_emChunkStatus(reinterpret_cast<EMExistStatus >((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) & (0x1 << ALIGN_BIT_LENGTH))),
m_undefined(0)
{
//    m_ulChunkSize = (*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) >> ALIGN_BIT_LENGTH;
//    m_emChunkStatus = reinterpret_cast<EMExistStatus >((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) & (0x1 << ALIGN_BIT_LENGTH));
//    m_undefined = 0;
}

SLHeadOrFoot::SLHeadOrFoot(void * pvChunkHeadOrFoot,unsigned long ulChunkSize = 0,EMExistStatus emStatus = FREE):
ILMemoryFlusher(pvChunkHeadOrFoot),
m_ulChunkSize(ulChunkSize),
m_emChunkStatus(emStatus),
m_undefined(0)
{

}

void SLHeadOrFoot::SetExistStatus(EMExistStatus emStatus)
{
    this->m_emChunkStatus = emStatus;
}

void SLHeadOrFoot::SetChunkSize(unsigned long ulChunkSize)
{
    this->m_ulChunkSize = ulChunkSize >> ALIGN_BIT_LENGTH;
}

EMExistStatus SLHeadOrFoot::GetExistStatus()
{
    return m_emChunkStatus;
}

unsigned long SLHeadOrFoot::GetChunkSize()
{
    return this->m_ulChunkSize << ALIGN_BIT_LENGTH;
}

void SLHeadOrFoot::FlushToMemory()
{
    ILMemoryFlusher
}
