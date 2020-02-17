// ������15. ��������1�ĸ���

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hammingWeight1(uint32_t n) {
		unsigned int a = 1;
		int count = 0;
		while (a)
		{
			if (n & a)
				++count;
			a = a << 1;
		}
		return count;
	}

	// һ������ȥ1�����������������㣬�൱�ڰ���������ұߵ�1���0��
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			++count;
			n = n & (n - 1);
		}
		return count;
	}


};

int main() 
{
	int a = 8;
	cout << Solution().hammingWeight(a) << endl;
	std::cout << endl;
	return 0;
}
