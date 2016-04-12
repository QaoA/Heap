//
// Created by mq on 16-4-12.
//

#ifndef MALLOC_3_CPP_TOOLFUNCTIONS_H
#define MALLOC_3_CPP_TOOLFUNCTIONS_H

template <typename ClassOrStruct,typename MemberVariable>
inline unsigned long GetOffset()
{
    return static_cast<unsigned long>(&(static_cast<ClassOrStruct *>(0) -> MemberVariable));
};

#endif //MALLOC_3_CPP_TOOLFUNCTIONS_H
