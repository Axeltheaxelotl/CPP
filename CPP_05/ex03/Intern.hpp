#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &src);
        ~Intern(void);
        Intern &operator=(const Intern &src);

        AForm *makeForm(std::string formName, std::string target);
};

#endif