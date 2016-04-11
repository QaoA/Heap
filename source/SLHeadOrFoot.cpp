//
// Created by mq on 16-4-9.
//
#include "../include/SLHeadOrFoot.h"
#include "../include/define.h"

#include <string.h>

SLHeadOrFoot::SLHeadOrFoot(void* pvChunkHeadOrFoot)
{
    memcpy(this,pvChunkHeadOrFoot, sizeof(SLHeadOrFoot));
}

SLHeadOrFoot::SLHeadOrFoot(SLHeadOrFoot& rHeadOrFoot):
        m_ulChunkSize(rHeadOrFoot.m_ulChunkSize),
        m_undefined(0),
        m_emChunkStatus(rHeadOrFoot.m_emChunkStatus)
{

}

SLHeadOrFoot::SLHeadOrFoot(unsigned long ulChunkSize,EMExistStatus emStatus):
        m_ulChunkSize(ulChunkSize),
        m_undefined(0),
        m_emChunkStatus(emStatus)
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

void SLHeadOrFoot::FlushToMemory(void * pvAddress)
{
    memcpy(pvAddress,this,sizeof(SLHeadOrFoot));
}