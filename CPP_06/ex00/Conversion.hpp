#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <cctype>

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NAN_INF,
    ERROR
};

class Conversion
{
public:
    Conversion(const std::string &input);
    Conversion(const Conversion &src);
    ~Conversion();

    Conversion &operator=(const Conversion &src);

    class ErrorException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    std::string getInput() const;
    int getType() const;
    char getChar() const;
    int getInt() const;
    float getFloat() const;
    double getDouble() const;

private:
    Conversion();
    void convertInput();
    void printOutput() const;
    int checkInput();
    void fromChar();
    void fromInt();
    void fromFloat();
    void fromDouble();
    void fromNanInf(); // Ajout de la déclaration de la méthode fromNanInf

    std::string _input;
    int _type;
    char _char;
    int _int;
    float _float;
    double _double;
};

#endif