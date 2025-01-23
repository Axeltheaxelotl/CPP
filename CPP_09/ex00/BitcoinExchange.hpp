/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:01:05 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 21:01:06 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(const std::string& dbFile);
        ~BitcoinExchange();

        float getExchangeRate(const std::string& date) const;
        void loadDatabase(const std::string& dbFile);

    private:
        std::map<std::string, float> exchangeRates;
};

#endif
