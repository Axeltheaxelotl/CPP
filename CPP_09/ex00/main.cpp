/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:01:09 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 21:01:10 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool isValidDate(const std::string& date)
{
    (void)date;
    return true;
}

bool isValidValue(const std::string& value)
{
    (void)value;
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc("bitcoin_database.csv");

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
            valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r\f\v"));

            if (!isValidDate(date) || !isValidValue(valueStr))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            std::stringstream valueStream(valueStr);
            float value;
            valueStream >> value;

            if (value < 0 || value > 1000)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            float rate = btc.getExchangeRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
    }
    return 0;
}
