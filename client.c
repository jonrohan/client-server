/*
*AUTHOR: Jon Rohan
*DATE: 2.28.2005
*TITLE: client.c
*DESCRIPTION: This program will be specified an IP address in the command line
*	      and will connect to an already running server. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 1025 /*This is the port for the client server connection*/
#define MAXDATASIZE 500 // max number of bytes we can get at once

int main(int argc, char *argv[])
{
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in their_addr; // connector.s address information
	
	//***************************block of code finds the localhost IP
	char hostn[400]; //placeholder for the hostname
	char ipadd[400]; //placeholder for my IP address

	struct hostent *hostIP; //placeholder for the IP address
	
	//if the gethostname returns a name then the program will get the ip address using gethostbyname
	if((gethostname(hostn, sizeof(hostn))) == 0) 
  	{
		hostIP = gethostbyname(hostn); //the netdb.h function gethostbyname
  	}
	else
	{
    		printf("ERROR:FC4539 - IP Address not found."); //error if the hostname is not found
  	}
	//****************************************************************


	if (argc != 2)
	{
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}
	
	if ((he=gethostbyname(argv[1])) == NULL) 
	{ // get the host info
		perror("gethostbyname");
		exit(1);
	}
	
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		perror("socket");
		exit(1);
	}
	
	their_addr.sin_family = AF_INET; // host byte order
	their_addr.sin_port = htons(PORT); // short, network byte order
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(their_addr.sin_zero), 0, 8); // zero the rest of the 

	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}
	
	if ((numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) 
	{
		perror("recv");
		exit(1);
	}
	
	buf[numbytes] = 0;
	printf("\n\nLocalhost: %s\n", inet_ntoa(*(struct in_addr *)hostIP->h_addr));
	printf("Local Port: %d\n", PORT);
	printf("Remote Host: %s\n", inet_ntoa(their_addr.sin_addr));
	printf("Received daytime data: %s\n",buf);
	close(sockfd);
	return 0;
}

