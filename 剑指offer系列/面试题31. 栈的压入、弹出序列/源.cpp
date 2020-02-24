// ������31. ջ��ѹ�롢��������
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty() && popped.empty())
			return true;
		if (pushed.empty() || popped.empty())
			return false;

		vector<int> s;    // ����ջ
		int j = 0;        // popped�±�
		for (auto i : pushed)
		{
			s.push_back(i);
			while (!s.empty() && popped[j] == s[s.size() - 1])
			{
				s.pop_back();
				++j;
			}
		}
		return s.empty();
	}
};


int main() 
{
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };
	cout << Solution().validateStackSequences(pushed, popped) << endl;

	std::cout << endl;
	return 0;
}
