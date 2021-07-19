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
#include <list>
#include <exception>

// Color:
#define REDCOLOR "\033[0;31m"
#define NOTCOLOR "\033[0m"

// Locations`s node
typedef struct
{
    // method          GET POST;
    // root            /content/website2;
    // index           home_page/index.html;
    // autoindex       off;
    // maxBody         5;
    //         redirect        http://127.0.0.1:8080/;
    //                                 cgi             ./python_upload.py;
}  locationNode;

// Server`s node
typedef struct
{
    unsigned short listen;
    std::string error_page;
    std::string server_name;
    // std::vector<local> arr;
}  serverNode;

class ParseConfig
{
private:
    // string _file_name;
public:
// Constructors:
    ParseConfig();
    ~ParseConfig();

// ParseConfigException:
    class ParseConfigException : public std::exception
    {
    private:
        short _num_err;
        ParseConfigException();
    public:
        ParseConfigException(short num_err);
        const char *what() const throw();
    };

// Methods:
    void getData(std::string file_name);
};

#endif