//
// Created by mq on 16-4-9.
//
#include "../include/SLHeadOrFoot.h"
#include "../include/define.h"

#include <string.h>

SLHeadOrFoot::m_data::m_data(EMExistStatus emStatus, unsigned long ulChunkSize):
m_emChunkStatus(emStatus),
m_ulChunkSize(ulChunkSize),
m_undefined(0)
{
}

SLHeadOrFoot::SLHeadOrFoot():
m_data(FREE,NULL)
{
}

SLHeadOrFoot::SLHeadOrFoot(void * pvChunkHeadOrFoot):
m_data(reinterpret_cast<EMExistStatus >((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) & (0x1 << ALIGN_BIT_LENGTH))
       ,((*reinterpret_cast<unsigned long * >(pvChunkHeadOrFoot)) >> ALIGN_BIT_LENGTH))
{
}

SLHeadOrFoot::SLHeadOrFoot(void * pvChunkHeadOrFoot,unsigned long ulChunkSize = 0,EMExistStatus emStatus = FREE):
m_data(emStatus,ulChunkSize)
{

}

void SLHeadOrFoot::SetExistStatus(EMExistStatus emStatus)
{
    this->m_data.m_emChunkStatus = emStatus;
}

void SLHeadOrFoot::SetChunkSize(unsigned long ulChunkSize)
{
    this->m_data.m_ulChunkSize = ulChunkSize >> ALIGN_BIT_LENGTH;
}

EMExistStatus SLHeadOrFoot::GetExistStatus()
{
    return m_data.m_emChunkStatus;
}

unsigned long SLHeadOrFoot::GetChunkSize()
{
    return this->m_data.m_ulChunkSize << ALIGN_BIT_LENGTH;
}

void SLHeadOrFoot::FlushToMemory(void * pvWriteStartAddress)
{
    *reinterpret_cast<unsigned long *>(pvWriteStartAddress) = *reinterpret_cast<unsigned long*>(&m_data);
}
