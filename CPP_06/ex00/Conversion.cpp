#include "Conversion.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

Conversion::Conversion(const std::string &input) : _input(input)
{
    this->_type = this->checkInput();
    this->convertInput();
    this->printOutput();
}

Conversion::Conversion(const Conversion &src) : _input(src.getInput())
{
    *this = src;
}

Conversion::~Conversion() {}

Conversion &Conversion::operator=(const Conversion &src)
{
    if (this != &src)
    {
        this->_input = src.getInput();
        this->_type = src.getType();
        this->_char = src.getChar();
        this->_int = src.getInt();
        this->_float = src.getFloat();
        this->_double = src.getDouble();
    }
    return *this;
}

std::string Conversion::getInput() const { return this->_input; }
int Conversion::getType() const { return this->_type; }
char Conversion::getChar() const { return this->_char; }
int Conversion::getInt() const { return this->_int; }
float Conversion::getFloat() const { return this->_float; }
double Conversion::getDouble() const { return this->_double; }

int Conversion::checkInput()
{
    if (this->_input == "nan" || this->_input == "nanf" || this->_input == "+inf" || this->_input == "-inf" || this->_input == "+inff" || this->_input == "-inff")
        return NAN_INF;
    if (this->_input.length() == 1 && !isdigit(this->_input[0]))
        return CHAR;
    try
    {
        std::istringstream iss(this->_input);
        double d;
        iss >> d;
        if (iss.fail())
            return ERROR;
        if (this->_input.find('.') != std::string::npos)
        {
            if (this->_input[this->_input.length() - 1] == 'f')
                return FLOAT;
            return DOUBLE;
        }
        return INT;
    }
    catch (const std::exception &)
    {
        return ERROR;
    }
}

void Conversion::convertInput()
{
    switch (this->_type)
    {
    case CHAR:
        this->fromChar();
        break;
    case INT:
        this->fromInt();
        break;
    case FLOAT:
        this->fromFloat();
        break;
    case DOUBLE:
        this->fromDouble();
        break;
    case NAN_INF:
        this->fromNanInf();
        break;
    default:
        throw Conversion::ErrorException();
    }
}

void Conversion::fromChar()
{
    this->_char = this->_input[0];
    this->_int = static_cast<int>(this->_char);
    this->_float = static_cast<float>(this->_char);
    this->_double = static_cast<double>(this->_char);
}

void Conversion::fromInt()
{
    this->_int = atoi(this->_input.c_str());
    this->_char = static_cast<char>(this->_int);
    this->_float = static_cast<float>(this->_int);
    this->_double = static_cast<double>(this->_int);
}

void Conversion::fromFloat()
{
    this->_float = static_cast<float>(atof(this->_input.c_str()));
    this->_char = static_cast<char>(this->_float);
    this->_int = static_cast<int>(this->_float);
    this->_double = static_cast<double>(this->_float);
}

void Conversion::fromDouble()
{
    this->_double = atof(this->_input.c_str());
    this->_char = static_cast<char>(this->_double);
    this->_int = static_cast<int>(this->_double);
    this->_float = static_cast<float>(this->_double);
}

void Conversion::fromNanInf()
{
    this->_char = 0;
    this->_int = 0;
    this->_float = atof(this->_input.c_str());
    this->_double = atof(this->_input.c_str());
}

void Conversion::printOutput() const
{
    std::cout << "char: ";
    if (this->_type == NAN_INF || this->_int < 0 || this->_int > 127 || !isprint(this->_char))
        std::cout << "impossible" << std::endl;
    else if (!isprint(this->_char))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << this->_char << "'" << std::endl;

    std::cout << "int: ";
    if (this->_type == NAN_INF || this->_double < std::numeric_limits<int>::min() || this->_double > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << this->_int << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << this->_float << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << this->_double << std::endl;
}

const char *Conversion::ErrorException::what() const throw()
{
    return "Error: Impossible to print or input not convertable";
}