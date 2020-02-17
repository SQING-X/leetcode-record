// ������14- II. ������ II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	// ̰���㷨
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;    // ����С��3ʱ����Ҫ���

		int timeOf3 = n / 3;         // ������Բ�ֳ�3�Ĵ���
		if (n % 3 == 1)              // ������3֮��������� ����������1ʱ����3�Ĵ�����ȥ1��Ȼ��ʣ�µ�4�ֳ�2*2
			timeOf3 -= 1;
		int timeOf2 = (n - timeOf3 * 3) / 2;
		long long res = 1;
		while (timeOf3--)            // �����������ȡ��
		{
			res = res * 3 % 1000000007;
		}
		res = res * (int)pow(2, timeOf2) % 1000000007;
		return (int)res;
	}
};

int main() 
{
	int a = 4;
	cout << Solution().cuttingRope(a) << endl;
	std::cout << endl;
	return 0;
}
