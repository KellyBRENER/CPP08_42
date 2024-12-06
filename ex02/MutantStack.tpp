/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:46:29 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/06 12:01:41 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <stack>

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

//rendre std::stack itérable
//dans la définition de la classe std::stack, le container est de type deque par défaut et stocké sous l'attribut privé "c"
template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack() : std::stack<T, Container>() {}
	MutantStack(MutantStack const & src) : std::stack<T, Container>(src) {}
	virtual ~MutantStack() {};
	MutantStack &	operator=(MutantStack const & src) {
		if (*this != src)
			std::stack<T, Container>::operator=(src);
		return *this;
	}
	typedef typename std::stack<T, Container>::container_type::iterator	iterator;//permet de définir une variable iterator du type de container utilisé
	iterator	begin() {
		return(this->c.begin());
	}
	iterator	end() {
		return (this->c.end());
	}
	void	push_back(T data) {
		this->c.push_back(data);
	}
};


#endif
