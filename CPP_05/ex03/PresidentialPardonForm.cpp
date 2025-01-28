/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:53:54 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 14:53:55 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator =(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
