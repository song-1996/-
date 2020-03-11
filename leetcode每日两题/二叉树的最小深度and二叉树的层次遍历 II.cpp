#define _CRT_SECURE_NO_WARNINGS 1

/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回它的最小深度  2.
*/
class Solution {
public:
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		int left_hight = INT_MAX;
		int right_hight = INT_MAX;
		if (root->left)
			left_hight = minDepth(root->left);
		if (root->right)
			right_hight = minDepth(root->right);
		if (left_hight == INT_MAX && right_hight == INT_MAX)
			return 1;
		return min(left_hight, right_hight) + 1;
	}
};

/*
107. 二叉树的层次遍历 II
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

	3
   / \
  9  20
	/  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
*/

class Solution {
	// stack<vector<int>> s;
	queue<TreeNode*> q;
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> ret;
		if (!root)
			return ret;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int> tmp;
			while (size > 0)
			{
				TreeNode* cur = q.front();
				tmp.push_back(cur->val);
				q.pop();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				size--;
			}
			ret.push_back(tmp);
			// s.push(tmp);
		}
		/*
		while(!s.empty())
		{
			ret.push_back(s.top());
			s.pop();
		}
		*/
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
/*
108. 将有序数组转换为二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

	  0
	 / \
   -3   9
   /   /
 -10  5
*/

class Solution {
	TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right)
	{
		if (left + 1 > right)
			return nullptr;
		int mid = (left + right) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = _sortedArrayToBST(nums, left, mid);
		root->right = _sortedArrayToBST(nums, mid + 1, right);
		return root;
	}
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		int left = 0, right = nums.size();
		return _sortedArrayToBST(nums, left, right);
	}
};

/*
112. 路径总和
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \      \
		7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return false;
		if (!root->left && !root->right)
		{
			sum -= root->val;
			if (sum == 0)
				return true;
			return false;
		}
		bool left = hasPathSum(root->left, sum - root->val);
		bool right = hasPathSum(root->right, sum - root->val);
		return left || right;
	}
};