/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:22:58 by gozon             #+#    #+#             */
/*   Updated: 2025/04/28 10:25:24 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Anonymous"), _grade(150) {

}

Bureaucrat::~Bureaucrat() {

}

void Bureaucrat::_setGrade(int grade) {

    try {
        if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        if (grade < 0)
            throw Bureaucrat::GradeTooLowException();
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        return ;
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name) {
    this->setGrade(src._grade);
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
    this->setGrade(grade);
}

