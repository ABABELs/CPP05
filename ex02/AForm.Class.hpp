/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:33:44 by babels            #+#    #+#             */
/*   Updated: 2024/01/24 12:00:48 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_CLASS_HPP
# define AForm_CLASS_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.Class.hpp"

class Bureaucrat;

class AForm
{
    private:
        AForm();
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
        
    public:
        AForm(std::string const name, int const gradeSign, int const gradeExec);
        AForm(AForm const & src);
        ~AForm(void);
        AForm & operator=(AForm const & rhs);
        void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;

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
        
        class AFormAlreadySign: public std::exception
        {
            const char *_message;
            public:
                AFormAlreadySign(const char *message);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif