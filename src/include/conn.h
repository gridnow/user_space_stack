/**
 * User space stack
 * See LICENSE at the project root dir for copyright information.
 * YaoSiHai 82828068 at qq.com
 */

#ifndef CONNECTION_H
#define CONNECTION_H

#include "list_head.h"
#include "ptf.h"
#include "conges.h"
#include "reliable.h"

typedef struct uss_connection
{
    // IO layer
    uss_ptf_t ptf;

    // congestion control layer

    // reliable control layer
} uss_connection_t;

#endif

