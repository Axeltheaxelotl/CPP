/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:02:28 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 21:02:29 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe();
        void sortAndDisplay(std::vector<int>& sequence);
    
    private:
        void mergeInsertSort(std::vector<int>& sequence);
        void mergeInsertSort(std::list<int>& sequence);
        template<typename Container>
        void displaySequence(const std::string& message, const Container& sequence);
        template<typename Container>
        void measureAndDisplay(const std::string& containerName, Container& sequence);
};

#endif
