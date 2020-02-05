#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class NumMatrix {
	vector<vector<int>> buf;
public:
	NumMatrix(vector<vector<int>>& matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		buf.resize(row);
		for (int i = 0; i < row; i++)
			buf[i].resize(col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				buf[i][j] = matrix[i][j];
		}
		for (int i = 1; i < row; i++)
			buf[i][0] += buf[i - 1][0];
		for (int i = 1; i < col; i++)
			buf[0][i] += buf[0][i - 1];
		for (int i = 1; i < row; i++)
		{
			for (int j = 1; j < col; j++)
			{
				buf[i][j] += buf[i][j - 1];
				for (int k = i-1; k >= 0; k--)
					buf[i][j] +=matrix[k][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		if (row1 == 0 && col1 == 0)
			return buf[row2][col2];
		if (row1 == 0 )
			return buf[row2][col2] - buf[row2][col1 - 1];
		if(col1==0)
			return buf[row2][col2] - buf[row1-1][col2];
		return buf[row2][col2] - buf[row1 - 1][col2]-buf[row2][col1-1] + buf[row1 - 1][col1 - 1];
	}
};

int main()
{
	vector<vector<int>> vv{ {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
	{1, 2, 0, 1, 5 },
  {4, 1, 0, 1, 7},
	{1, 0, 3, 0, 5 }
	};
	NumMatrix n(vv);
	cout << n.sumRegion(2, 1, 4, 3) << endl;
	cout << n.sumRegion(1, 1, 2, 2) << endl;
	cout << n.sumRegion(1, 2, 2, 4) << endl;
	cout << n.sumRegion(0, 0, 1, 2) << endl;
	cout << n.sumRegion(0, 2, 2, 4) << endl;
	cout << n.sumRegion(1, 0, 3, 2) << endl;
	system("pause");
	return 0;

}