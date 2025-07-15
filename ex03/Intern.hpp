/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:44:34 by gozon             #+#    #+#             */
/*   Updated: 2025/07/15 08:50:59 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern {

    public:
        Intern();
        Intern(const Intern& src);
        ~Intern();

        Intern& operator=(const Intern& src);

        AForm* makeForm(std::string name, std::string target) const;

};

#endif
