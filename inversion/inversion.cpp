// Uses Merge Sort to count the number of inversions on a vector.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

long unsigned int merge_and_count(const std::vector<int> &v1,
		    const std::vector<int> &v2,
		    std::vector<int> &out) {
	long unsigned int count = 0;

	auto beg1 = v1.begin(), end1 = v1.end();
	auto beg2 = v2.begin(), end2 = v2.end();
	while (true) {
		if (beg1 == end1) {
			auto ins = std::back_inserter(out);
			std::copy(beg2, end2, ins);
			break;
		}
		if (beg2 == end2) {
			auto ins = std::back_inserter(out);
			std::copy(beg1, end1, ins);
			break;
		}
		if (*beg1 < *beg2) {
			out.push_back(*beg1);
			++beg1;
		} else {
			out.push_back(*beg2);
			++beg2;
			count += end1 - beg1;
		}
	}
	return count;
}

long unsigned int count_and_sort(std::vector<int> &vec) {
	const auto SIZE = vec.size();
	if (SIZE == 1 or vec.empty())
		return 0;
	long unsigned int count = 0;
	auto beg = vec.begin(), end = vec.end();
	std::vector<int> v1(beg, beg + (SIZE/2));
	std::vector<int> v2(beg + (SIZE/2), end);
	count += count_and_sort(v1);
	count += count_and_sort(v2);
	vec.clear();
	count += merge_and_count(v1, v2, vec);
	return count;
}

main() {
	std::vector<int> vec;
	vec.reserve(100000);
	std::ifstream test("test.txt");
	int temp;
	while (test >> temp)
		vec.push_back(temp);
	long unsigned count = count_and_sort(vec);
	std::cout << count << "\n";
}
