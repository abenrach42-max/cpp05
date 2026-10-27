/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:00:08 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/09 15:17:19 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &rrf);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rrf);
        ~RobotomyRequestForm(void);
        std::string getTarget(void) const;
        void    execute(Bureaucrat const &executor) const;
};

#endif