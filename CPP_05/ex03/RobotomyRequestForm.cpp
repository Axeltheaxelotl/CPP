#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}