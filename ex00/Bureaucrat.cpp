/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:22:58 by gozon             #+#    #+#             */
/*   Updated: 2025/06/05 08:57:51 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool Bureaucrat::setGrade(int grade) {

    try {
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
    }
    catch(std::exception &e) {
        return (false);
    }
    this->grade = grade;
    return (true);
}

Bureaucrat::Bureaucrat(): name("Anonymous"), grade(150) {

}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat& src): name(src.name), grade(src.grade) {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name) {
    if (!this->setGrade(grade)) {
        std::cout << "Error: could not create bureaucrat " << name;
        std::cout << " with invalid grade " << grade << ".\n";
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {

    if (this != &src) {
       this-> setGrade(src.grade);
    }
    std::cout << "Warning: name of a bureaucrat cannot be changed." << std::endl;
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::promote() {
    if (this->setGrade(this->grade - 1)) {
        std::cout << "Bureaucrat " << this->name << " has been promoted to grade ";
        std::cout << this->grade << std::endl;
    }
    else {
        std::cout << "Bureaucrat " << this->name << " cannot be promoted." << std::endl;
    }
}

void Bureaucrat::demote() {
    if (this->setGrade(this->grade + 1)) {
        std::cout << "Bureaucrat " << this->name << " has been demoted to grade ";
        std::cout << this->grade << std::endl;
    }
    else {
        std::cout << "Bureaucrat " << this->name << " cannot be demoted." << std::endl;
    }
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    out << ".";
    return (out);
}
