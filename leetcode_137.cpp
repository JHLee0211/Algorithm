#include <map>
#include <bitset>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int one = 0, two = 0;
		for (auto n : nums) {
			int tmp = one & n;
			one = one ^ n;



			int tmp_two = two ^ tmp;
			tmp = two & tmp;
			two = tmp_two;
			one = one ^ tmp;
			int tmp_one = one ^ (one&two);
			two = two ^ (one&two);
			one = tmp_one;

		}
		return one;
	}
};