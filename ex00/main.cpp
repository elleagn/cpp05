/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:18:15 by gozon             #+#    #+#             */
/*   Updated: 2025/04/29 09:39:34 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat J("John", 150);
    Bureaucrat J1(J);

    std::cout << "CREATING BUREAUCRATS\n" << std::endl;
    std::cout << J << std::endl;
    std::cout << J1 << std::endl;
    J1 = Bureaucrat("", 1);
    std::cout << J1 << std::endl;
    std::cout << "\nInvalid grade:\n";
    Bureaucrat I("Invalid", 350);

    std::cout << "\nPROMOTING/DEMOTING\n\n";
    J.demote();
    J.promote();
    J1.promote();
    J1.demote();
    return (0);
}
