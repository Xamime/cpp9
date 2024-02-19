/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:33:37 by maxime            #+#    #+#             */
/*   Updated: 2024/02/19 13:07:31 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PMERGEME_
#define _PMERGEME_

# include <exception>

class PmergeMe {

    public:
		PmergeMe();
		PmergeMe & operator=(PmergeMe const & old);
		PmergeMe(PmergeMe const & old);
        ~PmergeMe(void);

        void sortVec(int argc, char **argv);
        void sortList(int argc, char **argv);

        class InvalidElementException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif