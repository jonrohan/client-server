# Client & Server in C/C++

This programming assignment consists of two simple programs: a client and a server. This will provide a service similar to the Daytime Service that is implemented in systems with TCP/IP protocol suite. Requirements for both the client and the server are given below:
1. Write a TCP based client program in C/C++ on either UNIX or Win32 system that queries a TCP daytime server at port 13 on a user-specified remote host. The program must have the following features:
o The user must be able to specify the remote host's address in the form of its name or dotted IP address from the command line (both are valid forms of addressing).
o The client program must output the local host's name/address.
o The client program must output the local socket's port number after the connection with
the remote host is established.
o The client program must output the remote host's name/address (as specified by the
user) and the daytime data returned by the server.
2. Write a TCP based server program in C/C++ on either UNIX or Win32 system that binds to the daytime service port (port 13) and grants TCP based Daytime Clients access to the TCP daytime service. This program loops indefinitely, accepts connection request from TCP based Daytime Clients, gets the next TCP client, and displays the connection details. Once connected it will send current date-time out to the user. Finally, it will flush unsent bytes, close the stream and close the connection with the client. The program must have the following features:
o The server has no command line parameters.
o The Daytime Server will display the following message after accepting a client
connection “Received request from Client:” which must be followed by the client IP
address and the port number.
o Once the daytime information is sent out to the client the server will close the
connection with that client.
Since the daytime is a very simple protocol it will be sufficient to implement the TCP daytime server as a single threaded server (you may wish to implement a multithreaded server for concurrent client connections). The server program will continue to run indefinitely (CTRL+C on windows to terminate) and accept any new client connection. Once the day-time is received the client will print it out to the standard output and terminate. If the default daytime server is running (at port 13) on a remote host the client program should be able to connect to the remote host and query the server which will send the current day-time to the client.
Your programs should check for errors at all critical points (memory allocation, file and socket I/O calls, etc.).