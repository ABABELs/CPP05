/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:07:48 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 15:28:34 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <string>
# include "AForm.Class.hpp"

class Intern
{
    public:
        class InexistantForm : public std::exception
        {
            public:
                virtual const char * what() const throw()
                {
                    return ("Form does not exist");
                }
        };
        
        Intern(void);
        Intern(Intern const & src);
        ~Intern(void);
        Intern & operator=(Intern const & rhs);

        AForm * makeForm(std::string type, std::string target);
        AForm * _makeShrubberyCreationForm(std::string target);
        AForm * _makeRobotomyRequestForm(std::string target);
        AForm * _makePresidentialPardonForm(std::string target);
};

#endif