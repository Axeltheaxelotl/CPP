/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:45:11 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 11:19:26 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
    try 
    {
        Bureaucrat fabio("fabio", 2);
        std::cout << fabio << std::endl;
        fabio.incrementGrade();
        std::cout << fabio << std::endl;
        fabio.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat fabio2("fabio2", 149);
        std::cout << fabio2 << std::endl;
        fabio2.decrementGrade();
        std::cout << fabio2 << std::endl;
        fabio2.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
