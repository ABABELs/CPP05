/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:14:05 by babels            #+#    #+#             */
/*   Updated: 2024/01/24 12:19:52 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class.hpp"
#include "Form.Class.hpp"

int main()
{
    Bureaucrat bureau_1("michel", 15);
	Bureaucrat bureau_2("Karen", 50);
	Form contract("Contract_1", 40, 80);
    Form contract2("Contract_2", 150, 150);

	std::cout << bureau_1 << std::endl;
	std::cout << bureau_2 << std::endl;
	std::cout << contract << std::endl;
    std::cout << contract2 << std::endl;
    
    bureau_2.signForm(contract);
	bureau_1.signForm(contract);
	contract.beSigned(bureau_1);
	bureau_2.signForm(contract2);
    contract2.beSigned(bureau_2);
	bureau_1.signForm(contract2);

    return (0);
}