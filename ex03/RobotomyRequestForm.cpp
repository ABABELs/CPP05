/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:00:29 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 14:58:04 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp" 

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(NULL, 72, 45)
{
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
    *this = src;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    (void) rhs;
    return (*this);
}

void    RobotomyRequestForm::action() const
{
    int wint;

    std::srand(time(0));
    std::cout << "Bzzzz ! Brrrrrrr ! ZZZZZZZZZ!" << std::endl;
    wint = std::rand() % 2;
    if (wint == 1)
        std::cout << "Robotomy succefully done on " << this->_target << std::endl; 
    else
        std::cout << "Robotomy failed" << std::endl;
}   

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}