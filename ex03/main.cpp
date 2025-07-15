/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/15 09:46:41 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int main(void) {

    Intern intern;

    AForm* form = NULL;

    std::cout << "Test 1 - ShrubberyCreationForm:\n" << BLUE;
    form = intern.makeForm("Shrubbery Creation", "blbl");
    if (form && form->getName() == "Shrubbery Creation"
        && form->getTarget() == "blbl")
        std::cout << GREEN << "OK.\n" << RESET;
    else
        std::cout << RED << "FAILED.\n" << RESET;
    delete form;
    form = NULL;

    std::cout << "Test 2 - RobotomyRequestForm:\n" << BLUE;
    form = intern.makeForm("Robotomy ReqUest", "blbl");
    if (form && form->getName() == "Robotomy Request"
        && form->getTarget() == "blbl")
        std::cout << GREEN << "OK.\n" << RESET;
    else
        std::cout << RED << "FAILED.\n" << RESET;
    delete form;
    form = NULL;

    std::cout << "Test 3 - PresidentialPardonForm:\n" << BLUE;
    form = intern.makeForm("PRESIDENTIAL PARDOn", "blbl");
    if (form && form->getName() == "Presidential Pardon"
        && form->getTarget() == "blbl")
        std::cout << GREEN << "OK.\n" << RESET;
    else
        std::cout << RED << "FAILED.\n" << RESET;
    delete form;
    form = NULL;

    std::cout << "Test 4 - Invalid Form:\n" << BLUE;
    form = intern.makeForm("PRESIDENTIAL PARDO", "blbl");
    if (!form)
        std::cout << GREEN << "OK.\n" << RESET;
    else
        std::cout << RED << "FAILED.\n" << RESET;
    delete form;
    form = NULL;

    return (0);

}
