/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:39:29 by maxime            #+#    #+#             */
/*   Updated: 2024/02/15 15:33:35 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
    std::vector<int> tab(5,4);
    std::deque<int> tab1(5,4);
    std::list<int> tab2(5,4);
    try
    {
        easyfind(tab, 4);
        easyfind(tab1, 4);
        easyfind(tab2, 4);
        easyfind(tab2, 3);
    }
    catch(const std::exception& e)
    {
        std::cerr << "No occurence found\n";
    }
    
    return (0);
}