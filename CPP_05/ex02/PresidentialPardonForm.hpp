#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator = (const PresidentialPardonForm &src)

        void execute(Bureaucrat const &executor) const;
};

#endif