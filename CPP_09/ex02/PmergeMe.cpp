/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:02:25 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 21:02:26 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}

void PmergeMe::sortAndDisplay(std::vector<int>& sequence)
{
    std::vector<int> vecSequence = sequence;
    std::list<int> listSequence(sequence.begin(), sequence.end());

    displaySequence("Before: ", sequence);

    measureAndDisplay("std::vector", vecSequence);
    measureAndDisplay("std::list", listSequence);
}

void PmergeMe::mergeInsertSort(std::vector<int>& sequence)
{
    if (sequence.size() <= 1) return;

    // Step 1: Group elements into pairs
    std::vector<int> largerElements;
    for (size_t i = 0; i < sequence.size() / 2; ++i) {
        if (sequence[2 * i] > sequence[2 * i + 1]) {
            largerElements.push_back(sequence[2 * i]);
            sequence[2 * i] = sequence[2 * i + 1];
        } else {
            largerElements.push_back(sequence[2 * i + 1]);
        }
    }

    // Step 2: Recursively sort the larger elements
    mergeInsertSort(largerElements);

    // Step 3: Insert the smaller elements into the sorted sequence
    for (size_t i = 0; i < sequence.size() / 2; ++i) {
        std::vector<int>::iterator it = std::lower_bound(largerElements.begin(), largerElements.end(), sequence[2 * i]);
        largerElements.insert(it, sequence[2 * i]);
    }

    // Step 4: Handle the last element if the size is odd
    if (sequence.size() % 2 != 0) {
        std::vector<int>::iterator it = std::lower_bound(largerElements.begin(), largerElements.end(), sequence.back());
        largerElements.insert(it, sequence.back());
    }

    sequence = largerElements;
}

void PmergeMe::mergeInsertSort(std::list<int>& sequence)
{
    if (sequence.size() <= 1) return;

    // Step 1: Group elements into pairs
    std::list<int> largerElements;
    std::list<int>::iterator it = sequence.begin();
    while (it != sequence.end()) {
        std::list<int>::iterator first = it++;
        if (it == sequence.end()) break;
        std::list<int>::iterator second = it++;
        if (*first > *second) {
            largerElements.push_back(*first);
            *first = *second;
        } else {
            largerElements.push_back(*second);
        }
    }

    // Step 2: Recursively sort the larger elements
    mergeInsertSort(largerElements);

    // Step 3: Insert the smaller elements into the sorted sequence
    it = sequence.begin();
    for (std::list<int>::iterator largerIt = largerElements.begin(); largerIt != largerElements.end(); ++largerIt) {
        it = std::lower_bound(it, sequence.end(), *largerIt);
        sequence.insert(it, *largerIt);
    }

    // Step 4: Handle the last element if the size is odd
    if (sequence.size() % 2 != 0) {
        std::list<int>::iterator pos = std::lower_bound(sequence.begin(), sequence.end(), sequence.back());
        sequence.insert(pos, sequence.back());
    }

    // Remove the original elements that were replaced
    sequence.erase(std::unique(sequence.begin(), sequence.end()), sequence.end());
}

template<typename Container>
void PmergeMe::displaySequence(const std::string& message, const Container& sequence)
{
    std::cout << message;
    for (typename Container::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe::measureAndDisplay(const std::string& containerName, Container& sequence)
{
    std::clock_t start = std::clock();
    mergeInsertSort(sequence);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

    displaySequence("After: ", sequence);
    std::cout << "Time to process a range of " << sequence.size() << " elements with " << containerName << ": " << duration << " us" << std::endl;
}
