/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/06/05 08:58:01 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {

    private:

        std::string const name;
        int grade;

        bool setGrade(int grade);

    public:

        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat(const std::string& name, int grade);

        Bureaucrat& operator=(const Bureaucrat& src);

        std::string getName() const;
        int getGrade() const;

        void promote();
        void demote();

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
