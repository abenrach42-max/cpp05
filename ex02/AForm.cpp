/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:14:44 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:50:52 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, const int gradeReqToSign, const int gradeReqToExec) : _name(name), _isSigned(false), _gradeRequiredToSigned(gradeReqToSign), _gradeRequiredToExec(gradeReqToExec)
{
    if (this->_gradeRequiredToExec < 1)
        throw (AForm::GradeTooHighException());
    if (this->_gradeRequiredToExec > 150)
        throw (AForm::GradeTooLowException());
    if (this->_gradeRequiredToSigned < 1)
        throw (AForm::GradeTooHighException());
    if (this->_gradeRequiredToSigned > 150)
        throw (AForm::GradeTooLowException());
    //std::cout << "Form constructor is called" << std::endl;
}

const std::string   &AForm::getName(void) const
{
    return (this->_name);
}

int   AForm::getGradeReqToSign(void) const
{
    return (this->_gradeRequiredToSigned);
}

int   AForm::getGradeReqToExec(void) const
{
    return (this->_gradeRequiredToExec);
}

bool    AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

void    AForm::beSigned(const Bureaucrat &bur)
{
    if (this->_gradeRequiredToSigned < bur.getGrade())
        throw (AForm::GradeTooLowException());
    this->_isSigned = true;
    return ;
}

const char  *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade to high for signed or execute this form");
}

const char  *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade to low for signed or execute this form");
}

AForm::AForm(const AForm &form) : _name(form.getName()), _gradeRequiredToSigned(form.getGradeReqToSign()), _gradeRequiredToExec(form.getGradeReqToExec())
{
    *this = form;
}

AForm    &AForm::operator=(const AForm &form)
{
    if (this != &form)
        this->_isSigned = form.getIsSigned();
    return (*this);
}

AForm::~AForm(void)
{
    //std::cout << "Form destrucor called" << std::endl;
}

std::ostream    &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form's name is " << f.getName() << " | Grade to sign is " << f.getGradeReqToSign() << " | Grade to execute is " << f.getGradeReqToExec() << " | ";
    if (f.getIsSigned() == true)
        std::cout << "This form is signed";
    else
        std::cout << "This form is not signed";
    std::cout << std::endl;
    return (os);
}