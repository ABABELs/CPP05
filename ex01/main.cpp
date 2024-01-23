/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babels <babels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:14:05 by babels            #+#    #+#             */
/*   Updated: 2024/01/21 12:18:41 by babels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.Class.hpp"

int main()
{
    Bureaucrat worker1("worker1", 1);
    Bureaucrat worker2("worker2", 150);

    std::cout << worker1 << std::endl;
    std::cout << worker2 << std::endl;
    worker1.promote();
    worker2.promote();
    std::cout << worker1 << std::endl;
    std::cout << worker2 << std::endl;
    std::cout << std::endl;

    worker1.demote();
    worker1.demote();
    worker2.demote();
    worker2.demote();
    std::cout << worker1 << std::endl;
    std::cout << worker2 << std::endl;
    std::cout << std::endl;

    Bureaucrat worker3("worker3", -42);
    Bureaucrat worker4("worker4", 420);
    std::cout << worker3 << std::endl;
    std::cout << worker4 << std::endl;

    return (0);
}