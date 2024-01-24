/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:14:05 by babels            #+#    #+#             */
/*   Updated: 2024/01/24 15:25:10 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class.hpp"
#include "AForm.Class.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.Class.hpp"

int main()
{
    Intern someIntern;
	Bureaucrat bureau_1("michel", 45);
	Bureaucrat bureau_2("Karen", 3);
	AForm *form_3 = new ShrubberyCreationForm("home");
	try
	{
		AForm	*form_2 = someIntern.makeForm("rootomy request", "Sam");
		bureau_2.signAForm(*form_2);
		form_2->beSigned(bureau_2);
		form_2->execute(bureau_2);
	}
	catch (Intern::InexistantForm &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		AForm	*form_4 = someIntern.makeForm("presidential pardon", "Dog");
		bureau_2.signAForm(*form_4);
		bureau_2.executeAForm(*form_4);
	}
	catch (Intern::InexistantForm &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << bureau_1 << std::endl;
	std::cout << bureau_2 << std::endl;
	form_3->execute(bureau_2);	
	return (0);
}