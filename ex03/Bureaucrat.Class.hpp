/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.Class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:29:48 by babels            #+#    #+#             */
/*   Updated: 2024/01/24 14:45:49 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.Class.hpp"

class AForm;

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("Grade too high !");
                }      
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("Grade too low !");
                }      
        };
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat(void);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        std::string getName(void) const;
        int getGrade(void) const;
        void promote(void);
        void demote(void);
        void signAForm(AForm &AForm);
        void executeAForm(AForm const &form);
    private:
        Bureaucrat(void);
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif