/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseConfig.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:47:00 by prautha           #+#    #+#             */
/*   Updated: 2021/07/18 20:47:01 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSECONFIG_HPP
#define PARSECONFIG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "ServerNode.hpp"

// Color
#define REDCOLOR "\033[0;31m"
#define NOTCOLOR "\033[0m"

class ParseConfig
{
private:
    std::vector<ServerNode> servers;

public:
// Constructors
    ParseConfig();
    ~ParseConfig();

// ParseConfigException
    class ParseConfigException : public std::exception
    {
    private:
        short _num_err;
        ParseConfigException();
    public:
        ParseConfigException(short num_err);
        const char *what() const throw();
    };

// Methods
    void getData(std::string file_name);
};

#endif