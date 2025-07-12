/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/12 17:55:33 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    
    std::cout << "\nPART 1 : Creating Bureaucrats\n\n";

    std::cout << "Test 1 - Creating a valid Bureaucrat: ";
    try {
        Bureaucrat john("John", 23);
        if (john.getName() == "John" && john.getGrade() == 23) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    }
    else {
        std::cout << RED << "FAILED" << RESET << std::endl;
    }
    }
    catch (...) {
        std::cout << RED << "FAILED: exception thrown";
    }

    std::cout << "Test 2 - Bureaucrat with a grade too high: ";
    try {
        Bureaucrat john("John", 0);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 3 - Bureaucrat with a grade too low: ";
    try {
        Bureaucrat john("John", 151);
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "\nPART 2: Promoting/demoting Bureaucrats\n\n";

    {

        Bureaucrat john("John", 23);
        std::cout << "Test 4 - Valid promotion:\n" << BLUE;
        try {
            john.promote();
            if (john.getName() == "John" && john.getGrade() == 22) {
            std::cout << GREEN << "OK" << RESET << std::endl;
        }
        else {
            std::cout << RED << "FAILED" << RESET << std::endl;
        }
        }
        catch (...) {
            std::cout << RED << "FAILED: exception thrown";
        }

        std::cout << "Test 5 - Valid demotion:\n" << BLUE;
        try {
            john.demote();
            if (john.getName() == "John" && john.getGrade() == 23) {
            std::cout << GREEN << "OK" << RESET << std::endl;
        }
        else {
            std::cout << RED << "FAILED" << RESET << std::endl;
        }
        }
        catch (...) {
            std::cout << RED << "FAILED: exception thrown";
        }
     
    }

    std::cout << "Test 6 - Invalid promotion: ";
    try {
        Bureaucrat john("John", 1);
        john.promote();
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "Test 7 - Invalid demotion: ";
    try {
        Bureaucrat john("John", 150);
        john.demote();
        std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << GREEN << "Exception thrown." << RESET << std::endl;
        std::cout << BLUE << e.what() << RESET << std::endl;
    }

    std::cout << "\nTest 8 - Overload operator:\n";
    Bureaucrat john("John", 23);
    std::cout << john << std::endl << std::endl;
    
    return (0);
}
