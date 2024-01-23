/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:57:03 by aabel             #+#    #+#             */
/*   Updated: 2024/01/23 14:24:28 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.Class.hpp"

Foarm::Foarm(std::string const name, int const gradeSign, int const gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Foarm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Foarm::GradeTooLowException();
}

Foarm::Foarm(Foarm const & src) :
    _name(src.getName()), _signed(src.getSigned()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
    *this = src;
}

Foarm::~Foarm(void) 
{
    return ;
}

Foarm & Foarm::operator=(Foarm const & rhs)
{
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string const   Foarm::getName(void) const
{
    return this->_name;
}

bool Foarm::getSigned(void) const
{
    return this->_signed;
}

int Foarm::getGradeSign(void) const
{
	return this->_gradeSign;
}

int Foarm::getGradeExec(void) const
{
	return this->_gradeExec;
}

void Foarm::beSigned(Foarm const & b)
{
	if (b.getGradeSign() > this->_gradeSign)
		throw Foarm::GradeTooLowException();
	else
		this->_signed = true;
}

Foarm::GradeTooHighException::GradeTooHighException(void) :
	_message("Grade is too high")
{
	return ;
}

Foarm::GradeTooLowException::GradeTooLowException(void) :
	_message("Grade is too low")
{
	return ;
}

Foarm::FormAlreadySign::FormAlreadySign(void) :
	_message("Form is already sign")
{
	return ;
}

std::ostream & operator<<(std::ostream & o, Foarm const & rhs)
{
	o << rhs.getName() << " is " << (rhs.getSigned() ? "signed" : "not signed") << std::endl;
	return o;
}

