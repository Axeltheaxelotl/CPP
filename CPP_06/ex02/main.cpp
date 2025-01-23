/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:54:44 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 20:54:45 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
#include "identify.hpp"
#include <iostream>

int main()
{
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}
