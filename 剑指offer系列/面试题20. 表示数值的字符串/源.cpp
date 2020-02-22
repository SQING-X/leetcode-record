// ������20. ��ʾ��ֵ���ַ���
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
	// ����A��C���������������и��ţ���B��һ���޷�������
	bool isNumber(string s) {
		if (s.empty()) return false;
		
		int pos = 0;
		while (pos < s.size() && s[pos] == ' ') ++pos;  //ȥ��ǰ�οո�
		bool numeric = scanInteger(s, pos);      // �ж��ַ�����ͷ�Ƿ��������
		
		// ������� '.'��������С������ 
		if (s[pos] == '.')
		{
			++pos;

			// 1. С������û���������֣� .123 == 0.123
			// 2. С����������û�����֣� 123. == 123.0
			numeric = scanUnsignedInteger(s, pos) || numeric;
		}

		// �������e����������ָ������
		if (s[pos] == 'e' || s[pos] == 'E')
		{
			++pos;

			// 1. ��eǰ��û������ʱ�ַ������ܱ�ʾ������
			// 2. ��e����û������ʱ���ܱ�ʾ������
			numeric = scanInteger(s, pos) && numeric;
		}
		while (pos < s.size() && s[pos] == ' ') ++pos;    // ȥ������Ŀո�

		return numeric && pos == s.size();
	}

	// �ж��Ƿ�����޷�������
	bool scanUnsignedInteger(const string &str, int &p)
	{
		int before = p;  // ��¼p֮ǰ��λ��
		while (p != str.size() && str[p] >= '0' && str[p] <= '9')
			++p;

		return p > before;  // ���p == before ˵���������޷�������
	}

	// �ж��Ƿ��������
	bool scanInteger(const string &str, int &p)
	{
		if (str[p] == '+' || str[p] == '-')
			++p;
		return scanUnsignedInteger(str, p);
	}
};

int main() 
{
	string s = "1 ";
	cout << Solution().isNumber(s) << endl;


	std::cout << endl;
	return 0;
}
