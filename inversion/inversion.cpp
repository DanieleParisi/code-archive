// Uses Merge Sort to count the number of inversions on a vector.

#include <iostream>
#include <vector>
#include <algorithm>

int merge_and_count(const std::vector<int> &v1,
		    const std::vector<int> &v2,
		    std::vector<int> &out) {
	int count = 0;
	out.reserve(v1.size() + v2.size());
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

int count_and_sort(std::vector<int> &vec) {
	if (vec.size() == 1)
		return 0;
	int count = 0;
	std::vector<int> v1(vec.begin(), vec.begin() + (vec.size()/2));
	std::vector<int> v2(vec.begin() + (vec.size()/2), vec.end());
	count += count_and_sort(v1);
	count += count_and_sort(v2);
	vec.clear();
	count += merge_and_count(v1, v2, vec);
	return count;
}

main() {
	std::vector<int> vec = {6,2,1,3,4,5};
	int count = count_and_sort(vec);
	std::cout << count << "\n";
	for (auto c : vec)
		std::cout << c << " ";
}
