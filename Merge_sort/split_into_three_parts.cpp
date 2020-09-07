#include "pch.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (std::distance(range_begin, range_end) > 1) {

		vector<typename RandomIt::value_type> result(range_begin, range_end);

		auto it1 = result.begin() + result.size() / 3;
		auto it2 = result.begin() + 2*result.size() / 3;

		MergeSort(result.begin(), it1);
		MergeSort(it1, it2);
		MergeSort(it2, result.end());

		vector<typename RandomIt::value_type> first_and_second_third;

		std::merge(result.begin(), it1, it1, it2, back_inserter(first_and_second_third));

		std::merge(first_and_second_third.begin(), first_and_second_third.end(),
			it2, result.end(), range_begin);
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

//Вывод:
//0 1 4 4 4 5 6 6 7