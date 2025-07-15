/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:51:24 by gozon             #+#    #+#             */
/*   Updated: 2025/07/15 09:52:57 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/* *************************** UTILS **************************************** */

std::string toLowerCase(const std::string& str) {

    std::string res;
    for (size_t i = 0; i < str.length(); i++) {
        res += tolower(str[i]);
    }
    return (res);

}

/* ************************************************************************** */

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

Intern::Intern() {

}

Intern::Intern(const Intern& src) {

    (void)src;

}

Intern::~Intern() {

}

/* ************************************************************************** */

/* ************************** OPERATORS ************************************* */

Intern& Intern::operator=(const Intern& src) {

    (void)src;
    return (*this);

}

/* ************************************************************************** */

/* *************************** INTERN ACTIONS ******************************* */

AForm* Intern::makeForm(std::string name, std::string target) const {

    AForm* aux[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)};
    std::string lowerName;
    AForm* res = NULL;

    lowerName = toLowerCase(name);
    for (int i = 0; i < 3; i++) {

        if (toLowerCase(aux[i]->getName()) == lowerName) {
            res = aux[i];
            std::cout << "Intern creates " << res->getName() << std::endl;;
        }
        else
            delete aux[i];

    }

    if (!res)
        std::cout << "Intern could not find " << name << std::endl;

    return (res);
}

/* ************************************************************************** */
