// Uses Merge Sort to count the number of inversions on a vector.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

long unsigned int merge_and_count(std::vector<int>::iterator beg1,
				  std::vector<int>::iterator end1,
				  std::vector<int>::iterator beg2,
				  std::vector<int>::iterator end2, 
				  const int SIZE) {
	std::vector<int> out;
	out.reserve(SIZE);
	long unsigned int count = 0;
	auto beg = beg1;
	while (beg1 != end1 && beg2 != end2) {
		if (*beg1 < *beg2) {
			out.push_back(*beg1);
			++beg1;
		} else {
			out.push_back(*beg2);
			++beg2;
			count += end1 - beg1;
		}
	}
	while (beg1 != end1)
		out.push_back(*beg1++);
	while (beg2 != end2) 
		out.push_back(*beg2++);
	for(const auto &c : out)
		*beg++ = c;
	return count;
}

long unsigned int count_and_sort(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	const auto SIZE = end - beg;
	if (SIZE < 2)
		return 0;
	long unsigned int count = 0;
	auto beg1 = beg, end1 = beg + (SIZE/2);
	auto beg2 = beg + (SIZE/2), end2 = end;
	count += count_and_sort(beg1, end1);
	count += count_and_sort(beg2, end2);
	count += merge_and_count(beg1, end1, beg2, end2, SIZE);
	return count;
}

main() {
	std::vector<int> vec;
	vec.reserve(100000);
	std::ifstream test("test.txt");
	int temp;
	while (test >> temp)
		vec.push_back(temp);
	long unsigned count = count_and_sort(vec.begin(), vec.end());
	std::cout << count << "\n";
}
