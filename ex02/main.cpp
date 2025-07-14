/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:30:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

    std::cout << "\nPART 2: Robotomy Request Form\n" << std::endl;
    {
        std::cout << "Test 5 - Form creation: ";
        RobotomyRequestForm robotomy("blbl");
        if (robotomy.getName() == "Robotomy Request" && robotomy.getSignGrade() == 72
                && robotomy.getExecGrade() == 45 && robotomy.getTarget() == "blbl")
            std::cout << GREEN << "OK." << RESET << std::endl;
        else
            std::cout << RED << "FAILED." << RESET << std::endl;

        std::cout << "Test 6 - Executing an unsigned form:\n" << BLUE;
        mary.executeForm(robotomy);
        std::cout << std::endl << RESET;

        mary.signForm(robotomy);
        std::cout << std::endl;

        std::cout << "Test 7 - Executing a form with an insufficient grade:\n" << BLUE;
        john.executeForm(robotomy);

        std::cout << RESET << "Test 8 - Executing a signed robotomy with a valid bureaucrat several times:\n";
        for (int i = 0; i < 10; i++) {
            mary.executeForm(robotomy);
            usleep(1000010); // because we use the time as seed
        }
    }

    std::cout << "\nPART 3: Presidential Pardon Form\n" << std::endl;
    {
        std::cout << "Test 8 - Form creation: ";
        PresidentialPardonForm presidential("blbl");
        if (presidential.getName() == "Presidential Pardon" && presidential.getSignGrade() == 25
                && presidential.getExecGrade() == 5 && presidential.getTarget() == "blbl")
            std::cout << GREEN << "OK." << RESET << std::endl;
        else
            std::cout << RED << "FAILED." << RESET << std::endl;

        std::cout << "Test 9 - Executing an unsigned form:\n" << BLUE;
        mary.executeForm(presidential);
        std::cout << std::endl << RESET;

        mary.signForm(presidential);
        std::cout << std::endl;

        std::cout << "Test 10 - Executing a form with an insufficient grade:\n" << BLUE;
        john.executeForm(presidential);

        std::cout << RESET << "Test 11 - Executing a signed form with a valid bureaucrat:\n" << BLUE;
        mary.executeForm(presidential);
        std::cout << std::endl << RESET;
    }

    return (0);

}
