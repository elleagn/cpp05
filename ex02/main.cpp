/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/13 19:02:37 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {

    std::cout << "\nPART 1: Form creation\n" << std::endl;

    std::cout << "Test 1 - Creating a valid form: ";
    try {
        AForm form("MyForm", 32, 23);
        if (form.getName() == "MyForm" && form.getExecGrade() == 32
                && form.getSignGrade() == 23 && !form.isSigned()) {
        std::cout << GREEN << "OK" << RESET << std::endl;
        }
        else {
        std::cout << RED << "FAILED" << RESET << std::endl;
        }
    }
    catch (...) {
        std::cout << RED << "FAILED: exception thrown";
    }

    std::cout << "Test 2 - Form with an execGrade too high: ";
    try {
        AForm form("MyForm", 0, 23);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3 - Form with an execGrade too low: ";
    try {
        AForm form("MyForm", 151, 23);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3 - Form with a signGrade too high: ";
    try {
        AForm form("MyForm", 1, 0);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 4 - Form with a signGrade too low: ";
    try {
        AForm form("MyForm", 1, 151);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "\nPART 2: Form signing\n" << std::endl;

    Bureaucrat mary("Mary", 21);
    std::cout << mary << std::endl;
    Bureaucrat john("John", 24);
    std::cout << john << std::endl;

    std::cout << "\nTest 5 - Overload operator:\n";
    AForm form("MyForm", 32, 23);
    std::cout << BLUE << form << RESET << std::endl << std::endl;

    std::cout << "Test 6 - Trying to sign form with a grade too low:\n" << BLUE;
    john.signForm(form);
    if (!form.isSigned()) {
        std::cout << GREEN << "OK.\n" << RESET;
    }
    else {
        std::cout << RED << "FAILED.\n" << RESET;
    }
    std::cout << "Test 7 - Signing form with a satisfying grade:\n" << BLUE;
    mary.signForm(form);
    if (form.isSigned()) {
        std::cout << GREEN << "OK.\n" << RESET;
    }
    else {
        std::cout << RED << "FAILED.\n" << RESET;
    }
    std::cout << "Test 7 - Trying to sign an already signed form:\n" << BLUE;
    mary.signForm(form);

    std::cout << std::endl;
    return (0);

}
