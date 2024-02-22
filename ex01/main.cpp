/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:32:06 by maxime            #+#    #+#             */
/*   Updated: 2024/02/22 14:20:05 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int is_operator(int c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

void    operation(RPN& rpn, int c)
{
    int result = 0;
    int previous = rpn.top();
    rpn.pop();
    if (c == '+')
    {
        result = previous + rpn.top();
        rpn.pop();
        rpn.push(result);
    }
    else if (c == '-')
    {
        result = rpn.top() - previous;
        rpn.pop();
        rpn.push(result);
    }
    else if (c == '*')
    {
        result = previous * rpn.top();
        rpn.pop();
        rpn.push(result);
    }
    else
    {
        if (previous == 0)
            throw std::exception();
        result = rpn.top() / previous;
        rpn.pop();
        rpn.push(result);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "This program take only one argument\n";
        return 1;    
    }
    RPN rpn;
    std::string string = argv[1];
    int i = 0;
    try
    {
        while (string[i])
        {
            if (isdigit(string[i]))
                rpn.push(string[i] - '0');
            else if (is_operator(string[i]) && rpn.size() > 1)
                operation(rpn, string[i]);
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
        if (!rpn.empty() && rpn.size() == 1)
            std::cout << rpn.top() << std::endl;
        else
            std::cout << "Error\n";
    }
    catch (std::exception &e) 
    {
        std::cout << "cant divide by 0\n";
    }
    return 0;
}