/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:24:53 by mdesrose          #+#    #+#             */
/*   Updated: 2024/02/13 19:32:02 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

// Implementation of a simple jacobsthal function
int jacobsthal(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<std::pair<int, int> > create_pairs(const std::vector<int>& a) {
    std::vector<std::pair<int, int> > split_array;
    std::vector<int> temp_array;

    for (size_t i = 0; i < a.size(); ++i) {
        size_t temp_length = temp_array.size();
        if (temp_length == 1) {
            temp_array.push_back(a[i]);
            split_array.push_back(std::make_pair(temp_array[0], temp_array[1]));
            temp_array.clear();
        } else if (split_array.size() * 2 == a.size() - 1) {
            split_array.push_back(std::make_pair(temp_array[0], a[i]));
        } else if (temp_length == 0) {
            temp_array.push_back(a[i]);
        }
    }

    return split_array;
}

std::vector<std::pair<int, int> > sort_each_pair(std::vector<std::pair<int, int> >& split_array) {
    for (size_t i = 0; i < split_array.size(); ++i) {
        if (split_array[i].first > split_array[i].second) {
            std::swap(split_array[i].first, split_array[i].second);
        }
    }
    return split_array;
}

void insert(std::pair<int, int> element, std::vector<std::pair<int, int> >& A, int n) {
    if (n < 0) {
        A[0] = element;
    } else if (element.second >= A[n].second) {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(element);
        } else {
            A[n + 1] = element;
        }
    } else {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(A[n]);
        } else {
            A[n + 1] = A[n];
            insert(element, A, n - 1);
        }
    }
}

std::vector<std::pair<int, int> > insertion_sort_pairs(std::vector<std::pair<int, int> >& A, int n) {
    if (n < 1) {
        return A;
    } else {
        insertion_sort_pairs(A, n - 1);
        insert(A[n], A, n - 1);
        return A;
    }
}

std::vector<int> build_jacob_insertion_sequence(const std::vector<int>& array) {
    int array_len = static_cast<int>(array.size());
    std::vector<int> end_sequence;
    size_t jacob_index = 3;

    while (jacobsthal(jacob_index) < array_len - 1) {
        end_sequence.push_back(jacobsthal(jacob_index));
        ++jacob_index;
    }

    return end_sequence;
}

void sort_by_larger_value(std::vector<std::pair<int, int> >& sorted_split_array) {
    insertion_sort_pairs(sorted_split_array, sorted_split_array.size() - 1);
}

std::vector<int> create_s(const std::vector<std::pair<int, int> >& sorted_split_array, int straggler, bool print_comparison_estimation) {
    std::vector<int> S;
    std::vector<int> pend;
    int comparisons_made = 0;

    for (size_t i = 0; i < sorted_split_array.size(); ++i) {
        S.push_back(sorted_split_array[i].second);
        pend.push_back(sorted_split_array[i].first);
    }

    S.insert(S.begin(), pend[0]);

    size_t iterator = 0;
    size_t jacobindex = 3;
    int item = 0;
    std::vector<int> indexSequence;
    indexSequence.push_back(1);
    std::string last = "default";

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend);

    while (iterator <= pend.size()) {
        if (!jacob_insertion_sequence.empty() && last != "jacob") {
            indexSequence.push_back(jacob_insertion_sequence[0]);
            item = pend[jacob_insertion_sequence[0] - 1];
            jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
            last = "jacob";
        } else {
            if (iterator < indexSequence.size() && iterator == static_cast<size_t>(indexSequence[iterator - 1])) {
                ++iterator;
            }
            item = pend[iterator - 1];
            indexSequence.push_back(iterator);
            last = "not-jacob";
        }

        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        comparisons_made += 2;

        S.insert(insertion_point, item);
        ++iterator;
        ++jacobindex;
    }

    if (straggler) {
        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
        comparisons_made += 2;
    }

    if (print_comparison_estimation) {
        std::cout << "Approximate Comparisons Made:" << std::endl;
        std::cout << comparisons_made << std::endl;
    }

    return S;
}

std::vector<int> merge_insertion_sort(const std::vector<int>& A) {
    bool hasStraggler = A.size() % 2 != 0;

    int straggler = hasStraggler ? A.back() : 0;

    std::vector<std::pair<int, int> > split_array = create_pairs(A);
    std::vector<std::pair<int, int> > sorted_split_array = sort_each_pair(split_array);
    sort_by_larger_value(sorted_split_array);

    std::vector<int> S = create_s(sorted_split_array, straggler, true);

    std::cout << "Sorted Array:" << std::endl;
    for (size_t i = 0; i < S.size(); ++i) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;

    return S;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

// Equivalent of random.randint(0, 5000) in C++98
int generateRandomNumber() {
    return rand() % 5001;
}

// Function to generate arrays with random, non-repeating numbers of any length
std::vector<int> createArray(int length) {
    std::vector<int> A;
    for (int i = 0; i < length; ++i) {
        int randomNumber;
        do {
            randomNumber = generateRandomNumber();
        } while (std::find(A.begin(), A.end(), randomNumber) != A.end());
        A.push_back(randomNumber);
    }
    return A;
}

int main() {
    // Create an unsorted array
    std::vector<int> a = createArray(100);

    // And sort it!
    std::cout << "Starting Array:" << std::endl;
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    clock_t start_time = clock();
    merge_insertion_sort(a);
    std::cout << "Sort took " << (double)(clock() - start_time) / CLOCKS_PER_SEC << " seconds to run" << std::endl;

    return 0;
}