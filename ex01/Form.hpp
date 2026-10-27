/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:57:18 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/07 18:20:31 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class   Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSigned;
        const int           _gradeRequiredToExec;
    public:
        Form(const std::string name, const int gradeReqToSign, const int gradeReqToExec);
        Form(const Form &form);
        Form    &operator=(const Form &form);
        ~Form(void);
        const std::string   &getName(void) const;
        int     getGradeReqToSign(void) const;
        int     getGradeReqToExec(void) const;
        bool    getIsSigned(void) const;
        void        beSigned(const Bureaucrat &bur);
        class   GradeTooLowException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
        class   GradeTooHighException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const Form &f);

#endif