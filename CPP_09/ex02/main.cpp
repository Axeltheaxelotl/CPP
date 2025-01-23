/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:02:20 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 21:02:21 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i)
    {
        int num = std::atoi(argv[i]);
        if (num < 0)
        {
            std::cerr << "Error: Invalid input" << std::endl;
            return 1;
        }
        sequence.push_back(num);
    }

    PmergeMe pmergeMe;
    pmergeMe.sortAndDisplay(sequence);

    return 0;
}
