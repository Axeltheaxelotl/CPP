/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:53:30 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 14:53:31 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        delete forms[i];
    }
    std::cout << "Form name " << formName << " does not exist" << std::endl;
    return NULL;
}
