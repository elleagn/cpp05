/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:42:17 by gozon             #+#    #+#             */
/*   Updated: 2025/07/14 19:03:39 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {

    protected:
        void doSomething(const Bureaucrat& executor) const;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

};

#endif
