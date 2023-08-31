# user_space_stack
The user space network stack is to provide high-speed and large throw-put network transfer capability for critical circumstances such as High Frequent Stock Exchange、Large scale computing and Market Maker(which needs Ultra low latency network lane to buy or sell BTC) etc. The main method to achieve the goal is by using bypass-kernel technology and user defined credit control algorithm,zero-copy,Software UDP-based/RDMA-based/DPDK-based package transfer,pipe-lined design and so on.

# Progress & Plan

Now we are in stage 1.

## Stage1:Package transforming framework
Package transforming framework(PTF) is used to abstract the underline network transfer capabilities.

## Stage2:Software version(UDP-based) network transfer

## Stage3:Datagram Congestion Control capability

## Stage4:Reliable transmission Control capability



# Test
In main.c we have server and client that can do high frequency network transfer and count the latency and throughput.

## Test data