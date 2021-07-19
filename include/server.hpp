/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:57:52 by fignigno          #+#    #+#             */
/*   Updated: 2021/07/19 17:49:02 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>

class Server {
 private:
	std::string					_port;
	std::vector<std::string>	_server_names;
 public:
	void	setPort(const std::string &port);
	void	addServerName(const std::string &name);
	const std::string	&getPort() const;
	const std::string	&getServerName(int num) const;
	size_t				getSizeOfNames() const;
};

#endif