/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <alanty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:45:08 by alanty            #+#    #+#             */
/*   Updated: 2025/03/11 13:13:39 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <iostream>
# include <string>
# include "Form.hpp"

# define HIGHTEST_GRADE 1
# define LOWEST_GRADE 150

class Form;

class Bureaucrat {
private:
    const std::string	_name;
    unsigned int		_grade;

public:
    Bureaucrat(void);
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat(void);
    Bureaucrat	&operator =(const Bureaucrat &src);

    std::string		getName(void) const;
    unsigned int	getGrade(void) const;

    void			incrementGrade(void);
    void			decrementGrade(void);
    void			signForm(Form &form) const;

    class GradeTooHighException: public std::exception {
    public:
        virtual const char* what(void) const throw();
    };

    class GradeTooLowException: public std::exception {
    public:
        virtual const char* what(void) const throw();
    };
};

std::ostream	&operator <<(std::ostream &o, const Bureaucrat &bur);

#endif