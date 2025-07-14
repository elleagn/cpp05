/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:55:33 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:25:42 by gozon            ###   ########.fr       */
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

class Bureaucrat;

class AForm {

    private:

        std::string const   _name;
        bool                _signed;
        int const           _execGrade;
        int const           _signGrade;
        std::string const   _target;

    protected:
        virtual void doSomething() const = 0;

    public:

        AForm();
        virtual ~AForm();
        AForm(const AForm& src);
        AForm(const std::string& name, int execGrade, int signGrade, std::string target);

        AForm& operator=(const AForm& src);

        std::string getName() const;
        int         getExecGrade() const;
        int         getSignGrade() const;
        bool        isSigned() const;
        std::string getTarget() const;

        void    beSigned(const Bureaucrat& bureaucrat);
        void    execute(const Bureaucrat& executor) const;

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };

        class UnsignedFormException: public std::exception {
            const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
