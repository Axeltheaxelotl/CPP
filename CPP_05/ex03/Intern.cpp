#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

// Helper functions to create forms
AForm *createShrubberyCreationForm(const std::string &target) { return new ShrubberyCreationForm(target); }
AForm *createRobotomyRequestForm(const std::string &target) { return new RobotomyRequestForm(target); }
AForm *createPresidentialPardonForm(const std::string &target) { return new PresidentialPardonForm(target); }

// Member functions
AForm *Intern::makeForm(const std::string form_name, const std::string form_target)
{
    std::string available_forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*form_creators[3])(const std::string &) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i)
    {
        if (form_name == available_forms[i])
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return form_creators[i](form_target);
        }
    }

    std::cout << "Intern couldn't create form: " << form_name << std::endl;
    return NULL;
}