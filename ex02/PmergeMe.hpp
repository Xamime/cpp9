/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:13:33 by maxime            #+#    #+#             */
/*   Updated: 2024/02/13 15:43:28 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdlib>
#include <iostream>

typedef struct s_data
{
    int a;
    int b;
}              data;

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        ~PmergeMe();

        void setProperty(Type value);
        Type getProperty() const;

    private:
        std::vector<data> victor;
};

PmergeMe::PmergeMe()
{
    // TODO: Implement constructor
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    // TODO: Implement copy constructor
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        // TODO: Implement copy assignment
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    // TODO: Implement destructor
}

void PmergeMe::setProperty(Type value)
{
    // TODO: Implement setter
}

Type PmergeMe::getProperty() const
{
    // TODO: Implement getter
}