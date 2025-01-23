/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:45:40 by alanty            #+#    #+#             */
/*   Updated: 2025/01/23 13:45:41 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void)
	: _name("Unnamed"), _signGrade(HIGHTEST_GRADE), _execGrade(HIGHTEST_GRADE)
{
	this->_isSigned = false;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < HIGHTEST_GRADE || execGrade < HIGHTEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form(const Form &src)
	: _name(src.getName() + "_copy"), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

Form::~Form(void)
{

}

Form	&Form::operator =(const Form &src)
{
	if (this != &src)
	{
		this->_isSigned = src.isSigned();
	}
	return *this;
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::isSigned(void) const
{
	return this->_isSigned;
}

unsigned int	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

unsigned int	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void	Form::beSigned(const Bureaucrat bur)
{
	if (bur.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("The grade is too high for his form...");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("The grade is too low for this form...");
}

std::ostream	&operator <<(std::ostream &o, const Form &form)
{
	o << "| Form:\t" << form.getName() << std::endl;
	o << "|\tSigned:\t" << form.isSigned() << std::endl;
	o << "|\tGrade to sign:\t" << form.getSignGrade() << std::endl;
	o << "|\tGrade to execute:\t" << form.getExecGrade();

	return o;
}
