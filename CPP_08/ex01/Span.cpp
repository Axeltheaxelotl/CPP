#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

void Span::addNumber(int number)
{
    if (_numbers.size() >= max_size)
    {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() <= 1)
    {
        throw std::out_of_range("Not enough numbers to calculate span");
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        if (sorted[i] - sorted[i - 1] < min)
        {
            min = sorted[i] - sorted[i - 1];
        }
    }
    return min;
}

int Span::longestSpan() const
{
    if (_numbers.size() <= 1)
    {
        throw std::out_of_range("Not enough numbers to calculate span");
    }
    int min_number = *std::min_element(_numbers.begin(), _numbers.end());
    int max_number = *std::max_element(_numbers.begin(), _numbers.end());
    return max_number - min_number;
}