/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:30 by kbrener-          #+#    #+#             */
/*   Updated: 2024/12/06 12:01:47 by kbrener-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main()
{
	//tests from subject
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
//My own test
std::stack<int>	realStack;
MutantStack<int, std::vector<int> >	mstack_vector;
MutantStack<int, std::list<int> >	mstack_list;
MutantStack<int, std::deque<int> >	mstack_deq;
realStack.push(6);
//realStack.push_back(10); not possible
mstack_vector.push(6);
mstack_list.push(6);
mstack_deq.push(6);
mstack_vector.push_back(10);
mstack_list.push_back(10);
mstack_deq.push_back(10);
std::cout<<"top of mstack_deq: "<<mstack_deq.top()<<std::endl;
std::cout<<"size of mstack_list: "<<mstack_list.size()<<std::endl;
std::cout<<"first it of mstack_vector: "<<*mstack_vector.begin()<<std::endl;

return 0;
}

