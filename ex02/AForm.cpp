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

AForm::AForm(): _name("undefined"), _signed(0), _execGrade(150),
_signGrade(150) {

}

AForm::~AForm() {

}

AForm::AForm(const AForm& src): _name(src._name), _signed(src._signed),
_execGrade(src._execGrade), _signGrade(src._signGrade) {

        if (this->_signGrade > 150 || this->_execGrade > 150)
            throw AForm::GradeTooLowException();
        if (this->_signGrade < 1 || this->_execGrade < 1)
            throw AForm::GradeTooHighException();

}

AForm::AForm(const std::string& name, int execGrade, int signGrade):
_name(name), _signed(0), _execGrade(execGrade), _signGrade(signGrade) {

    if (this->_signGrade > 150 || this->_execGrade > 150)
            throw AForm::GradeTooLowException();
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();

}

AForm& AForm::operator=(const AForm& src) {
    (void)src;
    std::cout << "Cannot assign a form to another because of const attributes";
    std::cout << std::endl;
    return (*this);
}

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

void AForm::beSigned(const Bureaucrat& bureaucrat) {

    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;

}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Form: Exception: grade too low.");
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Form: Exception: grade too high.");
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
