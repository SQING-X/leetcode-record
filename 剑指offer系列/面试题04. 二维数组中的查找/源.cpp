// ������04. ��ά�����еĲ���

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = col - 1; i >= 0; --i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (target == matrix[j][i])
					return true;
				if (target < matrix[j][i])   // ������break֮��j�����µ���0����Ҫ�Ż�
					break;
				if (target > matrix[j][i])
					continue;
			}
		}
		return false;
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0, j = col - 1;
		while (i < row && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				--j;
			else
				++i;
		}
		return false;
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
