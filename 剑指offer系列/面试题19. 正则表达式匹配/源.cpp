// ������19. ������ʽƥ��
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return matchCore(s, 0, p, 0);
	}

	bool matchCore(const string &s, int sp, const string &p, int pp)
	{
		if ((sp == s.size()) && (pp == p.size()))    // ���ַ���ƥ������ģʽƥ����ʱ��������
			return true;
		if ((sp != s.size()) && (pp == p.size()))    // ���ַ���ûƥ���굫��ģʽƥ����ʱ�����ؼ٣�
			return false;

		if (p[pp + 1] == '*')     // ��ģʽ����һ���ַ�Ϊ*ʱ��Ϊ���������*ǰ���ַ���ƥ�䣬ƥ��1�κ�ƥ����
		{
			if (p[pp] == s[sp] || (p[pp] == '.' && (sp != s.size())))      // �����ǰ�ַ����е��ַ���ģʽ�е��ַ�ƥ��
				return matchCore(s, sp + 1, p, pp + 2)  // ����*��ǰ�ߵ��ַ�ֻƥ��һ��
				|| matchCore(s, sp + 1, p, pp)    // *ǰ�ߵ��ַ���Ҫƥ����
				|| matchCore(s, sp, p, pp + 2);   // *ǰ���ַ�ƥ��0��
			else
				return matchCore(s, sp, p, pp + 2);
		}
		if (s[sp] == p[pp] || (p[pp] == '.' && (sp != s.size())))
			return matchCore(s, sp + 1, p, pp + 1);

		return false;
	}
};

int main() 
{
	string s = "", p = ".*";
	cout << Solution().isMatch(s, p) << endl;


	std::cout << endl;
	return 0;
}
