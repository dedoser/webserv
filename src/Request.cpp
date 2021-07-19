/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:20:23 by fignigno          #+#    #+#             */
/*   Updated: 2021/07/19 19:15:38 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

void	Request::setMethod(const std::string &method) {
	_method = method;
}

void	Request::setPath(const std::string &path) {
	_path = path;
}

void	Request::setProtocol(const std::string &protocol) {
	_protocol = protocol;
}

void	Request::addToBody(char *part) {
	_body.append(part);
}

void	Request::addHeader(const std::string &header,
						   const std::string &value) {
	_headers[header] = value;
}

const std::string&	Request::getMethod() const {
	return (_method);
}

const std::string&	Request::getPath() const {
	return (_path);
}

const std::string&	Request::getProtocol() const {
	return (_protocol);
}

const std::string&	Request::getBody() const {
	return (_body);
}

const std::string&	Request::getHeaderValue(const std::string &header) const {
	auto	it = _headers.find(header);
	if (it == _headers.end())
		throw std::exception();
	return (it->second);
}

bool	Request::findHeader(const std::string &header) const {
	auto	it = _headers.find(header);
	if (it == _headers.end())
		return (false);
	return (true);
}
