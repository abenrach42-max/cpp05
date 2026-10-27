/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:00:04 by abenrach          #+#    #+#             */
/*   Updated: 2026/10/09 17:19:27 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string   _target;
    public:
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &ppf);
        PresidentialPardonForm    &operator=(const PresidentialPardonForm &ppf);
        void    execute(Bureaucrat const &executor) const;
        ~PresidentialPardonForm(void);
        std::string   getTarget(void) const;
};

#endif