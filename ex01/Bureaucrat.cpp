/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:24:51 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/11 16:26:12 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
    //std::cout << "Bureaucrat constructor called" << std::endl;
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

const std::string   Bureaucrat::getName(void) const
{
    return (this->_name);
}

void    Bureaucrat::up_grade(void)
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
    return ;
}

void    Bureaucrat::down_grade(void)
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
    return ;
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        if (form.getIsSigned() == true)
        {
            std::cout << form.getName() << " is already signed" << std::endl;
            return ;
        }
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    return ;
}

const char  *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade to high");
}

const char  *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade to low");
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : _name(bur.getName())
{
    *this = bur;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &bur)
{
    if (this != &bur)
        this->_grade = bur.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &bur)
{
    os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
    return (os);
}