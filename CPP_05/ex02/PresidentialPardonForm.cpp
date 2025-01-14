#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentalPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentalPardonForm::PresidentialPardonForm(const PresidentalPardonForm &src) : AForm(src)