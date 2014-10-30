#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> merge(const std::vector<int> &v1,
		       const std::vector<int> &v2) {
	std::vector<int> out;
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
		}
	}
	return out;
}

std::vector<int> merge_sort(std::vector<int> &vec) {
	if (vec.size() == 1)
		return vec;
	std::vector<int> v1(vec.begin(), vec.begin() + (vec.size()/2));
	std::vector<int> v2(vec.begin() + (vec.size()/2), vec.end());
	v1 = merge_sort(v1);
	v2 = merge_sort(v2);
	return merge(v1,v2);
}

main() {
	std::vector<int> vec = {243,0,1,4,2,3,99,1,-3,6,7,8,9,10243,0,1,4,2,3,99,1,-3,6,7,8,9,10};
	vec = merge_sort(vec);
	for (auto c : vec)
		std::cout << c << " ";
}
