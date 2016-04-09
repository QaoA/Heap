//
// Created by mq on 16-4-9.
//
#include "../include/SLHeadOrFoot.h"
#include "../include/define.h"

#include <string.h>

SLHeadOrFoot::SLHeadOrFoot(void* chunkHeadOrFoot)
{
    memcpy(this,chunkHeadOrFoot, sizeof(SLHeadOrFoot));
}

SLHeadOrFoot::SLHeadOrFoot(SLHeadOrFoot& headOrFoot):
        m_ulChunkSize(headOrFoot.m_ulChunkSize),
        m_undefined(0),
        m_emChunkStatus(headOrFoot.m_emChunkStatus)
{

}

SLHeadOrFoot::SLHeadOrFoot(unsigned long chunkSize,EMExistStatus status):
        m_ulChunkSize(chunkSize),
        m_undefined(0),
        m_emChunkStatus(status)
{

}