/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:33:44 by babels            #+#    #+#             */
/*   Updated: 2024/01/24 12:00:48 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.Class.hpp"

class Bureaucrat;

class Form
{
    private:
        Form();
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
        
    public:
        Form(std::string const name, int const gradeSign, int const gradeExec);
        Form(Form const & src);
        ~Form(void);
        Form & operator=(Form const & rhs);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExec(void) const;
        void                beSigned(Bureaucrat &him);

        class GradeTooHighException : public std::exception
        {
            const char *_message;
            public:
                GradeTooHighException(const char *message);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };

        class GradeTooLowException : public std::exception
        {
            const char *_message;
            public:
                GradeTooLowException(const char *message);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };
        
        class FormAlreadySign: public std::exception
        {
            const char *_message;
            public:
                FormAlreadySign(const char *message);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif