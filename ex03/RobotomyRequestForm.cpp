/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:00:06 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/09 15:14:22 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    //std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : AForm(rrf.getName(), rrf.getGradeReqToSign(), rrf.getGradeReqToExec())
{
    *this = rrf;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
    if (this != &rrf)
        this->_target = rrf.getTarget();
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeReqToExec())
        throw AForm::GradeTooLowException();
    if (this->_target.empty())
        throw std::invalid_argument("String target is empty");
    
    srand(time(NULL));
    int x = rand();

    if (x <= (RAND_MAX / 2))
        std::cout << "Bzzzzzzzzzzzzzzzzzz...\n" << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy fail to " << this->_target << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    //std::cout << "RobotomyRequestForm destructor called" << std::endl;
}