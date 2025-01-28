#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat Marc_Dutroux = Bureaucrat("Marc_Dutroux", 3);
    Bureaucrat Marc_Dutroux_copy = Marc_Dutroux;
    Bureaucrat Émile_Louis = Bureaucrat("Émile_Louis", 150);
    Bureaucrat lou = Bureaucrat("Kevin", 20);

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

    std::cout << "SignForm: Émile_Louis sign Shrubbery: ";
    try
    {
        Émile_Louis.signForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "BeSigned: Marc_Dutroux sign Robotomy: ";
    try
    {
        robotomy.beSigned(Marc_Dutroux);
        std::cout << "OK" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Marc_Dutroux_copy.incrementGrade();

    std::cout << "BeSigned: Émile_Louis_copy sign Robotomy: ";
    try
    {
        robotomy.beSigned(Marc_Dutroux_copy);
        std::cout << "OK" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "SignForm: Kevin sign Pardon: ";
    try
    {
        lou.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "SignForm: Marc_Dutroux sign Shrubbery: ";
    try
    {
        Marc_Dutroux.signForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Shrubbery: ";
    try
    {
        Marc_Dutroux.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Robotomy: ";
    try
    {
        Marc_Dutroux.executeForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Execute Pardon: ";
    try
    {
        Marc_Dutroux.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}