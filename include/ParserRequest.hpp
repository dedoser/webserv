/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserRequest.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fignigno <fignigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:13:33 by fignigno          #+#    #+#             */
/*   Updated: 2021/07/19 19:47:10 by fignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_REQUEST_HPP
#define PARSER_REQUEST_HPP

#include <string>
#include "Request.hpp"

class ParserRequest
{
private:
	enum class state {
		METHOD,
		URI,
		PROTOCOL,
		HEADER,
		BODY,
		READY
	};
	std::string		_buff;
	std::string		_curStr;
	int				_contentLen;
	state			_state;
	bool			_hasBody;
	bool			_isChunked;
public:
	ParserRequest();
	~ParserRequest();
	void	parseStr(const std::string &)
};


#endif
