/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:14:44 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:36:05 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int gradeReqToSign, const int gradeReqToExec) : _name(name), _isSigned(false), _gradeRequiredToSigned(gradeReqToSign), _gradeRequiredToExec(gradeReqToExec)
{
    if (this->_gradeRequiredToExec < 1)
        throw (Form::GradeTooHighException());
    if (this->_gradeRequiredToExec > 150)
        throw (Form::GradeTooLowException());
    if (this->_gradeRequiredToSigned < 1)
        throw (Form::GradeTooHighException());
    if (this->_gradeRequiredToSigned > 150)
        throw (Form::GradeTooLowException());
    //std::cout << "Form constructor is called" << std::endl;
}

const std::string   &Form::getName(void) const
{
    return (this->_name);
}

int   Form::getGradeReqToSign(void) const
{
    return (this->_gradeRequiredToSigned);
}

int   Form::getGradeReqToExec(void) const
{
    return (this->_gradeRequiredToExec);
}

bool    Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

void    Form::beSigned(const Bureaucrat &bur)
{
    if (this->_gradeRequiredToSigned < bur.getGrade())
        throw (Form::GradeTooLowException());
    this->_isSigned = true;
    return ;
}

const char  *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade to high for signed or execute this form");
}

const char  *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade to low for signed or execute this form");
}

Form::Form(const Form &form) : _name(form.getName()), _gradeRequiredToSigned(form.getGradeReqToSign()), _gradeRequiredToExec(form.getGradeReqToExec())
{
    *this = form;
}

Form    &Form::operator=(const Form &form)
{
    if (this != &form)
        this->_isSigned = form.getIsSigned();
    return (*this);
}

Form::~Form(void)
{
    //std::cout << "Form destrucor called" << std::endl;
}

std::ostream    &operator<<(std::ostream &os, const Form &f)
{
    os << "Form's name is " << f.getName() << " | Grade to sign is " << f.getGradeReqToSign() << " | Grade to execute is " << f.getGradeReqToExec() << " | ";
    if (f.getIsSigned() == true)
        std::cout << "This form is signed";
    else
        std::cout << "This form is not signed";
    std::cout << std::endl;
    return (os);
}