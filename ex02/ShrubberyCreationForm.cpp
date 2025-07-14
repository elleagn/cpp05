/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:58:38 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:19:55 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* ************************ CONSTRUCTORS / DESTRUCTORS ********************** */

ShrubberyCreationForm::ShrubberyCreationForm(): AForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery Creation", 137, 145, target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
AForm(src) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/* ************************************************************************** */

/* *********************** OPERATORS **************************************** */

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    AForm::operator=(src);
    return (*this);
}

/* ************************************************************************** */

/* ************************ FORM ACTIONS ************************************ */

void ShrubberyCreationForm::doSomething() const {

    std::ifstream tree("tree.txt");
    if (!tree.is_open()) {
        throw ShrubberyCreationForm::FileException();
    }

    std::string title = getTarget() + "_shrubbery";
    std::ofstream out(title.c_str(), std::fstream::out | std::fstream::trunc);
    if (!out.is_open()) {
        tree.close();
        throw ShrubberyCreationForm::FileException();
    }

    std::string line;
    while (std::getline(tree, line)) {
        out << line;
        if (out.bad())
            break;
        if (!tree.eof()) {
            out << "\n";
        }
    }
    bool problem = tree.bad() || out.bad();
    out.close();
    tree.close();
    if (problem)
        throw ShrubberyCreationForm::FileException();

}

/* ************************************************************************** */

/* ************************** EXCEPTIONS ************************************ */

const char* ShrubberyCreationForm::FileException::what() const throw() {
    return ("Shrubbery: Exception: error opening or writing to file.");
}

/* ************************************************************************** */
