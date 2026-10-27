/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:56:16 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:43:20 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    // verification des initialisation de bureaucrat
    // initialisation incorrect
    try
    {
        Bureaucrat bob("bob", 151);
        std::cout << "test non reussi" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bob("bob", 0);
        std::cout << "test non reussi" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    //initialisation correct
    try
    {
        Bureaucrat bob("bob", 1);
        std::cout << "test bob grade 1 reussi car bon parametre grade (entre 1 et 150)" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    //verification des initialisation dans Form
    //initialisation incorrect
    try
    {
        Form att_sco("attestation de scolarite", 0, 0);
        std::cout << "test non reussi" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form att_sco("attestation de scolarite", 600, 300);
        std::cout << "test non reussi" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form att_sco("attestation de scolarite", 50, 5);
        std::cout << "test reussi" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    //verification de l'exo
    Bureaucrat bob("bob", 5);
    Bureaucrat bibi("bibi", 1);
    Form att_sco("attestation de scolarite", 1, 1);
    std::cout << att_sco;
    bob.up_grade();
    bob.up_grade();
    bob.up_grade();
    std::cout << bob;
    //bob.up_grade();
    bob.signForm(att_sco);
    bibi.signForm(att_sco);
    bibi.signForm(att_sco);
    std::cout << att_sco;
    Form blabla("blablacar", 5, 5);
    std::cout << blabla;
    blabla = att_sco;
    std::cout << blabla;
    return (0);
}