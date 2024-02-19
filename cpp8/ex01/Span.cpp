/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:33:02 by maxime            #+#    #+#             */
/*   Updated: 2024/02/19 13:19:05 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char *Span::TooMuchNumbers::what(void) const throw()
{
    return ("You cannot add more numbers");
}

const char *Span::TooFewNumbers::what(void) const throw()
{
    return ("Not enough numbers stored");
}

Span::Span()
{
    _numbers = 0;
}

Span::Span(unsigned int N)
{
    _numbers = N;
}

Span::Span(const Span& other)
{
    (void)other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
    }
    return *this;
}

void    Span::fillSpan(unsigned int N)
{
    std::srand(int(std::time(NULL)));
    _array.resize(N);
    std::generate(_array.begin(), _array.end(), std::rand);
}

int    Span::shortestSpan()
{
    if (_array.size() < 2)
        throw Span::TooFewNumbers();
    std::sort(_array.begin(), _array.end());
    int comp = _array[1] - _array[0];
    for (int i = 0; i < (int)_numbers - 1; i++){
        if (comp > (_array[i + 1] - _array[i]))
            comp = _array[i + 1] - _array[i];
    }
    return (comp);
}

int    Span::longestSpan()
{
    if (_array.size() < 2)
        throw Span::TooFewNumbers();
    int min = *std::min_element(_array.begin(), _array.end());
    int max = *std::max_element(_array.begin(), _array.end());
    return (max - min);
}

void    Span::addNumber(int N)
{
    if (_array.size() >= _numbers)
        throw Span::TooMuchNumbers();
    _array.push_back(N);
}

Span::~Span() {
}