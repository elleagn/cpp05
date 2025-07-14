/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 12:19:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <unistd.h>

int main(void) {

    Bureaucrat mary("Mary", 1);
    std::cout << "\nPART 1: Shrubbery Creation Form\n" << std::endl;

    {
        std::cout << "Test 1 - Form creation: ";
        ShrubberyCreationForm shrubbery("blbl");
        if (shrubbery.getName() == "Shrubbery Creation" && shrubbery.getSignGrade() == 145
                && shrubbery.getExecGrade() == 137 && shrubbery.getTarget() == "blbl")
            std::cout << GREEN << "OK." << RESET << std::endl;
        else
            std::cout << RED << "FAILED." << RESET << std::endl;

        std::cout << "Test 2 - Executing an unsigned form: ";
        try {
            shrubbery.execute(mary);
            std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << GREEN << "Exception thrown." << RESET << std::endl;
            std::cout << BLUE << e.what() << RESET << std::endl;
        }

        mary.signForm(shrubbery);
        std::cout << "Test 3 - Executing a form with an insufficient grade: ";
        try {
            Bureaucrat john("John", 150);
            shrubbery.execute(john);
            std::cout << RED << "FAILED: no exception was thrown" << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << GREEN << "Exception thrown." << RESET << std::endl;
            std::cout << BLUE << e.what() << RESET << std::endl;
        }
        std::cout << "Test 4 - Executing a signed form with a valid bureaucrat: ";
        try {
            if (!access("blbl_shrubbery", F_OK))
                unlink("blbl_shrubbery");
            shrubbery.execute(mary);
            if (!access("blbl_shrubbery", F_OK))
                std::cout << GREEN << "File was created.\n" << RESET;
            else
                std::cout << RED << "FAILED: couldn't find file." << RESET;
        }
        catch (...) {
        std::cout << RED << "FAILED: exception thrown" << RESET;
        }

    }


    return (0);

}
