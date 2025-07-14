/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:19:53 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:04:53 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

PresidentialPardonForm::PresidentialPardonForm(): AForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
AForm("Presidential Pardon", 5, 25, target) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
AForm(src) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

/* ************************************************************************** */

/* *********************** OPERATORS **************************************** */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
    AForm::operator=(src);
    return (*this);
}

/* ************************************************************************** */

/* ************************ FORM ACTIONS ************************************ */

void PresidentialPardonForm::doSomething() const {

    std::cout << getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;

}

/* ************************************************************************** */
