#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
    Bureaucrat	thiery = Bureaucrat("Thiery", 3);
    Bureaucrat	thiery_copy = thiery;
    Bureaucrat	sophie = Bureaucrat("Sophie", 150);
    Bureaucrat	lou = Bureaucrat("Lou", 20);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "Create a form with incorrect grade: ";
    try
    {
        ShrubberyCreationForm invalidForm("invalid");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "SignForm: Sophie sign Shrubbery: ";
    try
    {
        sophie.signForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "BeSigned: Thiery sign Robotomy: ";
    try
    {
        robotomy.beSigned(thiery);
        std::cout << "OK" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    thiery_copy.incrementGrade();

    std::cout << "BeSigned: Thierry_copy sign Robotomy: ";
    try
    {
        robotomy.beSigned(thiery_copy);
        std::cout << "OK" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "SignForm: Lou sign Pardon: ";
    try
    {
        lou.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Shrubbery: ";
    try
    {
        thiery.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Robotomy: ";
    try
    {
        thiery.executeForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Pardon: ";
    try
    {
        thiery.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}