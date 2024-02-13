/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:32:06 by maxime            #+#    #+#             */
/*   Updated: 2024/02/11 16:33:40 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int is_operator(int c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void    operation(RPN& test, int c)
{
    int result = 0;
    int previous = test.top();
    test.pop();
    if (c == '+')
    {
        result = previous + test.top();
        test.pop();
        test.push(result);
    }
    else if (c == '-')
    {
        result = test.top() - previous;
        test.pop();
        test.push(result);
    }
    else if (c == '*')
    {
        result = previous * test.top();
        test.pop();
        test.push(result);
    }
    else
    {
        result = test.top() / previous;
        test.pop();
        test.push(result);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "This program take only one argument\n";
        return 1;    
    }
    RPN test;
    std::string string = argv[1];
    int i = 0;
    while (string[i])
    {
        if (isdigit(string[i]) || is_operator(string[i]))
        {
            if (isdigit(string[i]))
            {
                test.push(string[i] - '0');
                if (test.size() > 2)
                {
                    std::cout << "0\n";
                    return 1;
                }
            }
            else if (is_operator(string[i]))
            {
                if (is_operator(string[i - 2]))
                {
                    std::cout << "0\n";
                    return 1;
                }
                operation(test, string[i]);
            }
        }
        else if (string[i] == ' ')
        {
            i++;
            continue;
        }
        else
        {
            std::cout << "Error\n";
            return 1;
        }
        i++;
    }
    std::cout << test.top() << std::endl;
    return 0;
}