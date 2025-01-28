/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:53:58 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 14:53:59 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        PresidentialPardonForm &operator =(const PresidentialPardonForm &src);

        void execute(Bureaucrat const &executor) const;
};

#endif
