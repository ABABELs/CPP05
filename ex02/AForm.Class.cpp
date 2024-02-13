/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:57:03 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 12:07:08 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.Class.hpp"

AForm::AForm(std::string const name, int const gradeSign, int const gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    return ;
}

AForm::AForm(AForm const & src) :
    _name(src.getName()), _signed(src.getSigned()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
    *this = src;
	return ;
}

AForm::~AForm(void) 
{
    return ;
}

AForm & AForm::operator=(AForm const & rhs)
{
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string const   AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getSigned(void) const
{
    return this->_signed;
}

int AForm::getGradeSign(void) const
{
	return this->_gradeSign;
}

int AForm::getGradeExec(void) const
{
	return this->_gradeExec;
}

void AForm::beSigned(Bureaucrat &him)
{
	try
	{
		if (him.getGrade() > _gradeSign)
			throw AForm::GradeTooLowException("Grade of the bureaucrat is to low to sign this form");
		else if (_signed == 0)
		{
			_signed = true;
		}
		else
			throw AForm::AFormAlreadySign(" attempt to sign a form already signed : ");
	}
	catch(const AForm::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const AForm::AFormAlreadySign& e)
	{
		std::cerr << him.getName() << e.what() << this->getName() << std::endl;
	}
}

void	AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->getSigned())
			throw AForm::GradeTooHighException("Form is not signed");
		else if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException("Grade executor is too low");
		else
			action();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

AForm::GradeTooHighException::GradeTooHighException( const char *message) : _message(message)
{
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{
	return ;
}

AForm::AFormAlreadySign::AFormAlreadySign(const char *message) : _message(message)
{
	return ;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
	o << rhs.getName() << " is " << (rhs.getSigned() ? "signed" : "not signed") << std::endl;
	return o;
}

