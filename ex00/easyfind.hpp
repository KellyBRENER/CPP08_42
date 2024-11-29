/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:23:34 by kbrener-          #+#    #+#             */
/*   Updated: 2024/11/29 11:30:41 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <algorithm>
#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include <exception>

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

class	TargetNotFind : public std::exception {
	private:
	std::string	_message;
	public:
	TargetNotFind(std::string const & message) : _message(message) {}
	virtual ~TargetNotFind() throw() {}
	virtual const char* what() const throw() {
		return (_message.c_str());
	}
};

template<typename T>
typename T::iterator	easyfind(T & container, int n) {
	typename T::iterator	it;
	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return it;
	else
		throw TargetNotFind("target not find in the container");
}

#endif
