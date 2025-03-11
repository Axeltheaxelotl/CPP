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
    try
    {
        // Test Bureaucrat
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        // Test increment and decrement
        alice.incrementGrade();
        std::cout << alice << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        // Test PresidentialPardonForm
        PresidentialPardonForm pardon("Ford Prefect");
        std::cout << pardon << std::endl;
        bob.signForm(pardon);
        bob.executeForm(pardon);

        // Test Intern
        Intern someRandomIntern;
        AForm* form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (form)
        {
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("unknown form", "target");
        if (form)
        {
            delete form;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}