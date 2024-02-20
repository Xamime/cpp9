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