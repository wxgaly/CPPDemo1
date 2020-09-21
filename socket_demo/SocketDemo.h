/*
 * @Author: Gary Wang
 * @Date: 2020-09-18 15:28:35
 * @LastEditors: Gary Wang
 * @LastEditTime: 2020-09-21 10:51:30
 * @Description: socket demo
 */
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

/**
* AF_INET: IPv4 protocol
* AF_INET6: IPv6 protocol
* SOCK_STREAM: TCP
* SOCK_DGRAM: UDP
*/
class ServerSocketDemo
{
private:
    /* data */
public:
    ServerSocketDemo(/* args */);
    ~ServerSocketDemo();
    void test();
    void testServer();
    void testClinet();
};

