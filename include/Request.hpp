/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:59:34 by fignigno          #+#    #+#             */
/*   Updated: 2021/07/19 18:36:29 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include <utility>

class Request
{
private:
	std::string		_method;
	std::string		_path;
	std::string		_protocol;
	std::string		_body;
	std::map<std::string, std::string>	_headers;
public:
	Request();
	~Request();
	
	void	setMethod(const std::string &method);
	void	setPath(const std::string &path);
	void	setProtocol(const std::string &protocol);
	void	addToBody(char *part);
	void	addHeader(const std::string &header,
					  const std::string &value);

	const std::string&	getMethod() const;
	const std::string&	getPath() const;
	const std::string&	getProtocol() const;
	const std::string&	getBody() const;
	const std::string&	getHeaderValue(const std::string &header) const;

	bool				findHeader(const std::string &header) const;
};

#endif
