/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:56:55 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 20:56:56 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define MAX_VAL 750

void increment(int& x) {
    x++;
}

void print(const int& x) {
    std::cout << x << " ";
}

int main() {
    int array[MAX_VAL];
    for (int i = 0; i < MAX_VAL; ++i) {
        array[i] = i;
    }

    iter(array, MAX_VAL, increment);
    iter(array, MAX_VAL, print);
    std::cout << std::endl;

    return 0;
}
