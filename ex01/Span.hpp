/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:44:28 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/02 10:27:17 by kbrener-         ###   ########.fr       */
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
	Span();
	Span(unsigned int N);
	Span(Span const & src);
	~Span();
	Span &	operator=(Span const & src);
	class SpanException : public std::exception {
		private:
			std::string	_message;
		public:
			SpanException(std::string const & message) : _message(message) {}
			virtual ~SpanException() throw() {}
			virtual const char* what() const throw() {
				return _message.c_str();
			}
	};

	void	addNumber(int nb);
	int	longestSpan();
	int	shortestSpan();
	void	addNumberS(std::vector<int>::iterator it_start, std::vector<int>::iterator it_end);
	void	printSpan();
};
