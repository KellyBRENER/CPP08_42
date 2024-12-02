/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:49:23 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/02 11:38:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {

	int	int_tab[] = {51, 84512, 4 ,68, 7, 5, 4};
	int* end =  int_tab + sizeof(int_tab) / sizeof(int);
	std::list<int>		int_list(int_tab, end); 
	std::vector<int>	int_vector(int_tab, end); 
	std::deque<int>		int_deque(int_tab, end);

	try {
	std::cout<<*easyfind(int_list, 4)<<std::endl;
	std::cout<<*easyfind(int_list, 2)<<std::endl;
	} catch (std::exception & e) {
		std::cout<<"ERROR : "<<e.what()<<std::endl;
	}
	try {
	std::cout<<*easyfind(int_vector, 4)<<std::endl;
	std::cout<<*easyfind(int_vector, 2)<<std::endl;
	} catch (std::exception & e) {
		std::cout<<"ERROR : "<<e.what()<<std::endl;
	}
	try {
	std::cout<<*easyfind(int_deque, 4)<<std::endl;
	std::cout<<*easyfind(int_deque, 2)<<std::endl;
	} catch (std::exception & e) {
		std::cout<<"ERROR : "<<e.what()<<std::endl;
	}
}
