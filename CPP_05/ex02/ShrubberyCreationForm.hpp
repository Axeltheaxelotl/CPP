#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
        ShrubberyCreationForm();
        virtual void execute(Bureaucrat const &executor) const;
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
};

#endif