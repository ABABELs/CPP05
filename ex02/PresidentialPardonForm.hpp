/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:32:10 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 14:32:45 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.Class.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        virtual void action() const;
        std::string getTarget(void) const;
    private:
        PresidentialPardonForm(void);
        std::string _target;
};

#endif