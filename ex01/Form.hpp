/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/07/13 17:19:19 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

// COLORS

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Form {

    private:

        std::string const _name;
        bool _signed;
        int const _execGrade;
        int const _signGrade;

    public:

        Form();
        ~Form();
        Form(const Form& src);
        Form(const std::string& name, int execGrade, int signGrade);

        Form& operator=(const Form& src);

        std::string getName() const;
        int getExecGrade() const;
        int getSignGrade() const;
        bool isSigned() const;

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& bureaucrat);

#endif
