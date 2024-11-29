/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:50:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/29 16:33:03 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()


int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

/*MY OWN TESTS*/
const int SIZE = 10000;
std::vector<int> largeVector(SIZE);

std::srand(static_cast<unsigned int>(std::time(0)));

for (int i = 0; i < SIZE; ++i) {
	largeVector[i] = std::rand();
}
try {
	Span	sp2(15000);

	sp2.addNumberS(largeVector.begin(), largeVector.end());
	sp2.printSpan();
	sp.addNumberS(largeVector.begin(), largeVector.end());
} catch (std::exception & e) {
	std::cout<<"ERROR : "<<e.what()<<std::endl;
}
return 0;
}
