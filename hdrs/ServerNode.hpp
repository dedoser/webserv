/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 17:03:32 by prautha           #+#    #+#             */
/*   Updated: 2021/07/19 17:03:36 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVERNODE_HPP
#define SERVERNODE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "LocationNode.hpp"

class ServerNode
{
private:
    unsigned short              listen;
    std::string                 error_page;
    std::string                 server_name;
    std::vector<LocationNode>   locations;
public:
    ServerNode();
    ~ServerNode();
};

#endif
