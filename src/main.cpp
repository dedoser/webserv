#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/server.hpp"

int main() {
	int	sock_fd;
	struct sockaddr_in addr;
	int connect;

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
	addr.sin_addr.s_addr = INADDR_ANY;
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
	char buffer[100];
	int bytesRead = read(connect, buffer, 100);
	buffer[bytesRead] = '\0';
	std::cout << "The message was: " << buffer;
	std::string response = "Good talking to you\n";
	send(connect, response.c_str(), response.size(), 0);
	close(connect);
	close(sock_fd);
}
