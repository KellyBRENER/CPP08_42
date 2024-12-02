/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:46:29 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/02 12:05:56 by kbrener-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <stack>

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

//rendre std::stack itérable
//dans la définition de la classe std::stack, le container est de type deque par défaut et stocké sous l'attribut privé "c"
template< typename T = int>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(MutantStack const & src) : std::stack<T>(src) {}
	virtual ~MutantStack() {};
	MutantStack &	operator=(MutantStack const & src) {
		if (*this != src)
			std::stack<T>::operator=(src);
		return *this;
	}
	typedef typename std::stack<T>::container_type::iterator	iterator;//permet de définir une variable iterator du type de container utilisé
	iterator	begin() {
		return(this->c.begin());
	}
	iterator	end() {
		return (this->c.end());
	}
};


#endif
