#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form)
    {
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form)
    {
        delete form;
    }

    form = someRandomIntern.makeForm("unknown form", "target");
    if (form)
    {
        delete form;
    }

    return 0;
}