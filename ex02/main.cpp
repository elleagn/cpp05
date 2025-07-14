/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 08:20:56 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

    std::cout << "\nPART 1: Shrubbery Creation Form\n" << std::endl;

    {
        std::cout << "Test 1 - Form creation: ";
        ShrubberyCreationForm shrubbery("blbl");
        if (shrubbery.getName() == "Shrubbery Creation" && shrubbery.getSignGrade() == 145
                && shrubbery.getExecGrade() == 137 && shrubbery.getTarget() == "blbl")
            std::cout << GREEN << "OK." << RESET << std::endl;
        else
            std::cout << RED << "FAILED." << RESET << std::endl;
    }


    return (0);

}
