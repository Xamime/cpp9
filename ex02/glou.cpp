/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glou.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:12:54 by maxime            #+#    #+#             */
/*   Updated: 2024/02/13 19:24:29 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>
#include <cstdlib>
#include <iostream>
//todo parsing si lettre, plusieurs espaces

int jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> build_jacob_insertion_sequence(const std::vector<int>& array) {
    std::vector<int> end_sequence;
    int array_len = static_cast<int>(array.size());
    size_t jacob_index = 3;

    while (jacobsthal(jacob_index) < array_len - 1) {
        end_sequence.push_back(jacobsthal(jacob_index));
        ++jacob_index;
    }

    return end_sequence;
}

std::vector<int> create_s(const std::vector<std::pair<int, int> >& sorted_split_array, int straggler, bool print_comparison_estimation)
{
    std::vector<int> S;
    std::vector<int> pend;
    int                 item = 0;

    for (size_t i = 0; i < sorted_split_array.size(); ++i) {
        S.push_back(sorted_split_array[i].second);
        pend.push_back(sorted_split_array[i].first);
    }

    S.insert(S.begin(), pend[0]);

    size_t iterator = 0;
    size_t jacobindex = 3;
    std::vector<int> index_sequence;
    index_sequence.push_back(1);
    std::string last = "default";

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend);

    while (iterator <= pend.size()) {
        if (!jacob_insertion_sequence.empty() && last != "jacob") {
            index_sequence.push_back(jacob_insertion_sequence[0]);
            item = pend[jacob_insertion_sequence[0] - 1];
            jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
            last = "jacob";
        } else {
            if (iterator < index_sequence.size() && iterator == static_cast<size_t>(index_sequence[iterator - 1]))
                ++iterator;
            item = pend[iterator - 1];
            index_sequence.push_back(iterator);
            last = "not-jacob";
        }

        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        S.insert(insertion_point, item);
        ++iterator;
        ++jacobindex;
    }

    if (straggler) {
        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
    }
    return S;
}

void    create_pair(std::vector<int> crash, std::vector<std::pair<int,int> >& pairred)
{
    std::pair<int, int>   value;
    for(unsigned long i = 0; i < crash.size(); i += 2)
    {
        value.first = crash[i];
        value.second = crash[i + 1];
        pairred.push_back(value);
    }
}
void    insert(std::pair<int,int>& element, std::vector<std::pair<int,int> >& pairred, int n)
{
    if (n < 0)
        pairred[0] = element;
    else if (element.second >= pairred[n].second)
    {
        if (n == (int)pairred.size() - 1)
            pairred.push_back(element);
        else
            pairred[n + 1] = element;
    }
    else
        if (n == static_cast<int>(pairred.size() - 1))
            pairred.push_back(pairred[n]);
        else
        {
            pairred[n + 1] = pairred[n];
            insert(element, pairred, n - 1);
        }
}

std::vector<std::pair<int,int> > insert_sort_pairs(std::vector<std::pair<int,int> >& pairred, int len)
{
    if (len < 1)
        return pairred;
    else
    {
        insert_sort_pairs(pairred, len - 1);
        insert(pairred[len], pairred, len - 1);
        return pairred;
    }
}

void sort_pairs(std::vector<std::pair<int,int> >& pairred)
{
    unsigned int i = 0;
    while (i < pairred.size())
    {
        if (pairred[i].first > pairred[i].second)
        {
            int tmp = pairred[i].first;
            pairred[i].first = pairred[i].second;
            pairred[i].second = tmp;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    if (argv[1][0] == ' ')
    {
        std::cout << "No spaces allowed on first char\n";
        return 1;
    }
    std::pair<int,int>                  pair;
    std::vector<int>                    crashtest;
    std::vector<int>                    final;
    std::vector<std::pair<int,int> >    pairred;
    std::string                         args = argv[1];
    size_t                              pos = args.find(' ');
    int                                 last_val = 0;
    bool                                odd_even = false;

    while (pos != std::string::npos)
    {
        crashtest.push_back(atoi(args.c_str()));
        args.erase(0, pos +1);
        pos = args.find(' ');
    }
    crashtest.push_back(atoi(args.c_str()));
    if (crashtest.size() % 2 == 1)
    {
        last_val = crashtest[crashtest.size() - 1];
        crashtest.pop_back();
        odd_even = true;
    }
    create_pair(crashtest, pairred);
    sort_pairs(pairred);
    insert_sort_pairs(pairred, pairred.size() - 1);
    final = create_s(pairred, odd_even, true);
    unsigned long i = 0;
    while (i < 12)
    {
        std::cout << final[i] << "\n";
        i++;
    }
}