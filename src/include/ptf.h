/**
 * PTF Package Transfer Framework
 * See LICENSE at the project root dir for copyright information.
 * YaoSiHai 82828068 at qq.com
 */

#ifndef PTF_H
#define PTF_H
#include "list_head.h"
#define USS_PTF_API_VERSION_0 0

typedef struct uss_ptf
{
    int version;
    int (*read)();
    int (*write)();
} uss_ptf_t;


#endif
