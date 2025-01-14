#include <iostream>
#include <string>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::GradeTooHighExecption();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooHighExecption();

    std::ofstream ofs(this->_target  + "_shrubbery");
    if (ofs.fail())
        throw std::ofstream::failure("Failed to open file");

    ofs << "ASCII trees" << std::endl;
    ofs.close();
}