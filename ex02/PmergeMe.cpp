

#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>
#include "PmergeMe.hpp"

# define MICROSECOND 100000

unsigned int ft_stou(const std::string& str);

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};

static void printVec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
    std::vector<unsigned int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec)
{
    if (vec.size() <= 1) {
        return vec;
    }

    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    left = mergeInsertVec(left);
    right = mergeInsertVec(right);

    return mergeVecs(left, right);
}

void PmergeMe::sortVec(int argc, char **argv)
{
	std::vector<unsigned int> storage;

	for (int i = 1; i < argc; i += 1) {
		storage.push_back(ft_stou(argv[i]));
	}

	std::cout << "Before: ";
	printVec(storage);

	std::clock_t start = std::clock();

	storage = mergeInsertVec(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << "After: ";
	printVec(storage);

	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " µs";
}

static std::list<unsigned int> mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right)
{
    std::list<unsigned int> result;

    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int>& lst) {
    if (lst.size() <= 1) {
        return lst;
    }

    int mid = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

    for (int i = 0; i < mid; i++) {
        left.push_back(lst.front());
        lst.pop_front();
    }
    right = lst;

    left = mergeInsertList(left);
    right = mergeInsertList(right);

    return mergeLists(left, right);
}

void PmergeMe::sortList(int argc, char **argv)
{
	std::list<unsigned int> storage;

	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

	std::clock_t start = std::clock();

	storage = mergeInsertList(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	std::cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " µs" << std::endl;
}

const char*	PmergeMe::InvalidElementException::what() const throw() {
	return "PmergeMe exception: invalid element";
}