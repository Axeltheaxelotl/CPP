#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}

void PmegeMe::sortAndDisplay(const std::vector<int>& sequence)
{
    std::vector<int> vecSequence = sequence;
    std::list<int> listSequence(sequence.begin(), sequence.end());

    displaySequence("Before: ", sequence);

    measureAndDisplayTime("std::vector", vecSequence);
    measureAndDisplayTime("std::list", listSequence);
}

void PmergeMe::mergeInsertSort(std::vector<int>& sequence)
{
    if (sequence.size() <= 1) return;

    size
}