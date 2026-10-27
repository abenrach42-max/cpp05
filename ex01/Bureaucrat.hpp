/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:25:05 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:20:45 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class   Bureaucrat
{
    private:
        const std::string   _name;
        int           _grade;
    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &bur);
        Bureaucrat  &operator=(const Bureaucrat &bur);
        ~Bureaucrat(void);
        const std::string   getName(void) const;
        int           getGrade(void) const;
        void                up_grade(void);
        void                down_grade(void);
        void                signForm(Form &form);
        class               GradeTooHighException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class               GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif