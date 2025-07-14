/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:58:38 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 09:03:57 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery Creation", 137, 145, target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
AForm(src) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/* ************************************************************************** */

/* *********************** OPERATORS **************************************** */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    AForm::operator=(src);
    return (*this);
}

/* ************************************************************************** */

/* ************************ FORM ACTIONS ************************************ */

void ShrubberyCreationForm::doSomething(const Bureaucrat& executor) {

    (void)executor;

}

/* ************************************************************************** */


