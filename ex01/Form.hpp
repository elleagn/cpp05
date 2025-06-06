/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/06/05 08:58:28 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form {

    private:

        std::string const name;
        bool isSigned;
        int const execGrade;
        int const signGrade;

    public:

        Form();
        ~Form();
        Form(const Form& src);
        Form(const std::string& name, int execGrade, int signGrade);

        Form& operator=(const Form& src);

        std::string getName() const;
        int getExecGrade() const;
        int getSignGrade() const;
        bool getStatus() const;

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& bureaucrat);

#endif
