/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseConfig.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:46:51 by prautha           #+#    #+#             */
/*   Updated: 2021/07/18 20:46:53 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseConfig.hpp"

// Constructors:
ParseConfig::ParseConfig() {}

ParseConfig::~ParseConfig() {}

// Methods:
void ParseConfig::getData(std::string file_name)
{
    std::string str;
    std::ifstream file(file_name);

    if (!file.is_open())
        throw ParseConfigException(2);

    for (file >> str; !file.eof(); file >> str)
    {
        std::cout << str << std::endl;
    }

}

// ParseConfigException:
ParseConfig::ParseConfigException::ParseConfigException() {};

ParseConfig::ParseConfigException::ParseConfigException(short num_err) : _num_err(num_err) {}

const char *ParseConfig::ParseConfigException::what() const throw()
{
    std::cout << REDCOLOR << "Error: ";
    switch (_num_err)
    {
    case 1:
        return ("too many arguments.");
    case 2:
        return ("file open error.");
    default:
        return ("undefined exception.");
    }
}