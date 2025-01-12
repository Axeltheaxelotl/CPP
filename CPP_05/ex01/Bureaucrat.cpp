#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Unnamed"), _grade(LOWEST_GRADE)
{

}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name)
{
	if (grade < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy")
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void	Bureaucrat::signForm(Form form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << "." << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because the lowest grade to sign is " << form.getSignGrade() << "." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high, hightest is 1...");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low, lowest is 150...");
}

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur)
{
	o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
