/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/13 17:47:04 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    std::cout << "\nPART 1: Form creation\n" << std::endl;

    std::cout << "Test 1 - Creating a valid form: ";
    try {
        Form form("MyForm", 32, 23);
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
        Form form("MyForm", 0, 23);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3 - Form with an execGrade too low: ";
    try {
        Form form("MyForm", 151, 23);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3 - Form with a signGrade too high: ";
    try {
        Form form("MyForm", 1, 0);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 4 - Form with a signGrade too low: ";
    try {
        Form form("MyForm", 1, 151);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "\nTest 5 - Overload operator:\n";
    Form form("MyForm", 32, 23);
    std::cout << form << std::endl << std::endl;
    return (0);

}
