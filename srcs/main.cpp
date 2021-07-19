/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prautha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:46:45 by prautha           #+#    #+#             */
/*   Updated: 2021/07/18 20:46:46 by prautha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParseConfig.hpp"

int main(int argc, char **argv)
{
    string address_file = "checkfile.txt";

    try
    {
        ParseConfig parser;

        if (argc > 2)
            throw ParseConfig::ParseConfigException(1);
        else if (argc == 2)
        {
            address_file = argv[1];
            parser.getData(address_file);
        }
        else
            parser.getData(address_file);
    }
    catch(const exception &e)
    {
        cerr << e.what() << NOTCOLOR << endl;
    }

    return 0;
}
