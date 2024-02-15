/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:39:50 by maxime            #+#    #+#             */
/*   Updated: 2024/01/21 13:37:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <iterator>
#include <cstddef>

template<class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack& other) {(void)other;};
        MutantStack& operator=(const MutantStack& other) {(void)(other);};
    
        virtual ~MutantStack() {};
        struct iterator : public std::iterator<std::forward_iterator_tag, std::ptrdiff_t, T, const T*, T&>
        {
            public:
                iterator(typename std::stack<T>::container_type::iterator iter) : ptr(iter) {}
                T& operator*() const { return *ptr; }
                T* operator->() { return ptr; }
                iterator& operator--() { ptr--; return *this; }
                iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
                iterator& operator++() { ptr++; return *this; }
                iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
                friend bool operator== (const iterator& a, const iterator& b) { return a.ptr == b.ptr; }
                friend bool operator!= (const iterator& a, const iterator& b) { return a.ptr != b.ptr; }
            private:
                typename std::stack<T>::container_type::iterator ptr;
        };
        iterator begin() {
            return iterator(this->c.begin());
        }
        iterator end() { 
            return iterator(this->c.end());
        }
};

#endif