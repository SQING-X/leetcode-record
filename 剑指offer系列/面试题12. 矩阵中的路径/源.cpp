// ������12. �����е�·��

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool hasPath(
		vector<vector<char>>& board, string &str, int &str_len,
		int i, int j, int &rows, int &cols, vector<int> &visited)
	{
		if (str_len == str.size())    // ���str�е�Ԫ�ض��Ƚ����ˣ�˵������һ��·��������true
			return true;
		
		bool isPath = false;
		if (i >= 0 && i < rows && j >= 0 && j < cols &&              // �ж��Ƿ񳬽�
			board[i][j] == str[str_len] && !visited[i*cols + j])     // �жϸ�λ���Ƿ���str�е��ַ���ȣ��жϸ�λ���Ƿ񾭹�
		{
			++str_len;
			visited[i*cols + j] = 1;
			isPath = hasPath(board, str, str_len, i, j - 1, rows, cols, visited)    // ���ĸ���������ж�
				|| hasPath(board, str, str_len, i, j + 1, rows, cols, visited)
				|| hasPath(board, str, str_len, i - 1, j, rows, cols, visited)
				|| hasPath(board, str, str_len, i + 1, j, rows, cols, visited);
			if (!isPath)     // ����ĸ����򶼲�����·����˵����λ�ò�����·������Ҫ�˻�
			{
				--str_len;
				visited[i*cols + j] = 0;
			}
		}
		return isPath;
	}


	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		int rows = board.size();
		int cols = board[0].size();
		vector<int> flag(rows * cols);      // �жϸ�λ���Ƿ��Ѿ�����

		int str_len = 0;       // ��ǰλ����str�еĳ���
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (hasPath(board, word, str_len, i, j, rows, cols, flag))
					return true;
			}
		}
		return false;
	}
};

int main() 
{
	vector<vector<char>> a = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCEEFFF";
	cout << Solution().exist(a, word) << endl;


	std::cout << endl;
	return 0;
}
