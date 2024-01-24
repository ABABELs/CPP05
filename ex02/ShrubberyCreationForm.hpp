/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:39:47 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 14:49:06 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.Class.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        virtual void action() const;
        std::string getTarget(void) const;
    private:
        ShrubberyCreationForm(void);
        std::string _target;
};

#endif