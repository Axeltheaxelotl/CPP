/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:54:18 by alanty            #+#    #+#             */
/*   Updated: 2025/01/28 14:54:19 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->isSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (!ofs.is_open() || ofs.fail()) {
        std::cerr << "Failed to open file: " << this->_target + "_shrubbery" << std::endl;
        return;
    }

    ofs <<
    "              * *\n"
    "           *    *  *\n"
    "      *  *    *     *  *\n"
    "     *     *    *  *    *\n"
    " * *   *    *    *    *   *\n"
    " *     *  *    * * .#  *   *\n"
    " *   *     * #.  .# *   *\n"
    "  *     \"#.  #: #\" * *    *\n"
    " *   * * \"#. ##\"       *\n"
    "   *       \"###\n"
    "             \"##\n"
    "              ##.\n"
    "              .##:\n"
    "              :###\n"
    "              ;###\n"
    "            ,####.\n"
    "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";

    ofs.close();
}
