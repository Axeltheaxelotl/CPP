/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:54:14 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 18:48:18 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  La conversion des types scalaire consiste a transformer une
    variable d'un type compatible. Par exemple, convertir un
    entier (int) en un flottant (float) ou vice-versa. il existe
    deux types */

#include "ScalarConverter.hpp"
#include "Conversion.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "One Argument required." << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}