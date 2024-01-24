/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:57:03 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 12:07:08 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.Class.hpp"

Form::Form(std::string const name, int const gradeSign, int const gradeExec) :
    _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    return ;
}

Form::Form(Form const & src) :
    _name(src.getName()), _signed(src.getSigned()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
    *this = src;
}

Form::~Form(void) 
{
    return ;
}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string const   Form::getName(void) const
{
    return this->_name;
}

bool Form::getSigned(void) const
{
    return this->_signed;
}

int Form::getGradeSign(void) const
{
	return this->_gradeSign;
}

int Form::getGradeExec(void) const
{
	return this->_gradeExec;
}

void Form::beSigned(Bureaucrat &him)
{
	try
	{
		if (him.getGrade() > _gradeSign)
			throw Form::GradeTooLowException("Bureaucrat grade is too low");
		else if (_signed == 0)
		{
			_signed = true;
			std::cout << him.getName() << " signs " << this->getName() << std::endl;
		}
		else
			throw Form::FormAlreadySign("Form is already sign ");
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const Form::FormAlreadySign& e)
	{
		std::cerr << e.what() <<him.getName() << e.what() << this->getName() << std::endl;
	}
}

Form::GradeTooHighException::GradeTooHighException( const char *message) : _message(message)
{
	return ;
}

Form::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{
	return ;
}

Form::FormAlreadySign::FormAlreadySign(const char *message) : _message(message)
{
	return ;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << " is " << (rhs.getSigned() ? "signed" : "not signed") << std::endl;
	return o;
}

