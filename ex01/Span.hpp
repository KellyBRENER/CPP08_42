/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/29 16:33:23 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <limits>

class Span {
private:
	unsigned int	_N;
	std::vector<int>		_container;
public:
	Span() : _N(0) {}
	Span(unsigned int N) : _N(N) {
		_container.reserve(N);//reserve la place max N
	}
	Span(Span const & src) {
		*this = src;
	}
	~Span() {}
	Span &	operator=(Span const & src) {
		if (this != &src) {
			_N = src._N;
			_container = src._container;
		}
		return *this;
	}
	class SpanIsFull : public std::exception {
		private:
			std::string	_message;
		public:
			SpanIsFull(std::string const & message) : _message(message) {}
			virtual ~SpanIsFull() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}
	};
	class	DistanceException : std::exception {
		private:
			std::string	_message;
		public:
			DistanceException(std::string const & message) : _message(message) {}
			virtual ~DistanceException() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}
	};

	void	addNumber(int nb) {
		if (_container.size() < _N) {
			_container.push_back(nb);
			std::sort(_container.begin(), _container.end());
		}
		else
			throw SpanIsFull("span is full, no more place for an int");
	}
	int	longestSpan() {
		if (_container.size() <= 1)
			throw DistanceException("not enough number to calculate a distance");
		return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
	}
	int	shortestSpan() {
		if (_container.size() <= 1)
			throw DistanceException("not enough number to calculate a distance");
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
	void	addNumberS(std::vector<int>::iterator it_start, std::vector<int>::iterator it_end) {
		int add_size = std::distance(it_end, it_start);
		if (add_size < 0)
			throw DistanceException("no number to add to Span");
		if (static_cast<unsigned int>(add_size) <= _N - _container.size()) {
			_container.insert(_container.end(), it_start, it_end);
		}
		else
			throw SpanIsFull("not enough place in span to add all int given in argument");
	}
	void	printSpan() {
		for (unsigned int i = 0; i < _container.size(); ++i)
			std::cout<<_container[i]<<" | ";
		std::cout<<std::endl;
	}
};
