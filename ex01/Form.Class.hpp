/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:33:44 by babels            #+#    #+#             */
/*   Updated: 2024/01/23 14:24:42 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include <stdexcept>

class Foarm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
        
    public:
        Foarm(std::string const name, int const gradeSign, int const gradeExec);
        Foarm(Foarm const & src);
        ~Foarm(void);
        Foarm & operator=(Foarm const & rhs);

        std::string const   getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExec(void) const;

        void                beSigned(Foarm const & b);
        virtual void        execute(Foarm const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            const char *_message;
            public:
                GradeTooHighException(void);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };

        class GradeTooLowException : public std::exception
        {
            const char *_message;
            public:
                GradeTooLowException(void);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };
        
        class FormAlreadySign: public std::exception
        {
            const char *_message;
            public:
                FormAlreadySign(void);
                virtual const char* what() const throw()
                {
                    return _message;
                }
        };
};

std::ostream & operator<<(std::ostream & o, Foarm const & rhs);

#endif