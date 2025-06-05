/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:13 by gozon             #+#    #+#             */
/*   Updated: 2025/06/05 08:58:24 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("undefined"), isSigned(0), execGrade(150),
signGrade(150) {

}

Form::~Form() {

}

Form::Form(const Form& src): name(src.name), isSigned(src.isSigned),
execGrade(src.execGrade), signGrade(src.signGrade) {

    try {
        if (this->signGrade > 150 || this->execGrade > 150)
            throw Form::GradeTooLowException();
        if (this->signGrade < 1 || this->execGrade < 1)
            throw Form::GradeTooHighException();
    }
    catch (std::exception &e) {
    }

}

Form::Form(const std::string& name, int execGrade, int signGrade):
name(name), isSigned(0), execGrade(execGrade), signGrade(signGrade) {

}

Form& Form::operator=(const Form& src) {

    std::cout << "Cannot assign a form to another because of const attributes";
    std::cout << std::endl;
    return (*this);

}

std::string Form::getName() const {

    return (this->name);
}

int Form::getExecGrade() const {

    return (this->execGrade);

}

int Form::getSignGrade() const {

    return(this->signGrade);

}

bool Form::getStatus() const {

    return (this->isSigned);

}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}
