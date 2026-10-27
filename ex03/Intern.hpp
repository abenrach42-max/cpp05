/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 16:11:27 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/11 16:50:42 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class   Intern
{
    public:
    Intern(void);
    Intern(const Intern &src);
    Intern  &operator=(const Intern &src);
    ~Intern(void);
    AForm   *createShru(const std::string &formTarget);
    AForm   *createRobo(const std::string &formTarget);
    AForm   *createPres(const std::string &formTarget);
    AForm   *makeForm(const std::string &formName, const std::string &forTarget);
};

#endif