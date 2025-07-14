/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 12:37:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <unistd.h>

int main(void) {

    Bureaucrat mary("Mary", 1);
    Bureaucrat john("John", 150);

    std::cout << "\nPART 1: Shrubbery Creation Form\n" << std::endl;
    {
        std::cout << "Test 1 - Form creation: ";
        ShrubberyCreationForm shrubbery("blbl");
        if (shrubbery.getName() == "Shrubbery Creation" && shrubbery.getSignGrade() == 145
                && shrubbery.getExecGrade() == 137 && shrubbery.getTarget() == "blbl")
            std::cout << GREEN << "OK." << RESET << std::endl;
        else
            std::cout << RED << "FAILED." << RESET << std::endl;

        std::cout << "Test 2 - Executing an unsigned form:\n" << BLUE;
        mary.executeForm(shrubbery);
        std::cout << std::endl << RESET;

        mary.signForm(shrubbery);
        std::cout << std::endl;

        std::cout << "Test 3 - Executing a form with an insufficient grade:\n" << BLUE;
        john.executeForm(shrubbery);

        std::cout << RESET << "Test 4 - Executing a signed form with a valid bureaucrat:\n" << BLUE;
        if (!access("blbl_shrubbery", F_OK))
            unlink("blbl_shrubbery");
        mary.executeForm(shrubbery);
        if (!access("blbl_shrubbery", F_OK))
            std::cout << GREEN << "File created\n" << RESET;
        else
            std::cout << RED << "FAILED: couldn't find file\n" << RESET;

    }


    return (0);

}
