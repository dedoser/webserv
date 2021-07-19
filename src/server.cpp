/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:13:52 by fignigno          #+#    #+#             */
/*   Updated: 2021/07/19 16:56:15 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Server::setPort(const std::string &port) {
	_port = port;
}

void	Server::addServerName(const std::string &name) {
	_server_names.push_back(name);
}

const std::string	&Server::getPort() const {
	return (_port);
}

const std::string	&Server::getServerName(int num) const {
	if (num >= (int)_server_names.size())
		throw std::exception();
	return (_server_names[num]);
}

size_t	Server::getSizeOfNames() const {
	return (_server_names.size());
}
