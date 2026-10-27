/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:56:16 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:27:48 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try 
    {
        Bureaucrat a("bob", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat a("bob", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("bob", 149);
        std::cout << a;
        a.down_grade();
        std::cout << a;
        a.down_grade();
        std::cout << a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat a("bob", 2);
        std::cout << a;
        a.up_grade();
        std::cout << a;
        a.up_grade();
        std::cout << a;
        a.up_grade();
        std::cout << "test" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("42", 5);
    }
    catch (std::exception &e)
    {
        std::cout << "test normalement y a pas d'erreur" << std::endl;
    }
    Bureaucrat bob("bob", 42);
    Bureaucrat bob_v2(bob);
    std::cout << bob;
    std::cout << bob_v2;
    Bureaucrat bob_v3("bob_v3", 55);
    std::cout << bob_v3;
    bob_v3 = bob_v2;
    std::cout << bob_v3;
    std::cout << "Test fini et les catchs n'arrete pas le programme du main" << std::endl;
    return (0);
}