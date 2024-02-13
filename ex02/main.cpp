/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:12:54 by maxime            #+#    #+#             */
/*   Updated: 2024/02/13 15:50:46 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    std::vector<data> test;
    std::string args = argv[1];
    size_t pos = args.find(' ');
    while (pos != std::string::npos)
    {
        int first = atoi(args.c_str());
        args.erase(0, pos +1);
        pos = args.find(' ');
        
        int second = atoi(args.c_str());
        args.erase(0, pos +1);
        pos = args.find(' ');
        
        test.push_back((data){first, second});
    }
    std::cout << test[0].a;
}