#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm &operator = (const RobotomyRequestForm &src);

        void execute(Bureaucrat const &executor) const;
};

#endif