
#include "pch.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (std::distance(range_begin, range_end) > 1)  {

		vector<typename RandomIt::value_type> result(range_begin, range_end);

		auto it = result.begin() + result.size() / 2;

		MergeSort(result.begin(), it);
		MergeSort(it, result.end());

		std::merge(result.begin(), it, it, result.end(), range_begin);
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

//Вывод:
//0 1 4 4 4 6 6 7