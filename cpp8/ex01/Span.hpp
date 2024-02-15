/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:49 by maxime            #+#    #+#             */
/*   Updated: 2024/02/15 15:41:25 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int N);
        int     shortestSpan();
        int     longestSpan();
        void    fillSpan(unsigned int N);
        class TooMuchNumbers : public std::exception
        {
            public:
		        const char *what(void) const throw();        
        };
        class TooFewNumbers : public std::exception
        {
            public:
		        const char *what(void) const throw();        
        };
    private:
        std::vector<int> _array;
        unsigned long _numbers;
};
