// ������13. �����˵��˶���Χ

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int movingCount(int m, int n, int k) {
		if (k < 0 || m <= 0 || n <= 0)
			return 0;
		vector<int> visited(m * n);    // ��¼��λ���Ƿ��Ѿ�����

		int count = movingCountCore(k, 0, 0, m, n, visited);       // �ӣ�0,0����ʼ���л���
		return count;
	}

	int movingCountCore(int threshold, int row, int col, int rows, int cols, vector<int> &visited)
	{
		int count = 0;
		if (check(threshold, row, col, rows, cols, visited))  // ��check��������Ƿ�������ĿҪ������
		{
			visited[row * cols + col] = 1;
			count = 1 + movingCountCore(threshold, row - 1, col, rows, cols, visited)      // �����λ�õ��ĸ��������������ĸ���
				+ movingCountCore(threshold, row + 1, col, rows, cols, visited)
				+ movingCountCore(threshold, row, col - 1, rows, cols, visited)
				+ movingCountCore(threshold, row, col + 1, rows, cols, visited);
		}
		return count;
	}

	bool check(int threshold, int row, int col, int rows, int cols, vector<int> &visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& (getDigitSum(row) + getDigitSum(col) <= threshold)
			&& !visited[row * cols + col])
			return true;
		return false;
	}

	int getDigitSum(int n)
	{
		int s = 0;
		while (n > 0)
		{
			s += n % 10;
			n /= 10;
		}
		return s;
	}

	// bfs
	int movingCount1(int m, int n, int k) {
		if (m <= 0 || n <= 0 || k < 0)
			return 0;
		
		vector<vector<int>> move = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };    // ��ǰλ�õ��ĸ�����
		int count = 1;            // ��ʼ����Ϊ1
		queue<vector<int>> q;     // ����һ���������������߹���λ��
		q.push({ 0, 0 });         // ��ʼλ��Ϊ��0,0��

		vector<int> visited(m * n);   
		visited[0] = 1;

		while (!q.empty())        // �����в�Ϊ��ʱ˵����������������λ�ã���Ҫ�Ը�λ����Χ���ĸ�λ�ý����ж�
		{
			int x = q.front()[0];
			int y = q.front()[1];
			q.pop();     // ����ǰλ�õ���
			
			for (auto &i : move)    // ���ζ��ĸ���������ж�
			{
				int nx = x + i[0]; 
				int ny = y + i[1];
				
				// �ж��Ƿ�Խ�硢������ĿҪ�󡢸�λ���Ƿ���ʹ�
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && (getDigitSum(nx) + getDigitSum(ny) <= k && !visited[ny * n + nx]))
				{
					++count;
					visited[ny * n + nx] = 1;
					q.push({ nx, ny });       // ������Ҫ���λ�ü��뵽������
				}
			}
		}
		return count;
	}
};

int main() 
{
	int m = 2, n = 3, k = 1;
	cout << Solution().movingCount1(m, n, k) << endl;



	std::cout << endl;
	return 0;
}
