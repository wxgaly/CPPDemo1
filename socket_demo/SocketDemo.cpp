/*
 * @Author: Gary Wang
 * @Date: 2020-09-18 15:55:30
 * @LastEditors: Gary Wang
 * @LastEditTime: 2020-09-21 10:58:03
 * @Description: file content
 */
#include "SocketDemo.h"

// #include <netdb.h>
// #include <netinet/in.h>

ServerSocketDemo::ServerSocketDemo()
{
}

ServerSocketDemo::~ServerSocketDemo()
{
}

void ServerSocketDemo::test()
{
    // testServer();
    testClinet();
}

/**
 * demo 地址：http://www.linuxhowtos.org/C_C++/socket.htm
 */
void ServerSocketDemo::testServer()
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("fd is %d \n", sockfd);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = 10001;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    // serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }
    else
    {
        printf("bind success. \n");
    }

    /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        perror("ERROR on accept");
        exit(1);
    }
    else
    {
        printf("accept socket, cli_addr is %d \n", cli_addr.sin_port);
    }

    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n", buffer);

    /* Write a response to the client */
    n = write(newsockfd, "I got your message", 18);

    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);
}

void ServerSocketDemo::testClinet()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 10002;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
    }

    server = gethostbyname("127.0.0.1");
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
    }
    
    n = write(sockfd, "我这里都挺好", 18);
    if (n < 0)
    {
        perror("ERROR writing to socket");
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
    {
        perror("ERROR reading from socket");
    }

    printf("%s\n", buffer);
    close(sockfd);
}