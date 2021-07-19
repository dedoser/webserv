#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server.hpp"

#define BUFF_SIZE 1024

int main() {
	Server	server;
	int	sock_fd;
	struct sockaddr_in addr;
	int connect;

	server.setPort("8080");
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		std::cerr << "Error1\n";
		return (0);
	}
	int opt = 1;
	if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
		std::cerr << "Setsockopt error" << std::endl;
		exit(EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(sock_fd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
		std::cerr << "Error2" << strerror(errno) << "\n";
		return (0);
	}
	if (listen(sock_fd, 10) == -1) {
		std::cerr << "Error3\n";
		return (0);
	}
	socklen_t	addrlen = sizeof(addr);
	if ((connect = accept(sock_fd, (struct sockaddr *) &addr, &addrlen)) == -1) {
		std::cerr << "Error\n";
		return (0);
	}
	char	buffer[BUFF_SIZE + 1];
	while (true) {

		int	count = recv(connect, buffer, BUFF_SIZE, 0);
		if (count == -1) {
			std::cerr << "Recv error" << std::endl;
			continue;
		}
		if (count == 0 || (count == 1 && buffer[0] == 4)) {
			close(connect);
		}
		buffer[count] = '\0';
		
	}
	std::string response = "Good talking to you\n";
	send(connect, response.c_str(), response.size(), 0);
	close(connect);
	close(sock_fd);
}
