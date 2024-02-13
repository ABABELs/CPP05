/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.Class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:01:04 by babels            #+#    #+#             */
/*   Updated: 2024/02/13 11:27:42 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class.hpp"

Bureaucrat::Bureaucrat(void)
{
    return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            _grade = grade;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
    *this = src;
    return ;
}

Bureaucrat::~Bureaucrat(void)
{
    return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::promote(void)
{
    try
    {
        if (this->_grade <= 1)
            throw Bureaucrat::GradeTooHighException();
        else
            this->_grade--;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::demote(void)
{
    try
    {
        if (this->_grade >= 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade++;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return (o);
}
