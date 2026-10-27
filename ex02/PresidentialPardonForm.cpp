/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:00:01 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/09 17:24:57 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    //std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) : AForm(ppf.getName(), ppf.getGradeReqToSign(), ppf.getGradeReqToExec())
{
    *this = ppf;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf)
{
    if (this != &ppf)
        this->_target = ppf.getTarget();
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeReqToExec())
        throw AForm::GradeTooLowException();
    if (this->_target.empty())
        throw std::invalid_argument("String target is empty");
    
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    //std::cout << "PresidentialPardonForm destructor called" << std::endl;
}