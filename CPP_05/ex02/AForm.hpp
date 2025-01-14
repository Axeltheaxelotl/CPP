#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const unsigned int _signGrade;
        const unsigned int _execGrade;

    public:
        AForm(void);
        AForm(std::string name, unsigned int signGradem, unsigned int execGrade);
        AForm(const AForm &src);
        virtual ~AForm(void);
        AForm &operator = (const AForm &src);

        std::string getName(void) const;
        bool isSigned(void) const;
        unsigned int getSignGrade(void) const;
        unsigned int getExecGrade(void) const;

        void beSigned(const Bureaucrat &bur);
        virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighExecption: public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };

    class GradeToolLowException: public std::exception
    {
        public:
            virtual const char* what(void) const throw();
    };
};

std::ostream &operator <<(std::ostream &o, const AForm &form);

#endif