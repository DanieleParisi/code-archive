#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using ItVint = std::vector<int>::iterator;

ItVint choose_pivot(ItVint &beg, ItVint &end) {
	return beg;
}

void partition(ItVint &beg, ItVint &end, ItVint &pivot) {
	// put the pivot at the beginning
	std::iter_swap(beg, pivot);
	pivot = beg + 1;
	for(ItVint it = beg + 1; it != end; ++it) {
		if (*it < *beg)
			std::iter_swap(it, pivot++);
	}
	std::iter_swap(beg, --pivot);
}

void quick_sort(ItVint beg, ItVint end) {
	if (end - beg < 2)
		return;
	ItVint pivot = choose_pivot(beg, end);
	partition(beg, end, pivot);
	quick_sort(beg, pivot);
	quick_sort(pivot + 1, end);
}

main() {
	std::vector<int> vec {5,1,3,7,2,8,9,11,4,6,10,22,13};
	auto beg = vec.begin(), end = vec.end();
	quick_sort(beg,end);
	for (auto &c : vec)
		std::cout << c << " ";
}
