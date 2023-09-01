/**
 * USS
 * See LICENSE at the project root dir for copyright information.
 * YaoSiHai 82828068 at qq.com
 */
#include <stdio.h>
#include <errno.h>
#include "uss.h"

uss_instance_t uss_create()
{
    return NULL;
}

int uss_connection_create(uss_instance_t *uss, struct sockaddr *addr, uss_link_type_t link_type)
{
    return -ENOSYS;
}