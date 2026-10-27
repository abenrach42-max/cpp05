/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:56:16 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/11 16:18:27 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "==========Intern try to create shrubbery form==========\n" << std::endl;
    try
    {
        Intern  stagiaire;
        Bureaucrat  super_bob("super bob", 1);
        AForm   *scf;
        
        scf = stagiaire.makeForm("shrubbery request", "target");
        std::cout << *scf;
        super_bob.signForm(*scf);
        super_bob.executeForm(*scf);
        delete scf;
        std::cout << "Test 1 complete !!!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n==========Intern try to create robotomy form==========\n" << std::endl;
    try
    {
        Intern  stagiaire;
        Bureaucrat  super_bob("super bob", 1);
        AForm   *rrf;
        
        rrf = stagiaire.makeForm("robotomy request", "bob");
        std::cout << *rrf;
        super_bob.signForm(*rrf);
        super_bob.executeForm(*rrf);
        delete rrf;
        std::cout << "Test 2 complete !!!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n==========Intern try to create presidential form==========\n" << std::endl;
    try
    {
        Intern  stagiaire;
        Bureaucrat  super_bob("super bob", 1);
        AForm   *ppf;
        
        ppf = stagiaire.makeForm("presidential request", "bebe bob");
        std::cout << *ppf;
        super_bob.signForm(*ppf);
        super_bob.executeForm(*ppf);
        delete ppf;
        std::cout << "Test 3 complete !!!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n==========Intern try to create blabla form==========\n" << std::endl;
    try
    {
        Intern  stagiaire;
        Bureaucrat  super_bob("super bob", 1);
        AForm   *ppf;
        
        ppf = stagiaire.makeForm("blabla", "bebe bob");
        std::cout << *ppf;
        super_bob.signForm(*ppf);
        super_bob.executeForm(*ppf);
        delete ppf;
        std::cout << "Test 4 fail !!!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::cout << "Test 4 complete !!!" << std::endl;
    }
    return (0);
}