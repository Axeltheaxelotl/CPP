/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:45:11 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 13:45:12 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
    try 
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;
        alice.decrementGrade();
        std::cout << alice << std::endl;
        alice.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
