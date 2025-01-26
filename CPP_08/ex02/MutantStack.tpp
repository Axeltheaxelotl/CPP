# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MutantStack.tpp                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 20:58:43 by alanty            #+#    #+#              #
#    Updated: 2025/01/23 20:58:45 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

// Include the header file
#include "MutantStack.hpp"

// Implementation of MutantStack methods
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const {
    return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const {
    return this->c.rend();
}

#endif


