/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:54:21 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 17:39:33 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Conversion.hpp"

void ScalarConverter::convert(const std::string& literal)
{
    try
    {
        Conversion conversion(literal);
    }
    catch(const Conversion::ErrorException& e)
    {
        std::cerr << e.what() << std::endl;
    }
}