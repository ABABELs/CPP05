/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:58:19 by aabel             #+#    #+#             */
/*   Updated: 2024/01/24 14:07:29 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.Class.hpp"
#include "stdlib.h"
#include "time.h"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        virtual void action() const;
        std::string getTarget(void) const;
    private:
        RobotomyRequestForm(void);
        std::string _target;
};

#endif