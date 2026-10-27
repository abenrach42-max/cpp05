/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:40:38 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/11 17:01:28 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    //std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    *this = src;
}
Intern  &Intern::operator=(const Intern &src)
{
    (void)src;
    return (*this);
}

AForm   *Intern::createShru(const std::string &formTarget)
{
    return (new ShrubberyCreationForm(formTarget));
}

AForm   *Intern::createRobo(const std::string &formTarget)
{
    return (new RobotomyRequestForm(formTarget));
}

AForm   *Intern::createPres(const std::string &formTarget)
{
    return (new PresidentialPardonForm(formTarget));
}

AForm   *Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
    std::string tab_str[3] = {"shrubbery request", "presidential request", "robotomy request"};
    AForm   *(Intern::*tabCreateForm[3])(const std::string &) = {&Intern::createShru, &Intern::createPres, &Intern::createRobo};    

    for (int i = 0; i < 3; i++)
    {
        if (tab_str[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*tabCreateForm[i])(formTarget));
        }
    }
    throw std::invalid_argument("Not existing please make sure you have [shrubbery request, presidential request, robotomy request]");
}

Intern::~Intern(void)
{
    //std::cout << "Intern destructor called" << std::endl;
}