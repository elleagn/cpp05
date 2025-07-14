/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:58:44 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 10:03:22 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm {

    protected:
        void doSomething(const Bureaucrat& executor) const;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

        class FileException: public std::exception {
            const char* what() const throw();
        };

};

#endif
