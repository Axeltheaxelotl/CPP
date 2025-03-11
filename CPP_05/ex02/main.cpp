#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);
    Bureaucrat midRank("MidRank", 75);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "Testing ShrubberyCreationForm:" << std::endl;
    try
    {
        lowRank.signForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        highRank.signForm(shrubbery);
        highRank.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTesting RobotomyRequestForm:" << std::endl;
    try
    {
        midRank.signForm(robotomy);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        highRank.signForm(robotomy);
        for (int i = 0; i < 5; ++i)
        {
            highRank.executeForm(robotomy);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTesting PresidentialPardonForm:" << std::endl;
    try
    {
        midRank.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        highRank.signForm(pardon);
        highRank.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTesting invalid form creation:" << std::endl;
    try
    {
        ShrubberyCreationForm invalidForm("invalid");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}