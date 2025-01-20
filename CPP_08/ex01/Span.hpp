#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
public:
    Span(unsigned int N);
    void addNumber(int number);
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);
    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> _numbers;
    unsigned int max_size;
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

#endif