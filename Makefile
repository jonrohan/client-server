client: server
	cc client.c -o client -lsocket -lnsl

server:
	cc server.c -o server -lsocket -lnsl 
