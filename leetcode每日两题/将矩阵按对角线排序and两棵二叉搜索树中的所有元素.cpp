#define _CRT_SECURE_NO_WARNINGS 1

/*
1329. 将矩阵按对角线排序
给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。



示例 1：



输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
	{
		for (size_t i = 0; i < mat.size() - 1; i++)
		{
			size_t ci = i;
			size_t j = 0;
			vector<int> tmp;
			while (i < mat.size() && j < mat[0].size())
			{
				tmp.push_back(mat[i][j]);
				i++; j++;
			}
			sort(tmp.begin(), tmp.end());
			i = ci; j = 0;
			int k = 0;
			while (i < mat.size() && j < mat[0].size())
			{
				mat[i][j] = tmp[k];
				i++; j++; k++;
			}
			i = ci;
		}
		for (size_t j = 1; j < mat[0].size() - 1; j++)
		{
			size_t cj = j;
			size_t i = 0;
			vector<int> tmp;
			while (i < mat.size() && j < mat[0].size())
			{
				tmp.push_back(mat[i][j]);
				i++; j++;
			}
			sort(tmp.begin(), tmp.end());
			i = 0; j = cj;
			int k = 0;
			while (i < mat.size() && j < mat[0].size())
			{
				mat[i][j] = tmp[k];
				i++; j++; k++;
			}
			j = cj;
		}
		return mat;
	}
};


/*
1305. 两棵二叉搜索树中的所有元素
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.



示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：

输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
输出：[-10,0,0,1,2,5,7,10]
示例 3：

输入：root1 = [], root2 = [5,1,7,0,2]
输出：[0,1,2,5,7]
示例 4：

输入：root1 = [0,-10,10], root2 = []
输出：[-10,0,10]
示例 5：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]*/

class Solution {
	void Get_val(TreeNode* root, vector<int>& ret)
	{
		if (root)
		{
			Get_val(root->left, ret);
			ret.push_back(root->val);
			Get_val(root->right, ret);
		}
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
	{
		vector<int> nums1;
		vector<int> nums2;
		vector<int> ret;
		Get_val(root1, nums1);
		Get_val(root2, nums2);
		auto it1 = nums1.begin();
		auto it2 = nums2.begin();
		while (it1 != nums1.end() && it2 != nums2.end())
		{
			if (*it1 <= *it2)
			{
				ret.push_back(*it1);
				it1++;
			}
			else
			{
				ret.push_back(*it2);
				it2++;
			}
		}
		while (it1 != nums1.end())
		{
			ret.push_back(*it1);
			it1++;
		}
		while (it2 != nums2.end())
		{
			ret.push_back(*it2);
			it2++;
		}
		return ret;
	}
};