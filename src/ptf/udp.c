/**
 * PTF Package Transfer Framework
 * See LICENSE at the project root dir for copyright information.
 * YaoSiHai 82828068 at qq.com
 *
 * The UDP implementation for PTF
 */
#include <errno.h>
#include "ptf.h"

static int udp_read()
{
    return -ENOSYS;
}

static int udp_write()
{
    return -ENOSYS;
}

struct uss_ptf uss_ptf_udp = {
        .version = USS_PTF_API_VERSION_0,
        .read = udp_read,
        .write = udp_write,
};
