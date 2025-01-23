/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:54:21 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 20:54:22 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <iomanip>

void ScalarConverter::convert(const std::string& literal)
{
    char* end;
    errno = 0;

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }

    long i = std::strtol(literal.c_str(), &end, 10);
    if (errno == 0 && *end == '\0' && i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
    {
        std::cout << "char: " << (std::isprint(i) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
        return;
    }

    double d = std::strtod(literal.c_str(), &end);
    if (errno == 0 && (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
    {
        if (std::isnan(d) || std::isinf(d))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            std::cout << "char: " << (std::isprint(static_cast<int>(d)) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
