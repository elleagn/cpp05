/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/04/24 10:14:17 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {

    private:

        std::string const _name;
        int _grade;

    public:

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& bureaucrat);
        Bureaucrat(const std::string& name, int grade);

        Bureaucrat& operator=(const Bureaucrat& src);

        std::string getName() const;
        int getGrade() const;

        void promote();
        void demote();

        class GradeTooHighException;
        class GradeTooLowException;

};

class Bureaucrat::GradeTooHighException: public std::exception {
    const char* what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception {
    const char* what() const throw();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
