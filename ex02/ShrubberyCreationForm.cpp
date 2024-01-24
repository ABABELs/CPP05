/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:45:01 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 14:51:18 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(NULL, 145, 137)
{
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExec())
{
    *this = src;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    (void) rhs;
    return (*this);
}

void ShrubberyCreationForm::action() const
{
    std::ofstream ofs((this->getTarget() += "_shrubbery").c_str());
    
    ofs << "      /\\      " << std::endl;
    ofs << "     /\\*\\     " << std::endl;
    ofs << "    /\\O\\*\\    " << std::endl;
    ofs << "   /*/\\/\\/\\   " << std::endl;
    ofs << "  /\\O\\/\\*\\/\\  " << std::endl;
    ofs << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    ofs << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "      ||      " << std::endl;
    ofs << "    \\====/    " << std::endl;
    ofs << "     \\__/     " << std::endl;
    ofs.close();
    std::cout << "ShrubberyCreationForm execute on " << getTarget() << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}