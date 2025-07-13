/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:13 by gozon             #+#    #+#             */
/*   Updated: 2025/07/13 17:58:09 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("undefined"), _signed(0), _execGrade(150),
_signGrade(150) {

}

Form::~Form() {

}

Form::Form(const Form& src): _name(src._name), _signed(src._signed),
_execGrade(src._execGrade), _signGrade(src._signGrade) {

        if (this->_signGrade > 150 || this->_execGrade > 150)
            throw Form::GradeTooLowException();
        if (this->_signGrade < 1 || this->_execGrade < 1)
            throw Form::GradeTooHighException();

}

Form::Form(const std::string& name, int execGrade, int signGrade):
_name(name), _signed(0), _execGrade(execGrade), _signGrade(signGrade) {

    if (this->_signGrade > 150 || this->_execGrade > 150)
            throw Form::GradeTooLowException();
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw Form::GradeTooHighException();

}

Form& Form::operator=(const Form& src) {
    (void)src;
    std::cout << "Cannot assign a form to another because of const attributes";
    std::cout << std::endl;
    return (*this);
}

std::string Form::getName() const {

    return (this->_name);
}

int Form::getExecGrade() const {

    return (this->_execGrade);

}

int Form::getSignGrade() const {

    return(this->_signGrade);

}

bool Form::isSigned() const {

    return (this->_signed);

}

void Form::beSigned(const Bureaucrat& bureaucrat) {

    if (bureaucrat.getGrade() > _execGrade)
        throw Form::GradeTooLowException();
    _signed = true;

}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: Exception: grade too low.");
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: Exception: grade too high.");
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    std::cout   << "Form " << form.getName() << " can be signed with a grade higher than "
                << form.getExecGrade() << " and executed with a grade higher than "
                << form.getSignGrade() << ". ";
    std::cout << "It's currently ";
    if (!form.isSigned()) {
        std::cout << "not ";
    }
    std::cout << "signed.";
    return (out);
}
