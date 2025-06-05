/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:13 by gozon             #+#    #+#             */
/*   Updated: 2025/05/26 18:29:57 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("undefined"), _isSigned(0), _execGrade(150), 
_signGrade(150) {

}

Form::~Form() {

}

Form::Form(const Form& src): _name(src._name), _isSigned(src._isSigned), 
_execGrade(src._execGrade), _signGrade(src._signGrade) {

    try {
        if (this->_signGrade > 150 || this->_execGrade > 150)
            throw Form::GradeTooLowException();
        if (this->_signGrade < 1 || this->_execGrade < 1)
            throw Form::GradeTooHighException();
    }
    catch (std::exception &e) {
    }
    
}

Form::Form(const std::string& name, int execGrade, int signGrade): 
_name(name), _isSigned(0), _execGrade(execGrade), _signGrade(signGrade) {

}

Form& Form::operator=(const Form& src) {

    std::cout << "Cannot assign a form to another because of const attributes";
    std::cout << std::endl;

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

bool Form::getStatus() const {
    
    return (this->_isSigned);
    
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Exception: grade too low.");
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Exception: grade too high.");
}