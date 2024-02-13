/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:14:05 by babels            #+#    #+#             */
/*   Updated: 2024/02/13 12:45:53 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class.hpp"
#include "AForm.Class.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Bureaucrat bureau_1("michel", 1500);
	// Bureaucrat bureau_1("michel", 0);
	Bureaucrat bureau_1("michel", 45);
	Bureaucrat bureau_2("Karen", 3);
	AForm *form_1 = new RobotomyRequestForm("Leon");
	AForm *form_2 = new PresidentialPardonForm("Arthur");
	AForm *form_3 = new ShrubberyCreationForm("Sam");

	std::cout << bureau_1 << std::endl;
	std::cout << bureau_2 << std::endl;
	std::cout << std::endl;

	bureau_1.signAForm(*form_1);
	form_1->beSigned(bureau_1);
	bureau_1.executeAForm(*form_1);
	bureau_2.signAForm(*form_1);
	std::cout << std::endl;

	bureau_1.signAForm(*form_2);
	bureau_1.executeAForm(*form_2);
	bureau_2.signAForm(*form_2);
	bureau_1.executeAForm(*form_2);
	bureau_2.executeAForm(*form_2);
	std::cout << std::endl;

	bureau_1.signAForm(*form_3);
	form_3->beSigned(bureau_1);
	bureau_2.executeAForm(*form_3);

    return (0);
}