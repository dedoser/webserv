/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LocationNode.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:03:45 by prautha           #+#    #+#             */
/*   Updated: 2021/07/19 17:03:46 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATIONNODE_HPP
#define LOCATIONNODE_HPP
#include <iostream>
#include <string>
#include <vector>

class LocationNode
{
private:
    std::vector<std::string>    methods;
    std::string                 root;
    std::string                 index;
    bool                        autoindex;
    int                         maxBody;
    std::string                 cgi;
public:
    LocationNode();
    ~LocationNode();
};

#endif
