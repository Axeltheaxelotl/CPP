/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:56:52 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 20:56:53 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, int length, void (*func)(T&))
{
    for (int i = 0; i < length; ++i) 
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T* array, int length, void (*func)(const T&)) 
{
    for (int i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

#endif
