/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:22:58 by gozon             #+#    #+#             */
/*   Updated: 2025/04/28 10:58:56 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool Bureaucrat::_setGrade(int grade) {

    try {
        if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        if (grade < 0)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        return (false);
    }
    this->_grade = grade;
    return (true);
}

Bureaucrat::Bureaucrat(): _name("Anonymous"), _grade(150) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name) {
    this->_setGrade(src._grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
    this->_setGrade(grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {

    if (this != &src) {
       this-> _setGrade(src._grade);
    }
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::promote() {
    if (this->_setGrade(this->_grade - 1)) {
        std::cout << "Bureaucrat " << this->_name << "has been promoted to grade ";
        std::cout << this->_grade << std::endl;
    }
}

void Bureaucrat::demote() {
    if (this->_setGrade(this->_grade + 1)) {
        std::cout << "Bureaucrat " << this->_name << " has been demoted to grade ";
        std::cout << this->_grade << std::endl;
    }
    else {
        std::cout << "Bureaucrat " << this->_name << "cannot be demoted." << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Error: cannot attribute a grade above 150.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Error: cannot attribute a grade under 1.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    out << "." << std::endl;
}
