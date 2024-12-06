/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:50:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/06 11:59:11 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

void	fill_vector(std::vector<int> & largeVector) {
	std::srand(static_cast<unsigned int>(std::time(0)));

	for (int i = 0; i < 10000; ++i) {
	largeVector[i] = std::rand();
	}
}

int main()
{
Span sp = Span(5);
Span sp1 = Span(5);
try {
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
sp.addNumber(5);
} catch (std::exception & e) {
	std::cout<<"ERROR : "<<e.what()<<std::endl;
}
try {
sp1.addNumber(6);
std::cout << sp1.shortestSpan() << std::endl;
std::cout << sp1.longestSpan() << std::endl;
} catch (std::exception & e) {
	std::cout<<"ERROR : "<<e.what()<<std::endl;
}
/*MY OWN TESTS*/
std::vector<int> largeVector(10000);
fill_vector(largeVector);
try {
	Span	sp2(15000);

	sp2.addNumberS(largeVector.begin(), largeVector.end());
	sp2.printSpan();
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	sp.addNumberS(largeVector.begin(), largeVector.end());
} catch (std::exception & e) {
	std::cout<<"ERROR : "<<e.what()<<std::endl;
}
return 0;
}
