//
// Created by mq on 16-4-9.
//
#include "../include/SLHeadOrFoot.h"
#include "../include/define.h"

#include <string.h>

SLHeadOrFoot::SLHeadOrFoot():
m_emChunkStatus(FREE),
m_ulChunkSize(2*PER_CONTROL_UNIT_SIZE)
{
}

SLHeadOrFoot::SLHeadOrFoot(void * pvChunkHeadOrFoot):
m_emChunkStatus(reinterpret_cast<EMExistStatus >((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) & (0x1 << ALIGN_BIT_LENGTH))),
m_ulChunkSize((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) >> ALIGN_BIT_LENGTH)
{
}

SLHeadOrFoot::SLHeadOrFoot(unsigned long ulChunkSize,EMExistStatus emStatus):
m_emChunkStatus(emStatus),
m_ulChunkSize(ulChunkSize)
{
}

void SLHeadOrFoot::SetExistStatus(EMExistStatus emStatus)
{
    this->m_emChunkStatus = emStatus;
}

void SLHeadOrFoot::SetChunkSize(unsigned long ulChunkSize)
{
    this->m_ulChunkSize = ulChunkSize;
}

EMExistStatus SLHeadOrFoot::GetExistStatus()
{
    return m_emChunkStatus;
}

unsigned long SLHeadOrFoot::GetChunkSize()
{
    return this->m_ulChunkSize;
}

unsigned long SLHeadOrFoot::GetPackedData()
{
    return (m_ulChunkSize & ~(0x1 << ALIGN_BIT_LENGTH)) & m_emChunkStatus;
}

