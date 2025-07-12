/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:22:58 by gozon             #+#    #+#             */
/*   Updated: 2025/07/12 17:59:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool Bureaucrat::_setGrade(int grade) {

    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
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
    std::cout << "Warning: name of a bureaucrat cannot be changed." << std::endl;
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::promote() {

    this->_setGrade(_grade - 1);
    std::cout << "Bureaucrat " << this->_name << " has been promoted to grade ";
    std::cout << this->_grade << std::endl;

}

void Bureaucrat::demote() {

    this->_setGrade(_grade + 1);
    std::cout << "Bureaucrat " << this->_name << " has been demoted to grade ";
    std::cout << this->_grade << std::endl;

}

const char* Bureaucrat::GradeTooLowException::what() const throw() {

    return ("Bureaucrat: Exception: grade too low.");

}

const char* Bureaucrat::GradeTooHighException::what() const throw() {

    return ("Bureaucrat: Exception: grade too high.");

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {

    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    out << ".";
    return (out);

}
