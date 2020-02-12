// ������05. �滻�ո�


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	string replaceSpace(string s) {
		if (s.empty()) return "";
		int len = s.size();
		int kg = 0;
		for (auto &i : s)   // ����ͳ���ַ����еĿո���
		{
			if (i == ' ')
				++kg;
		}
		int new_len = len + kg * 2;
		for (int i = len; i < new_len; ++i)    // �����ַ����ĳ���
			s += ' ';

		int index = new_len - 1;
		for (int i = len - 1; i >= 0; --i)   // �Ӻ���ǰ�����滻�ո�
		{
			if (s[i] != ' ')
				s[index--] = s[i];
			else
			{
				s[index--] = '0';
				s[index--] = '2';
				s[index--] = '%';
			}
		}
		return s;
	}
};

int main() 
{
	string s = "We are happy.";
	string re = Solution().replaceSpace(s);
	for (auto &i : re)
		cout << i;
	std::cout << endl;
	return 0;
}
