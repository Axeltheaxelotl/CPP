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