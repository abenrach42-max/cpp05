/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:56:16 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/09 17:36:52 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::cout << "==========Test for Shurberrycreationform==========\n" << std::endl;
    try
    {
        AForm   *x = new ShrubberyCreationForm("tree");
        std::cout << x->getName() << " | grade to sign : " << x->getGradeReqToSign() << " | grade to execute : " << x->getGradeReqToExec() << std::endl;
        Bureaucrat bob("bob", 146);
        std::cout << bob;
        bob.signForm(*x);
        bob.up_grade();
        std::cout << bob;
        bob.signForm(*x);
        bob.signForm(*x);
        for (int i = 0; i < 8; i++)
            bob.up_grade();
        //bob.down_grade();
        std::cout << bob;
        bob.executeForm(*x);
        delete x;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n==========Test for RobomyRequestform==========\n" << std::endl;
    try
    {
        AForm   *rrf = new RobotomyRequestForm("tung tung sahur");
        std::cout << *rrf;
        Bureaucrat  bob("bob", 73);
        bob.signForm(*rrf);
        bob.up_grade();
        bob.signForm(*rrf);
        for (int i = 0; i < (72 - 45) - 1; i++)
            bob.up_grade();
        std::cout << bob;
        bob.executeForm(*rrf);
        bob.up_grade();
        std::cout << bob;
        bob.executeForm(*rrf);
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n\n==========Test for Presidentialpardon==========\n" << std::endl;
    try
    {
        AForm   *ppf = new PresidentialPardonForm("bebe bob");
        Bureaucrat  bob("bob", 25);
        std::cout << *ppf;
        std::cout << bob;
        bob.signForm(*ppf);
        bob.signForm(*ppf);
        bob.executeForm(*ppf);
        for (int i = 0; i < (25 - 5); i++)
            bob.up_grade();
        std::cout << bob;
        bob.executeForm(*ppf);
        delete ppf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat  super_bob("super bob", 1);
        AForm   *ppf = new PresidentialPardonForm("bebe bob");
        AForm   *rrf = new RobotomyRequestForm("bob");
        AForm   *scf = new ShrubberyCreationForm("target");

        std::cout << *ppf;
        std::cout << *rrf;
        std::cout << *scf;
        std::cout << super_bob;
        super_bob.signForm(*ppf);
        super_bob.signForm(*rrf);
        super_bob.signForm(*scf);
        super_bob.executeForm(*ppf);
        super_bob.executeForm(*rrf);
        super_bob.executeForm(*scf);
        delete rrf;
        delete ppf;
        delete scf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n=============================================================" << std::endl;
    return (0);
}