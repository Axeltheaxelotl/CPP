# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    easyfind.tpp                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 20:57:45 by alanty            #+#    #+#              #
#    Updated: 2025/01/23 20:57:49 by alanty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return it;
}
