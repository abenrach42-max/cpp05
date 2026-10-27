/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:57:18 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/08 18:35:39 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class   AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeRequiredToSigned;
        const int           _gradeRequiredToExec;
    public:
        AForm(const std::string name, const int gradeReqToSign, const int gradeReqToExec);
        AForm(const AForm &form);
        AForm    &operator=(const AForm &form);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm(void);
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

std::ostream    &operator<<(std::ostream &os, const AForm &f);

#endif