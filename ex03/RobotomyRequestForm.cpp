/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:19:53 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:19:27 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

RobotomyRequestForm::RobotomyRequestForm(): AForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
AForm("Robotomy Request", 45, 72, target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
AForm(src) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

/* ************************************************************************** */

/* *********************** OPERATORS **************************************** */

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
    AForm::operator=(src);
    return (*this);
}

/* ************************************************************************** */

/* ************************ FORM ACTIONS ************************************ */

void RobotomyRequestForm::doSomething() const {

    std::srand(std::time(NULL));
    int const outcome = std::rand() % 2;
    std::cout << "/* drilling noises */" << std::endl;
    std::cout << getTarget() << "'s robotomy was a ";
    if (outcome) {
        std::cout << GREEN << "SUCCESS" << RESET << "!!! Yay!" << std::endl;
    }
    else {
        std::cout << RED << "FAILURE" << RESET << "... Oops!" << std::endl;
    }
}

/* ************************************************************************** */
