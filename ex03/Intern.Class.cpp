/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:12:00 by aabel             #+#    #+#             */
/*   Updated: 2024/02/13 13:00:45 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.Class.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.Class.hpp"
#include "Intern.Class.hpp"

Intern::Intern(void) 
{
    return ; 
}

Intern::Intern(Intern const & src) 
{
    *this = src; 
    return ;
}

Intern::~Intern(void) 
{
    return ; 
}

Intern & Intern::operator=(Intern const & rhs) 
{
    if (this != &rhs)
    {
        return (*this); 
    }
    return (*this);   
}

AForm * Intern::makeForm(std::string type, std::string target)
{
    AForm *(Intern::*arrayPtr[3])(std::string target) = {&Intern::_makeShrubberyCreationForm, &Intern::_makeRobotomyRequestForm, &Intern::_makePresidentialPardonForm};
    std::string arrayStr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if (type == arrayStr[i])
        {
            std::cout << "Intern creates " << type << std::endl;
            return ((this->*arrayPtr[i])(target));
        }
    }
    throw Intern::InexistantForm();
}

AForm * Intern::_makeShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::_makeRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm * Intern::_makePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

std::ostream & operator<<(std::ostream & o, Intern const & rhs)
{
    (void)rhs;
    return (o);
}
