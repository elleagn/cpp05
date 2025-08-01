/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 12:23:06 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

// COLORS

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class AForm;

class Bureaucrat {

    private:

        std::string const _name;
        int _grade;

        bool _setGrade(int grade);

        Bureaucrat();

    public:

        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat(const std::string& name, int grade);

        Bureaucrat& operator=(const Bureaucrat& src);

        std::string getName() const;
        int         getGrade() const;

        void promote();
        void demote();

        void    signForm(AForm& form) const;
        void    executeForm(const AForm& form) const;

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };


};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
