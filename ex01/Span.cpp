/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:19:15 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/02 10:28:02 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {
	_container.reserve(N);//reserve la place max N
}
Span::Span(Span const & src) {
	*this = src;
}
Span::~Span() {}
Span &	Span::operator=(Span const & src) {
	if (this != &src) {
		_N = src._N;
		_container = src._container;
	}
	return *this;
}
void	Span::addNumber(int nb) {
	if (_container.size() < _N) {
		_container.push_back(nb);
		std::sort(_container.begin(), _container.end());
	}
	else
		throw SpanException("span is full, no more place for an int");
}
int	Span::longestSpan() {
	if (_container.size() > 1)
		return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
	else
		throw SpanException("not enough number to calculate a distance");
}
int	Span::shortestSpan() {
	if (_container.size() > 1) {
		std::vector<int>::iterator	it;
		int diff;
		int diff_min = std::numeric_limits<int>::max();
		for (it = _container.begin() + 1; it != _container.end(); ++it) {
			diff = *it - *(it - 1);
			if (diff < diff_min)
				diff_min = diff;
		}
		return diff_min;
	}
	else
		throw SpanException("not enough number to calculate a distance");
}
void	Span::addNumberS(std::vector<int>::iterator it_start, std::vector<int>::iterator it_end) {
	int add_size = std::distance(it_start, it_end);//calcule le nombre d'éléments entre first et last
	if (add_size <= 0)
		throw SpanException("no number to add to Span");
	if (static_cast<unsigned int>(add_size) <= _N - _container.size()) {//check s'il reste assez de place pour les nombres à ajouter
		_container.insert(_container.end(), it_start, it_end);//rajoute à la fin du container les nombres de start à end
		std::sort(_container.begin(), _container.end());
	}
	else
		throw SpanException("not enough place in span to add all int given in argument");
}
void	Span::printSpan() {
	for (unsigned int i = 0; i < _container.size(); ++i)
		std::cout<<_container[i]<<" | ";
	std::cout<<std::endl;
}

