/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:00:15 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/08 18:51:03 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    //std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}
std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeReqToExec())
        throw AForm::GradeTooLowException();
    if (this->_target.empty())
        throw std::invalid_argument("String target is empty");

    std::ofstream   file;
    std::string     filename = this->_target + "_shrubbery";
    
    file.open(filename.c_str(), std::ofstream::out); // pas besoin de mettre un else y a un throw dans cette methode
    if (file.is_open())
    {
        file << "    /\\         /\\       /\\\n";
        file << "   /  \\       /  \\     /  \\\n";
        file << "  /____\\     /____\\   /____\\\n";
        file << "    ||         ||       ||\n";
        file << "    ||         ||       ||\n";
        file << "----||---------||-------||----" << std::endl;
        file.close();
    }
    else
    {
        throw std::runtime_error("Open file fail");
    }
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) : AForm(scf.getName(), scf.getGradeReqToSign(), scf.getGradeReqToExec())
{
    //std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = scf;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
    //std::cout << "ShrubberyCreationForm copy assignement called" << std::endl;
    if (this != &scf)
        this->_target = scf.getTarget();
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    //std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
