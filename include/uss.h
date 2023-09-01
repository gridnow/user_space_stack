/**
 * The User Space Stack for ultra-low latency and large throughput applications.
 * See LICENSE at the project root dir for copyright information.
 * YaoSiHai 82828068 at qq.com
 */

#ifndef User_Space_Stack_H
#define User_Space_Stack_H

#include <sys/socket.h>

/**
 * User Space Stack (USS) Instance
 *
 * USS实例包含所有必要的数据、控制逻辑用来实现延迟和吞吐的优化功能。
 * 在一个USS实例中可以创建多个链接用于通讯，本层是封装层，调用者无需关心其中内容。
 */
typedef void *uss_instance_t;

/**
 * A connection with with remote peer
 *
 * “链接”表示与对端进行可靠的、高速的、低延迟的交互的数据流。
 * 本层为封装层接口，调用者无需关心其中内容。
 */
typedef void *uss_conn_t;

/**
 * The link type of the connection
 */
typedef enum uss_link_type
{
    /* 常规软件通讯层，USS尽可能减少数据拷贝、减少OS的使用来降低延迟 */
    USS_LINK_TYPE_SOFTWARE,

    /* 如果机器上具备RDMA 的网卡，可以在创建链接时指定该链接方式，通过IBV 方式操作网卡，从而彻底通过bypass kernel 的方式提高吞吐降低延迟 */
    USS_LINK_TYPE_RDMA,

    /* 原理同RDMA，只是采用Intel 的DPDK库操作网卡 */
    USS_LINK_TYPE_DPDK,
} uss_link_type_t;

/**
 * Create an instance of USS
 */
uss_instance_t uss_create();

/**
 * Create a connection that support reliable data transmission.
 */
int uss_connection_create(uss_instance_t *uss, struct sockaddr *addr, uss_link_type_t link_type);

#endif /* User_Space_Stack_H */
