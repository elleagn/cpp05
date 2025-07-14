/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:13 by gozon             #+#    #+#             */
/*   Updated: 2025/07/13 18:42:00 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

AForm::AForm(): _name("undefined"), _signed(0), _execGrade(150),
_signGrade(150), _target("none") {

}

AForm::~AForm() {

}

AForm::AForm(const AForm& src): _name(src._name), _signed(src._signed),
_execGrade(src._execGrade), _signGrade(src._signGrade), _target(src._target) {

        if (this->_signGrade > 150 || this->_execGrade > 150)
            throw AForm::GradeTooLowException();
        if (this->_signGrade < 1 || this->_execGrade < 1)
            throw AForm::GradeTooHighException();

}

AForm::AForm(const std::string& name, int execGrade, int signGrade, std::string target):
_name(name), _signed(false), _execGrade(execGrade), _signGrade(signGrade), _target(target) {

    if (this->_signGrade > 150 || this->_execGrade > 150)
            throw AForm::GradeTooLowException();
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();

}

/* ************************************************************************** */

/* *********************** OPERATORS **************************************** */

AForm& AForm::operator=(const AForm& src) {
    (void)src;
    std::cout << "Cannot assign a form to another because of const attributes";
    std::cout << std::endl;
    return (*this);

}

std::ostream& operator<<(std::ostream& out, const AForm& form) {

    std::cout   << "Form " << form.getName() << " can be signed with a grade higher than "
                << form.getSignGrade() << " and executed with a grade higher than "
                << form.getExecGrade() << ". ";
    std::cout << "It's currently ";
    if (!form.isSigned()) {
        std::cout << "not ";
    }
    std::cout << "signed.";
    return (out);
}

/* ************************************************************************** */

/* ************************ GETTERS ***************************************** */

std::string AForm::getName() const {

    return (this->_name);
}

int AForm::getExecGrade() const {

    return (this->_execGrade);

}

int AForm::getSignGrade() const {

    return(this->_signGrade);

}

bool AForm::isSigned() const {

    return (this->_signed);

}

std::string AForm::getTarget() const {

    return (_target);

}

/* ************************************************************************** */

/* ************************ FORM ACTIONS ************************************ */

void AForm::beSigned(const Bureaucrat& bureaucrat) {

    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;

}

void    AForm::execute(const Bureaucrat& executor) const {

    if (!_signed)
        throw AForm::UnsignedFormException();
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();
    doSomething(executor);

}

/* ************************************************************************** */

/* ************************** EXCEPTIONS ************************************ */

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Form: Exception: grade too low.");
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Form: Exception: grade too high.");
}

const char* AForm::UnsignedFormException::what() const throw() {
    return ("Form: Exception: form is not signed.");
}

/* ************************************************************************** */
