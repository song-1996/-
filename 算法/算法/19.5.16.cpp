#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

//template<class Type>
//void Perm(Type list[], int k, int m)
//{ //产生[list[k:m]的所有排列
//	if (k == m)
//	{  //只剩下一个元素
//		for (int i = 0; i <= m; i++)
//			cout << list[i];
//		cout << endl;
//	}
//	else  //还有多个元素待排列，递归产生排列
//		for (int i = k; i <= m; i++)
//		{
//			swap(list[k], list[i]);
//			Perm(list, k + 1, m);
//			swap(list[k], list[i]);
//		}
//}
//
//int main() {
//
//	char s[] = "abcd";
//	Perm(s, 0, 3);
//	system("pause");
//	return 0;
//}


//typedef struct task
//{
//	int start;
//	int end;
//	int value;
//}task;
//int sum_a(task *t,int i)
//{
//	if (i == 1)
//		return t[i-1].value;
//	if (i == 2)
//		return t[i - 2].value > t[i - 1].value ? t[i - 2].value : t[i - 1].value;
//	int A = sum_a(t, (i - 1)+t[i-1].value);
//	int B= sum_a(t, i - 1);
//	return A > B ? A : B;
//}
//int main()
//{
//	task t[8] = {0};
//	int i = 0;
//	for (int i = 0; i < 8; i++)
//	{
//		scanf("%d", &t[i].start);
//		scanf("%d", &t[i].end);
//		scanf("%d", &t[i].value);
//	}
//	cout<<sum_a(t,8);
//	system("pause");
//}

//#include<vector>
//class Solution {
//public:
//	int minimumTotal(vector<vector<int>>& triangle)
//	{
//		if (triangle.empty())
//			return 0;
//		if (triangle[0].empty())
//			return 0;
//		int m = triangle.size();
//		int n = triangle[m - 1].size();
//		int min_path = 999999999;
//		for (int i = 0; i < m - 1; i++)
//			triangle[m - 1][0] += triangle[i][0];
//		for (int i = 0; i < m - 1; i++)
//			triangle[m - 1][n - 1] += triangle[i][i];
//		for (int j = 1; j < n - 1; j++)
//		{
//			int i = m - 1;
//			int x = m - 1;
//			int y = j;
//			while (x > 0 || y > 0 )
//			{
//				if (x == y)
//				{
//					triangle[i][j] += triangle[x - 1][y - 1];
//					y = y - 1;
//					x = x - 1;
//					}
//				else if (y == 0)
//				{
//					triangle[i][j] += triangle[x - 1][y];
//					x = x - 1;
//				}
//				else
//				{
//					if (triangle[x - 1][y - 1] < triangle[x - 1][y])
//					{
//						triangle[i][j] += triangle[x - 1][y - 1];
//						y = y - 1;
//					}
//					else
//					{
//						triangle[i][j] += triangle[x - 1][y];
//					}
//					x = x - 1;
//				}
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (min_path > triangle[m - 1][i])
//				min_path = triangle[m - 1][i];
//		}
//		return min_path;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> v;
//	v.resize(13);
//	for (int i = 0; i < 13; i++)
//	{
//		v[i].resize(i + 1, 0);
//	}
//	for (int i = 0; i < 13; i++)
//	{
//		for (int j = 0; j < i + 1; j++)
//		{
//			cin >> v[i][j];
//		}
//	}
//	Solution s;
//	s.minimumTotal(v);
//}

#include<vector>
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray)
//	{
//		if (rotateArray.size() == 0)
//			return 0;
//		if (rotateArray[0] < rotateArray[rotateArray.size() - 1])
//			return rotateArray[0];
//		int ret = rotateArray[0];
//		if (rotateArray[0] == rotateArray[rotateArray.size() - 1])
//		{
//			for (int i = 0; i < (int)rotateArray.size(); i++)
//			{
//				if (rotateArray[i] < ret)
//					ret = rotateArray[i];
//			}
//		}
//		else
//		{
//			int left = 0;
//			int right = rotateArray.size() - 1;
//			int mid = 0;
//			while (left <= right)
//			{
//				mid = (left + right) >> 1;
//				if (mid - left == 0)
//				{
//					ret = rotateArray[mid];
//					break;
//				}
//				else if (rotateArray[mid] >= rotateArray[0])
//				{
//					left = mid + 1;
//				}
//				else if(rotateArray[mid] <= rotateArray[rotateArray.size() - 1])
//				{
//					right = mid - 1;
//				}
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	int arr[] = { 3,4,5,6,8,1,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	vector<int>v(arr,arr+sz);
//	Solution s;
//	s.minNumberInRotateArray(v);
//}


//class Solution {
//public:
//	vector<int> printMatrix(vector<vector<int> > matrix)
//	{
//		vector<int> v;
//		if (matrix.empty() || matrix[0].empty())
//			return v;
//		int m = matrix.size();
//		int n = matrix[m - 1].size();
//		int key = m * n;
//		v.resize(m*n, 0);
//		int index = 0;
//		int row = 0;
//		while (1)
//		{
//			for (int i = row; i < n; i++)
//				v[index++] = matrix[row][i];
//			for (int i = row + 1; i < m; i++)
//				v[index++] = matrix[i][n - 1];
//			for (int i = n - 2; i >= row; i--)
//			{
//				if (index < key)
//					v[index++] = matrix[m - 1][i];
//				else
//					break;
//			}
//			for (int i = m - 2; i >= row + 1; i--)
//			{
//				if (index < key)
//					v[index++] = matrix[i][row];
//				else
//					break;
//			}
//			if (index == key)
//				break;
//			row++;
//			n--;
//			m--;
//		}
//		return v;
//	}
//};
//
//int main()
//{
//	vector<vector<int>> vv(1, vector<int>(5));
//	for (int i = 0; i < 1; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			cin >> vv[i][j];
//		}
//	}
//	Solution s;
//	s.printMatrix(vv);
//	return 0;
//}


//class Solution {
//	void _Adjust_down(vector<int>& v, size_t i)
//	{
//		size_t parent = i;
//		size_t child = parent + parent + 1;
//		while (child < v.size())
//		{
//			if (child + 1 < v.size() && v[child] < v[child + 1])
//				child = child + 1;
//			if (v[parent] < v[child])
//				swap(v[parent], v[child]);
//			else
//				return;
//			parent = child;
//			child = parent + parent + 1;
//		}
//	}
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
//	{
//		vector<int> v;
//		if (k <= 0)
//			return v;
//		v.resize(k);
//		for (int i = 0; i < k; i++)
//			v[i] = input[i];
//		if (k == (int)input.size())
//			return v;
//		for (int i = ((v.size() - 2) >> 1); i >= 0; i--)
//			_Adjust_down(v, i);
//		for (int i = k; i < (int)input.size(); i++)
//		{
//			if (input[i] <= v[0])
//			{
//				v[0] = input[i];
//				_Adjust_down(v, 0);
//			}
//		}
//		return v;
//	}
//};

//class Solution {
//	struct TreeNode
//	{
//	public:
//		TreeNode(int _val)
//			:val(_val),
//			left(nullptr),
//			right(nullptr)
//		{}
//		int val;
//		TreeNode* left;
//		TreeNode* right;
//	};
//	void post(vector<int>& v, TreeNode* root, int* index)
//	{
//		if (root)
//		{
//			post(v, root->left, index);
//			post(v, root->right, index);
//			v[(*index)++] = root->val;
//		}
//	}
//public:
//	bool VerifySquenceOfBST(vector<int> sequence)
//	{
//		if (sequence.empty())
//			return true;
//		TreeNode* root = new TreeNode(sequence[sequence.size() - 1]);
//		for (int i = (sequence.size() - 2); i >= 0; i--)
//		{
//			TreeNode* cur = root;
//			if (sequence[i] > cur->val)
//			{
//				while (sequence[i] > cur->val)
//				{
//					if (cur->right)
//						cur = cur->right;
//					else
//					{
//						cur->right = new TreeNode(sequence[i]);
//						break;
//					}
//				}
//				while (sequence[i] < cur->val)
//				{
//					if (cur->left)
//						cur = cur->left;
//					else
//					{
//						cur->left = new TreeNode(sequence[i]);
//						break;
//					}
//				}
//			}
//			else	if (sequence[i] < cur->val)
//			{
//				while (sequence[i] < cur->val)
//				{
//					if (cur->left)
//						cur = cur->left;
//					else
//					{
//						cur->left = new TreeNode(sequence[i]);
//						break;
//					}
//				}
//				while (sequence[i] > cur->val)
//				{
//					if (cur->right)
//						cur = cur->right;
//					else
//					{
//						cur->right = new TreeNode(sequence[i]);
//						break;
//					}
//				}
//			}
//			else
//				continue;
//		}
//		int index = 0;
//		vector<int> v;
//		v.resize(sequence.size());
//		 post(v, root, &index);
//		 for (int i = 0; i < (int)sequence.size(); i++)
//		 {
//			 if (v[i] != sequence[i])
//				 return false;
//		 }
//		 return true;
//	}
//};


//class Solution {
//public:
//	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
//	{
//		if (data.empty())
//			return;
//		int max = 0;
//		for (int i = 0; i < (int)data.size(); i++)
//		{
//			if (data[i] > max)
//				max = data[i];
//		}
//		vector<int> v;
//		v.resize(max+1);
//		for (int i = 0; i < (int)data.size(); i++)
//		{
//			v[data[i]]++;
//		}
//		int j = 0;
//		for (int i = 0; i < max+1; i++)
//		{
//			if (v[i] == 1)
//			{
//				data[j++] = i;
//			}
//		}
//		*num1 = data[0];
//		*num2 = data[1];
//	}
//};
//int main()
//{
//	int arr[] = { 1,2,2,1,34,36,34,78,98,97,98,97 };
//	int a = 0;
//	int b = 0;
//	vector<int > v(arr, arr + 12);
//	Solution s;
//	s.FindNumsAppearOnce(v,&a,&b);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//int _count(int l, int r)
//{
//	int end = 1;
//	for (int i = 0; i < 9; i++)
//	{
//		end = end * 10;
//	}
//	if (l<1 || r>end)
//		return 0;
//	int count = 0;
//	int j = l;
//	int left = 1;
//	for (; j <= r; j++)
//	{
//		if (j > 1)
//		{
//			left = left * 10;
//			left = left + j;
//		}
//		if (left % 3 == 0)
//			count++;
//	}
//	return count;
//}
//int main()
//{
//	int l, r;
//	while (cin >> l >> r)
//	{
//		cout << _count(l, r) << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int j = 0;
//	cin >> j;
//	int stop = j;
//	vector<int> v;
//	int x;
//	while (j--)
//	{
//		cin >> x;
//		v.push_back(x);
//	}
//	sort(v.begin(), v.end());
//	j = 1;
//	for (int i = 1; i < stop; i++)
//	{
//		if (v[i] != v[i - 1])
//			v[j++] = v[i];
//	}
//	cout << j << endl;
//	for (int i = 0; i < j; i++)
//	{
//		cout << v[i] << ' ';
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//
//{
//	string str;
//	cin >> str;
//	str.resize(3);
//	cout << str << endl;
//	/*int key = 0;
//	int j = 1;
//	for (int i = 0; i < (int)str.size() - 2; i++)
//	{
//		if (str[i] != '-')
//		{
//			key += (str[i]-'0') * j;
//			j++;
//		}
//	}
//	key = key % 11;
//	if (key == 10)
//		key = 'X'-'0';
//	if (key == str[str.size() - 1]-'0')
//		cout << "Right" << endl;
//	else
//	{
//		str[str.size() - 1] = key+'0';
//		cout << str << endl;
//	}*/
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	char sign = '+';
//	int i = 0;
//	if (str[0] == '-')
//	{
//		sign = '-';
//		i = i + 1;
//		reverse(str.begin() + 1, str.end());
//	}
//	else
//		reverse(str.begin(), str.end());
//	int j = i;
//	for (; i < (int)str.size(); i++)
//	{
//		if (str[i] != '0' && str[i] != '+')
//			str[j++] = str[i];
//	}
//	str.resize(j);
//	cout << str << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
#include<cmath>
//bool is_prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int x = 0;
//	cin >> x;
//	vector<int> v;
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (is_prime(i))
//			v.push_back(i);
//	}
//	int i = 0;
//	for (; i < (int)v.size(); i++)
//	{
//		if (x%v[i] == 0)
//		{
//			if (is_prime(x / v[i]))
//				break;
//		}
//	}
//	cout << x / v[i] << endl;
//	return 0;
//}


//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		if (n < 1 || m < 1)
//			return -1;
//		int last = 0;
//		vector<int> v;
//		v.reserve(n);
//		for (int i = 0; i < n; i++)
//			v.push_back(i);
//		int count = n;
//		int cm = -1;
//		for (int i = 0; i < n; i++)
//		{
//			if (v[i] != -1)
//				cm++;
//			else
//			{
//				if (i + 1 == n)
//					i = -1;
//				continue;
//			}
//			if (cm == (m - 1))
//			{
//				v[i] = -1;
//				count--;
//				if (count == 1)
//					break;
//				cm = -1;
//			}
//			if (i + 1 == n)
//				i = -1;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (v[i] != -1)
//			{
//				last = v[i];
//				break;
//			}
//
//		}
//		return last;
//	}
//};


//class Solution {
//public:
//	vector<vector<int> > FindContinuousSequence(int sum)
//	{
//		int sz = 0;
//		sz = sum / 2 + 1;
//		vector<int> v;
//		v.reserve(sz);
//		vector<vector<int>> vv;
//		for (int i = 0; i < sz; i++)
//			v.push_back(i + 1);
//		int left = 0;
//		int right = 1;
//		int pos = 0;
//		while (right < (int)v.size())
//		{
//			int ans = 0;
//			for (int i = left; i <= right; i++)
//				ans += v[i];
//			if (ans == sum)
//			{
//				vv.resize(pos+1);
//				for (int i = left; i <= right; i++)
//					vv[pos].push_back(v[i]);
//				pos++;
//				right++;
//			}
//			else if (ans < sum)
//				right++;
//			else
//				left++;
//		}
//		return vv;
//	}
//};

//#include<string>
//class Solution {
//public:
//	string LeftRotateString(string str, int n)
//	{
//		if (n <= 0)
//			return str;
//		string s;
//		int len = str.size();
//		s.reserve(len + 1);
//		n = n % len;
//		str += str;
//		int left = n;
//		int right = n + len;
//		for (int i = left; i < right; i++)
//			s.push_back(str[i]);
//		s.push_back('\0');
//		return s;
//	}
//};
//int main()
//{
//	Solution s;
//	cout << s.LeftRotateString("abcXYZdef", 23) << endl;
//	return 0;
//}


//class Solution {
//public:
//
//	bool duplicate(int numbers[], int length, int* duplication)
//	{
//		int i = 0;
//		if (numbers == nullptr || length == 0)
//			return false;
//		while (i < length)
//		{
//			while (numbers[i] != i)
//			{
//				if (numbers[numbers[i]] == numbers[i])
//				{
//					*duplication = numbers[i];
//					return true;
//				}
//				swap(numbers[i], numbers[numbers[i]]);
//			}
//			i++;
//		}
//		return false;
//	}
//};

//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers)
//	{
//		if (numbers.empty())
//			return false;
//		int count = 0;
//		for (int i = 0; i < (int)numbers.size(); i++)
//		{
//			if (numbers[i] == 0)
//				count++;
//		}
//		sort(numbers.begin(), numbers.end());
//		for (int i = 0; i < (int)numbers.size() - 1; i++)
//		{
//			if (numbers[i] == 0)
//				continue;
//			else
//			{
//				if (numbers[i + 1] - numbers[i] > 1)
//					count = count - (numbers[i + 1] - numbers[i] - 1);
//				if (count < 0)
//					return false;
//			}
//		}
//		return true;
//	}
//};

//class Solution {
//	int sum;
//	void Merge(vector<int>& arr, int left, int mid, int right, int* tmp)
//	{
//		int begin1 = left;
//		int end1 = mid;
//		int begin2 = mid;
//		int end2 = right;
//		int pos = 0;
//		while (begin1 < end1)
//		{
//			if (arr[begin1] > arr[end2 - 1])
//			{
//				sum += end2 - begin2;
//				{
//					begin1++;
//					end2 = right;
//				}
//			}
//			else
//			{
//				end2--;
//				if (end2 == begin2)
//				{
//					begin1++;
//					end2 = right;
//				}
//			}
//		}
//		begin1 = left;
//		while (begin1 < end1&&begin2 < end2)
//		{
//			if (arr[begin1] <= arr[begin2])
//				tmp[pos++] = arr[begin1++];
//			else
//				tmp[pos++] = arr[begin2++];
//		}
//		while (begin1 < end1)
//			tmp[pos++] = arr[begin1++];
//		while (begin2 < end2)
//			tmp[pos++] = arr[begin2++];
//		end1 = 0;
//		while (left < right)
//		{
//			arr[left++] = tmp[end1++];
//		}
//	}
//	void _InversePairs(vector<int>& v, int left, int right, int* tmp)
//	{
//		if (left + 1 < right)
//		{
//			int mid = (left + right) >> 1;
//			_InversePairs(v, left, mid, tmp);
//			_InversePairs(v, mid, right, tmp);
//			Merge(v, left, mid, right, tmp);
//		}
//	}
//public:
//	int InversePairs(vector<int> data)
//	{
//		sum = 0;
//		if (data.empty())
//			return sum;
//		int* tmp = new int[data.size()];
//		_InversePairs(data, 0, data.size(), tmp);
//		delete[] tmp;
//		sum %= 1000000007;
//		return sum;
//	}
//};

//class Solution {
//	int sum;
//	void Merge(vector<int>& arr, int left, int mid, int right, int* tmp)
//	{
//		if (mid == right)
//			mid = (right + left) >> 1;
//		int begin1 = left;
//		int end1 = mid;
//		int begin2 = mid;
//		int end2 = right;
//		int pos = left;
//		while (begin1 < end1)
//		{
//			if (arr[begin1] > arr[end2 - 1])
//			{
//				sum += end2 - begin2;
//				if (sum > 1000000007)
//					sum %= 1000000007;
//				{
//					begin1++;
//					end2 = right;
//				}
//			}
//			else
//			{
//				end2--;
//				if (end2 == begin2)
//				{
//					begin1++;
//					end2 = right;
//				}
//			}
//		}
//		begin1 = left;
//		while (begin1 < end1&&begin2 < end2)
//		{
//			if (arr[begin1] <= arr[begin2])
//				tmp[pos++] = arr[begin1++];
//			else
//				tmp[pos++] = arr[begin2++];
//		}
//		while (begin1 < end1)
//			tmp[pos++] = arr[begin1++];
//		while (begin2 < end2)
//			tmp[pos++] = arr[begin2++];
//	}
//	void _InversePairs(vector<int>& arr, int sz, int* tmp)
//	{
//		int gap = 1;
//		int i = 0;
//		while (gap < sz)
//		{
//			for (i = 0; i < sz; i += 2 * gap)
//			{
//				int left = i;
//				int mid = left + gap;
//				int right = mid + gap;
//				if (mid > sz)
//					mid = sz;
//				if (right > sz)
//					right = sz;
//				Merge(arr, left, mid, right, tmp);
//			}
//			for (int j = 0; j < sz; j++)
//				arr[j] = tmp[j];
//			gap = gap * 2;
//		}
//	}
//public:
//	int InversePairs(vector<int> data)
//	{
//		sum = 0;
//		if (data.empty())
//			return sum;
//		int* tmp = new int[data.size()];
//		_InversePairs(data, data.size(), tmp);
//		delete[] tmp;
//		sum %= 1000000007;
//		return sum;
//	}
//};
//int main()
//{
//	int arr[] = {7,4,5,3,6,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	vector<int> v(arr, arr + sz);
//	Solution s;
//	cout<<s.InversePairs(v);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//void Print_matrix(vector<vector<int>> vv)
//{
//	for (int i = 0; i < (int)vv.size(); i++)
//	{
//		for (int j = 0; j < (int)vv[0].size(); j++)
//			cout << vv[i][j] << ' ';
//		cout << endl;
//	}
//}
//void rotate(vector<vector<int>>& vv, int n)
//{
//	int right = n;
//	int j = right - 1;
//	int k = 0;
//	int left = 0;
//	while (left < right)
//	{
//		for (int i = left; i < right - 1; i++)
//		{
//			int tmp = vv[j][k];
//			vv[j][k] = vv[right - 1][j];
//			vv[right - 1][j] = vv[i][right - 1];
//			vv[i][right - 1] = vv[k][i];
//			vv[k][i] = tmp;
//			j--;
//		}
//		k++;
//		right--;
//		left++;
//		j = right - 1;
//	}
//	Print_matrix(vv);
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		vector<vector<int> > vv(n, vector<int>(n));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> vv[i][j];
//			}
//		}
//		rotate(vv, n);
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//bool flag = false;
//void Print(vector<vector<int>>& vv, int x1, int y1, int x2, int y2)
//{
//
//	if (flag)
//	{
//		while (x2 >= x1 && y2 <= y1)
//		{
//				cout << vv[x1][y1] << ' ';
//				x1++;
//				y1--;
//		}
//		flag = false;
//	}
//	else
//	{
//		while (x2 >= x1 && y2 <= y1)
//		{
//				cout << vv[x2][y2] << ' ';
//				x2--;
//				y2++;
//		}
//		flag = true;
//	}
//}
//void Print_z(vector<vector<int>>& vv)
//{
//	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//	while (x1 < (int)vv.size() || y2 < (int)vv[0].size())
//	{
//		Print(vv, x1, y1, x2, y2);
//		if (y1 < (int)vv[0].size()-1)
//			y1++;
//		else
//			x1++;
//		if (x2 < (int)vv.size()-1)
//			x2++;
//		else
//			y2++;
//	}
//}
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		vector<vector<int>> vv(n, vector<int>(m));
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				cin >> vv[i][j];
//			}
//		}
//		Print_z(vv);
//	}
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int arr_cal(vector<int> copy)
//{
//	int count = 0;
//	int max_count = 0;
//	sort(copy.begin(), copy.end());
//	for (int i = 1; i < (int)copy.size(); i++)
//	{
//		if (copy[i] - copy[i - 1] == 1)
//			count++;
//		else
//		{
//			if (max_count < count)
//				max_count = count;
//			count = 0;
//		}
//	}
//	if (max_count < count)
//		max_count = count;
//	if(max_count!=0)
//		return max_count+1;
//	else
//		return max_count;
//}
//int Max_arr_sum(vector<int>& v)
//{
//	vector<int> copy;
//	int sz = v.size();
//	if (sz == 0 || sz == 1)
//		return sz;
//	copy.reserve(sz);
//	int max_len = 0;
//	int len = 0;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		copy.push_back(v[i]);
//		int j = i+1;
//		for (; j < sz; j++)
//		{
//			copy.push_back(v[j]);
//			len = arr_cal(copy);
//			if (len > max_len)
//				max_len = len;
//		}
//		copy.clear();
//	}
//	return max_len;
//}
//int main()
//{
//	int n;
//	vector<int> v;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	cout << Max_arr_sum(v) << endl;
//}

//class Same {
//public:
//	bool checkSam(string stringA, string stringB)
//	{
//		vector<char*> vA;
//		vector<char*> vB;
//		char* str = strtok((char*)stringA.c_str(), " ");
//		while (str)
//		{
//			vA.push_back(str);
//			str = strtok(nullptr, " ");
//		}
//		str = strtok((char*)stringB.c_str(), " ");
//		while (str)
//		{
//			vB.push_back(str);
//			str = strtok(nullptr, " ");
//		}
//		return true;
//	}
//};
//int main()
//{
//	Same s;
//	s.checkSam("This is nowcoder", "is This nowcoder");
//	return 0;
//}

//class Replacement {
//public:
//	string replaceSpace(string iniString, int length)
//	{
//		int count = 0;
//		for (int i = 0; i < length; i++)
//		{
//			if (iniString[i] == ' ')
//				count++;
//		}
//		if (count == 0)
//			return iniString;
//		string String;
//		int len = 0;
//		len = length + (count * 3) - count;
//		String.resize(len);
//		int j = len-1;
//		for (int i = length - 1; i >= 0; i--, j--)
//		{
//			if (iniString[i] == ' ')
//			{
//				String[j--] = '0';
//				String[j--] = '2';
//				String[j] = '%';
//			}
//			else
//				String[j] = iniString[i];
//		}
//		return String;
//	}
//};
//int main()
//{
//	Replacement r;
//	r.replaceSpace("Mr John Smith",13);
//	return 0;
//}

//class Zipper {
//	void Push_digit(string& str, int count)
//	{
//		if (count > 9)
//		{
//			Push_digit(str, count / 10);
//		}
//		str.push_back(count % 10 + '0');
//	}
//public:
//	string zipString(string iniString)
//	{
//		int pre = 0;
//		int cur = 1;
//		int count = 1;
//		int len = iniString.size();
//		int ziplen = 0;
//		string str;
//		for (int cur = 1; cur < len; cur++)
//		{
//			if (iniString[pre] == iniString[cur])
//			{
//				count++;
//			}
//			else
//			{
//				str.push_back(iniString[pre]);
//				Push_digit(str, count);
//				pre = cur;
//				count = 1;
//			}
//		}
//		str.push_back(iniString[pre]);
//		Push_digit(str, count);
//		ziplen = str.size();
//		if (len > ziplen)
//			return str;
//		else
//			return iniString;
//	}
//};
//
//int main()
//{
//	Zipper z;
//	z.zipString("aaaaaaaaaaaaaaaaaaabcccccaaa");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int Bs_greater_key(vector<int> v, int len, int key)
//{
//	int left = 0;
//	int right = len;
//	int mid = 0;
//	while (left < right)
//	{
//		mid = left + (right - left) / 2;
//		if (right - left == 1 && v[right] >= key && v[left] < key)
//			return right + 1;
//		else if (v[mid] >= key)
//			right = mid;
//		else
//			left = mid + 1;
//	}
//	if (left == right && 0 <= left && left < right)
//		return right + 1;
//	return left + 1;
//}
//int main()
//{
//	int n, key;
//	vector<int> v;
//	cin >> n >> key;
//	v.reserve(n);
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	cout << Bs_greater_key(v, n, key) << endl;
//	return 0;
//}

//class Transform {
//public:
//	vector<vector<int> > transformImage(vector<vector<int> > mat, int n)
//	{
//		int i = 0;
//		int k = 0;
//		while (k <= n/2)
//		{
//			int j = n - 1;
//			i = k;
//			while (i < n-1)
//			{
//				int tmp = mat[k][i];
//				mat[k][i] = mat[j][k];
//				mat[j][k] = mat[n - 1][j];
//				mat[n - 1][j] = mat[i][n - 1];
//				mat[i][n - 1] = tmp;
//				j--;
//				i++;
//			}
//			k++;
//			n--;
//		}
//		return mat;
//	}
//};

//#include<queue>
//class Clearer {
//	queue<int> q;
//private:
//	void Change_arr(vector<vector<int> >& mat, int top, int x, int y,int n)
//	{
//		int tmpx = x;
//		int tmpy = y;
//		if (top == 0)
//		{
//			while (--x >= 0)
//			{
//				mat[x][y] = 0;
//			}
//			x = tmpx;
//			while (--y >= 0)
//			{
//				mat[x][y] = 0;
//			}
//			y = tmpy;
//			while (++x < n)
//			{
//				mat[x][y] = 0;
//			}
//			x = tmpx;
//			while (++y < n)
//			{
//				mat[x][y] = 0;
//			}
//			y = tmpy;
//		}
//	}
//public:
//	vector<vector<int> > clearZero(vector<vector<int> > mat, int n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				q.push(mat[i][j]);
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				int top = q.front();
//				q.pop();
//				Change_arr(mat, top, i, j,n);
//			}
//		}
//		return mat;
//	}
//};
//int main()
//{
//	vector<vector<int>> vv;
//	vv.resize(3);
//	for (int i = 0; i < vv.size(); i++)
//	{
//		vv[i].resize(3);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> vv[i][j];
//		}
//	}
//	Clearer c;
//	c.clearZero(vv,3);
//	return 0;
//}


//class ReverseEqual {
//public:
//	bool checkReverseEqual(string s1, string s2)
//	{
//		char buf[256] = {0};
//		for (int i = 0; i < (int)s1.size(); i++)
//		{
//			buf[s1[i]]++;
//		}
//		for (int i = 0; i < (int)s2.size(); i++)
//		{
//			buf[s2[i]]--;
//		}
//		for (int i = 0; i < 256; i++)
//		{
//			if (buf[i] != 0)
//				return false;
//		}
//		return true;
//	}
//};
//int main()
//{
//	ReverseEqual r;
//	r.checkReverseEqual("ookvnorsiwwddjkpqasgbqjqrgsyriuxsruxidwprrxagjxzbwwgztsgndyfoelcgfzqzxzximtdwjlkhouxqrdzdguhxweqkvqabcltywygpbgeprmhbltnhkhynvpuszoqdrspwldgecrbvzsiywkfzphczpxyeyzhdhnegmodldikwnjhlwer", "sgndyfoelcgfzqzxzximtdwjlkhouxqrdzdguhxweqkvqabcltywygpbgeprmhbltnhkhynvpuszoqdrspwldgecrbvzsiywkfzphczpxyeyzhdhnegmodldikwnjhlwerookvnorsiwwddjkpqasgbqjqrgsyriuxsruxidwprrxagjxzbwwgzt");
//	return 0;
//}

#include<vector>

//class SetOfStacks {
//public:
//	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size)
//	{
//		vector<vector<int>> vv;
//		vector<int> v;
//		v.reserve(size);
//		for (int i = 0; i < (int)ope.size(); i++)
//		{
//			if (ope[i][0] == 1)
//			{
//				if ((int)v.size() >= size)
//				{
//					vector<int> tmp(v);
//					vv.push_back(tmp);
//					v.clear();
//				}
//				v.push_back(ope[i][1]);
//			}
//			if (ope[i][0] == 2)
//			{
//				if (v.size() > 0)
//					v.pop_back();
//				else
//				{
//					if (vv.size() > 0)
//					{
//						v = vv[vv.size() - 1];
//						vv.pop_back();
//						v.pop_back();
//					}
//				}
//			}
//		}
//		vv.push_back(v);
//		return vv;
//	}
//};
//int main()
//{
//	vector<vector<int>> vv(10,vector<int>(2));
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> vv[i][j];
//		}
//	}
//	SetOfStacks s;
//	s.setOfStacks(vv, 5);
//	return 0;
//}
//#include<stack>
//class TwoStacks {
//	stack<int> tmps;
//public:
//	vector<int> twoStacksSort(vector<int> numbers)
//	{
//		int len = numbers.size();
//		int i = 0;
//		while( i < len)
//		{
//			int tmp = numbers[i];
//			while (!tmps.empty() && tmp < tmps.top())
//			{
//				numbers[i] = tmps.top();
//				tmps.pop();
//				i--;
//			}
//			tmps.push(tmp);
//				i++;
//		}
//		for (int i = 0; i < len; i++)
//		{
//			numbers[i]=tmps.top();
//			tmps.pop();
//		}
//		return numbers;
//	}
//};
//
//int main()
//{
//	int arr[] = { 3,2,5,1,4 };
//	vector<int> v(arr,arr+5);
//	TwoStacks t;
//	t.twoStacksSort(v);
//	return 0;
//}

//#include<queue>
//class CatDogAsylum {
//	queue<int> q1;
//	queue<int> q2;
//	queue<int> s1;
//	queue<int> s2;
//#define Q1   \
//	do{							\
//       v.push_back(q1.front()); \
//       q1.pop();                \
//       s1.pop();                 \
//	}while (0)                
//
//#define Q2   \
//	do{							\
//       v.push_back(q2.front()); \
//       q2.pop();                \
//       s2.pop();                 \
//	}while (0)            
//public:
//	vector<int> asylum(vector<vector<int> > ope)
//	{
//		vector<int> v;
//		for (int i = 0; i < (int)ope.size(); i++)
//		{
//			//进入
//			if (ope[i][0] == 1)
//			{
//				if (ope[i][1] > 0)
//				{
//					q1.push(ope[i][1]);
//					s1.push(i);
//				}
//				else
//				{
//					q2.push(ope[i][1]);
//					s2.push(i);
//				}
//			}
//			else
//			{
//				if (ope[i][1] == 0)
//				{
//					if (!q1.empty() || !q2.empty())
//					{
//						if (!q1.empty() && q2.empty())
//							Q1;
//						if (q1.empty() && !q2.empty())
//							Q2;
//						if (!q1.empty() && !q2.empty())
//						{
//							if (s1.front() < s2.front())
//								Q1;
//							else
//								Q2;
//						}
//					}
//				}
//				else if (ope[i][1] == 1)
//					Q1;
//				else
//					Q2;
//			}
//		}
//		return v;
//	}
//};
//int main()
//{
//	//1 -5 1 -1 1 9 1 9 2 0 2 1 1 -8 2 1 1 -71 1 -92
//	vector<vector<int>> vv(10,vector<int>(2));
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> vv[i][j];
//		}
//	}
//	CatDogAsylum c;
//	c.asylum(vv);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	char buf[256] = { 0 };
//	string str;
//	string sub;
//	string ret;
//	getline(cin, str);
//	getline(cin, sub);
//	for (int i = 0; i < (int)str.size(); i++)
//		buf[str[i]]++;
//	for (int i = 0; i < (int)sub.size(); i++)
//		buf[sub[i]] = 0;
//	for (int i = 0; i < (int)str.size(); i++)
//	{
//		if (buf[str[i]] != 0)
//		{
//			ret.push_back(str[i]);
//			buf[str[i]]--;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//void Reverse(string& str)
//{
//	reverse(str.begin(), str.end());
//	str.push_back(' ');
//	int pos = 0;
//	for (int i = 0; i < (int)str.size(); i ++)
//	{
//		pos = str.find(' ', i);
//		reverse(str.begin() + i, str.begin() + pos);
//		i = pos;
//	}
//	str.pop_back();
//	cout << str << endl;
//}
//int main()
//{
//	string str;
//	getline(cin, str);
//	Reverse(str);
//	return 0;;
//}


//class KthNumber {
//private:
//	bool Meet(vector<int >v, int x)
//	{
//
//		int left = 0;
//		int right = v.size() - 1;
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = (left + right) / 2;
//			if (v[mid] == x)
//				return true;
//			else if (v[mid] < x)
//				left = mid + 1;
//			else
//				right = mid - 1;
//		}
//		return false;
//	}
//public:
//	int findKth(int k)
//	{
//		int ret = 0;
//		vector<int> v(3);
//		v[0] = 3;
//		v[1] = 5;
//		v[2] = 7;
//		for (int i = 0; i < (int)v.size(); i++)
//		{
//			for (int j = 3; j < 8; j += 2)
//			{
//				if (!Meet(v, v[i] * j))
//				{
//					v.push_back(v[i] * j);
//					sort(v.begin(), v.end());
//					if (v.size() == 120)
//						break;
//				}
//			}
//			if (v.size() == 120)
//				break;
//		}
//		return v[v.size() - 39];
//	}
//};
//
//int main()
//{
//	KthNumber k;
//	cout<<k.findKth(82);
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//bool Is_Hw(string& str)
//{
//	string cpy(str);
//	reverse(str.begin(), str.end());
//	for (int i = 0; i < (int)str.size(); i++)
//	{
//		if (str[i] != cpy[i])
//			return false;
//	}
//	return true;
//}
//int _Count(string& sA,  const string& sB)
//{
//	int count = 0;
//	string sAA(sA);
//	for (int i = 0; i < (int)sA.size(); i++)
//	{
//		sA.insert(i, sB);
//		if (Is_Hw(sA))
//			count++;
//		sA = sAA;
//	}
//	sA += sB;
//	if (Is_Hw(sA))
//		count++;
//	sA = sAA;
//	return count;
//}
//int main()
//{
//	string sA;
//	string sB;
//	getline(cin, sA);
//	getline(cin, sB);
//	cout << _Count(sA, sB) << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int Max_Sum(const vector<int>& v)
//{
//	int sum = v[0];
//	int cur = 0;
//	for (int i = 0; i < (int)v.size(); i++)
//	{
//
//		cur += v[i];
//		if (cur > sum)
//			sum = cur;
//		if (cur < 0)
//			cur = 0;
//	}
//	return sum;
//}
//int main()
//{
//	int n;
//	vector<int> v;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	cout << Max_Sum(v) << endl;
//	return 0;
//}

//#include<string>
//using namespace std;
//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.size() == 0)
//			return 0;
//		int ret = 0;
//		int flag = 1;
//		if (str[0] == '-')
//		{
//			flag = -1;
//		}
//		for (int i = 1; i < (int)str.size(); i++)
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//				ret = ret * 10 + (str[i] - '0');
//			else
//				return 0;
//		}
//		if (flag == -1)
//			ret = -ret;
//		return ret;
//	}
//};
//
//int main()
//{
//	string s1;
//	cin >> s1;
//	Solution s;
//	cout<<s.StrToInt(s1);
//	return 0;
//}


#include<iostream>
//#include<vector>
using namespace std;
//int Max_Count(int m, int n)
//{
//	int max = 0;
//	vector<vector<int>> vv(m, vector<int>(n));
//	if (n > 2)
//		vv[0][2] = -1;
//	if (m > 2)
//		vv[2][0] = -1;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (vv[i][j] != -1)
//			{
//				max++;
//				if (j+2 < n)
//					vv[i][j + 2] = -1;
//				if (i+2 < m)
//					vv[i + 2][j] = -1;
//			}
//		}
//	}
//	return max;
//}
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	cout << Max_Count(m, n) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.size() == 0)
//			return 0;
//		int ret = 0;
//		int flag = 1;
//		for (int i = 0; i < (int)str.size(); i++)
//		{
//			if (str[0] == '-')
//				flag = -1;
//			else if (str[0] == '+')
//				;
//			else if (str[i] >= '0' && str[i] <= '9')
//					ret = ret * 10 + (str[i] - '0');
//				else
//					return 0;
//		}
//		if (flag == -1)
//			ret = -ret;
//		return ret;
//	}
//};
//int main()
//{
//	string s1;
//	cin >> s1;
//	Solution s;
//	cout<<s.StrToInt(s1);
//	return 0;
//}

#include<iostream>
using namespace std;
//int Minstep(int x)
//{
//	int f1 = 0;
//	int f2 = 1;
//	if (x == 0 || x == 1)
//		return 0;
//	int f3;
//	for (int i = 2; i < 1000; i++)
//	{
//		f3 = f1 + f2;
//		if (f3 > x&&f2 < x)
//			break;
//		else if (f3 == x)
//			return 0;
//		f1 = f2;
//		f2 = f3;
//	}
//	return (f3 - x < x - f2 ? (f3 - x) : (x - f2));
//}
//int main()
//{
//	int x;
//	while (cin >> x)
//		cout << Minstep(x) << endl;
//	return 0;
//}

//#include<stack>
//class Parenthesis {
//	stack<char> s;
//public:
//	bool chkParenthesis(string A, int n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (A[i] == '(')
//				s.push(A[i]);
//			else if (A[i] == ')')
//				s.pop();
//			else
//				return false;
//		}
//		if (s.empty())
//			return true;
//		else
//			return false;
//	}
//};
//
//int main()
//{
//	Parenthesis p;
//	p.chkParenthesis("()()()", 6);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	string s1;
//	string s2;
//	bool flag1 = false;
//	bool flag2 = false;
//	cin >> s1;
//	string copys1 = s1;
//	int copyn = n;
//	while (--n)
//	{
//		cin >> s2;
//		if (s1 < s2)
//			s1 = s2;
//		else
//		{
//			flag1 = true;
//			break;
//		}
//	}
//	s1 = copys1;
//	n = copyn;
//	while (--n)
//	{
//		cin >> s2;
//		if (s1.size() < s2.size())
//			s1 = s2;
//		else
//		{
//			flag2 = true;
//			break;
//		}
//	}
//	if (!flag1 && !flag2)
//		cout << "both" << endl;
//	else if (!flag1 && flag2)
//		cout << "lexicographically" << endl;
//	else if (flag1 && !flag2)
//		cout << "lengths" << endl;
//	else
//		cout << "none" << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int Lcm(int a, int b)
//{
//	if (a < b)
//		swap(a, b);
//	int ret = a * b;
//	int z = b;
//	while (a%b)
//	{
//		z = a % b;
//		a = b;
//		b = z;
//	}
//	return  ret / z;
//}
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//		cout << Lcm(a, b) << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int Count_step(int m, int n)
//{
//	vector<vector<int>> vv(m, vector<int>(n));
//	for (int i = 0; i < m; i++)
//		vv[i][0] = 1;
//	for (int i = 0; i < n; i++)
//		vv[0][i] = 1;
//	for (int i = 1; i < m; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
//		}
//	}
//	return vv[m - 1][n - 1];
//}
//int main()
//{
//	int m, n;
//	cin >> m>>n;
//	cout << Count_step(m, n) << endl;
//	return 0;
//}

#if 0
#include<iostream>
#include<string>
using namespace std;
int password_len(const string& str)
{
	if (str.size() <= 4)
		return 5;
	else if (str.size() <= 7)
		return 10;
	else
		return 25;
}
int password_char(const string& str)
{
	bool Up_count = false;
	bool Down_count = false;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			Up_count = true;
		if (str[i] >= 'a'&&str[i] <= 'z')
			Down_count = true;
	}
	if (Up_count && Down_count)
		return 20;
	else if ((Up_count && !Down_count) || (!Up_count&&Down_count))
		return 10;
	else
		return 0;
}
int password_digtal(const string& str)
{
	int count = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			count++;
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 20;
}
int password_sign(const string& str)
{
	int count = 0;
	for (int i = 0; i < (int)str.size(); i++)
	{
		if ((str[i] >= '!'&&str[i] <= '/') ||
			(str[i] >= ':'&&str[i] <= '@') ||
			(str[i] >= '['&&str[i] <= '`') ||
			(str[i] >= '{'&&str[i] <= '~'))
			count++;
	}
	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 25;
}
int Check_password_level(string& str)
{
	int score = 0;
	score += password_len(str);
	int ch = password_char(str);
	int datal = password_digtal(str);
	int sign = password_sign(str);
	score += (ch + datal + sign);
	if (ch == 20 && datal >= 10 && sign >= 10)
		score += 5;
	else if (ch == 10 && datal >= 10 && sign >= 10)
		score += 3;
	else  if (ch == 10 && datal >= 10)
		score += 2;
	return score;
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		int score = Check_password_level(str);
		if (score >= 90)
			cout << "VERY_SECURE" << endl;
		else if (score >= 80)
			cout << "SECURE" << endl;
		else if (score >= 70)
			cout << "VERY_STRONG" << endl;
		else if (score >= 60)
			cout << "STRONG" << endl;
		else if (score >= 50)
			cout << "AVERAGE" << endl;
		else if (score >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}
#endif 

#if 0
#include<iostream>
using namespace std;
int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool Is_leap(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return true;
	return false;
}
bool Is_legal(int year, int month, int day)
{
	if (month < 1 || month>12)
		return false;
	if (arr[month] < day || day < 1)
		return false;
	return true;
}
int GetOutDay(int year, int month, int day)
{
	arr[2] = 28;
	int outday=0;
	if (Is_leap(year))
		arr[2] += 1;
	if (!Is_legal(year, month, day))
		return -1;
	for (int i = 1; i < month; i++)
		outday += arr[i];
	outday += day;
	return outday;
}
int main()
{
	int y, m, d;
	while (cin >> y >> m >> d)
		cout << GetOutDay(y, m, d) << endl;
	return 0;
}
#endif 

#if 0
#include<iostream>
#include<cmath>
using namespace std;
bool Is_Pn(int x)
{
	int sum = x;
	for (int i = 1; i <= sqrt(x); i++)
	{
		if (x%i == 0)
		{
			if (i == 1)
				sum -= 1;
			else
				sum -= (i + (x / i));
		}
	}
	if (sum == 0)
		return true;
	else
		return false;
}
int Pn_count(int x)
{
	int count = 0;
	for (int i = 2; i <= x; i++)
	{
		if (Is_Pn(i))
			count++;
	}
	return count;
}
int main()
{
	int x;
	while (cin >> x)
		cout << Pn_count(x) << endl;
	return 0;
}
#endif 

#if 0
#include<iostream>
#include<string>
using namespace std;
void Cmp_puke(const string& str)
{
	string str1;
	string str2;
	size_t pos = str.find('-');
	if (string::npos == pos)
	{
		return;
	}
	else
	{
		str1 = str.substr(0, pos);
		str2 = str.substr(pos + 1);
	}
	int i = 0;
	while (string::npos != (pos = str1.find('1', i)))
	{
		str1[pos] = '*';
		str1.erase(pos + 1, 1);
		i = pos + 1;
	}
	i = 0;
	while (string::npos != (pos = str2.find('1', i)))
	{
		str2[pos] = '*';
		str2.erase(pos + 1, 1);
		i = pos + 1;
	}
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 == 1)
	{
		if (len2 == 1 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
		else
		{
			cout << str1 << endl;
			return;
		}
	}
	else if (len1 == 3)
	{
		if (len2 == 3 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
		else if (len2 == 3 && str1 > str2)
		{
			cout << str1 << endl;
			return;
		}
	}
	else if (len1 == 5)
	{
		if (len2 == 5 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
		else if (len2 == 5 && str1 > str2)
		{
			cout << str1 << endl;
			return;
		}
		else if (len2 == 3 && str1 > str2)
		{
			cout << str1 << endl;
			return;
		}
		else if (len2 == 3 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
	}
	else if (len1 == 9)
	{
		if (len2 == 9 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
		else if (len2 == 9 && str1 > str2)
		{
			cout << str1 << endl;
			return;
		}
	}
	else if (len1 == 7)
	{
		if (len2 == 7 && str1 < str2)
		{
			cout << str2 << endl;
			return;
		}
		else if (len2 == 7 && str1 > str2)
		{
			cout << str1 << endl;
			return;
		}
		else if (len2 != 7 && str2[0] != 'j')
		{
			cout << str1 << endl;
			return;
		}
	}
	if (str1[0] == 'j')
	{
		cout << str1 << endl;
		return;
	}
	if (str2[0] == 'j')
	{
		cout << str2 << endl;
		return;
	}
	else
		cout << "ERROR" << endl;
}
int main()
{
	string str;
	getline(cin, str);
	Cmp_puke(str);
	return 0;
}
#endif 


#if 0
#include<iostream>
#include<vector>
using namespace std;
int Even_first_out(int n)
{
	vector<vector<int>> vv(n);
	for (int i = 0; i < n ; i++)
		vv[i].resize(i * 2 + 1, 1);
	for (int i = 2; i < n ; i++)
		vv[i][1] = i;
	int k = 0;
	for (int i = 2; i < n ; i++)
	{
		k += 2;
		for (int j = 2; j <= k; j++)
			vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
		vv[i][i * 2 - 1] = vv[i][1];
		vv[i][i * 2] = vv[i][0];
	}
	for (int i = 0; i < (n - 1) * 2 + 1; i++)
	{
		if (vv[n - 1][i] % 2 == 0)
			return (i + 1);
	}
	return -1;
}
int main()
{
	int n;
	while (cin >> n)
		cout << Even_first_out(n) << endl;
	return 0;
}
#endif 

#if 0
#include<iostream>
#include<string>
using namespace std;
bool Judge_str(string& str1, string& str2)
{
	auto it1 = str1.begin();
	auto it2 = str2.begin();
	char c = 0;
	while ((it1 != str1.end()) && (it2 != str2.end()))
	{
		if (*it1 == *it2)
		{
			it1++;
			it2++;
		}
		else if (*it1 == '*')
		{
			if (++it1 != str1.end())
				c = *it1;
			else
				return true;
			while (c == '?'&&++it1 != str1.end())
				c = *it1;
			while ((it2 != str2.end()) && (*it2 != c))
				it2++;
			if (*(--it1) == '*')
			{
				it2++;
			}
			it1++;
			if (it2 == str2.end())
				return false;

		}
		else if (*it1 == '?')
		{
			it1++;
			it2++;
		}
		else
			return false;
	}
	return true;
}
int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		if (Judge_str(str1, str2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
#endif 

#include<iostream>
#include<string>
using namespace std;
void Find_substr(string& str1, string& str2)
{
	if (str1.size() > str2.size())
		str1.swap(str2);
	string ret;
	for (int j = 0; j < (int)str1.size(); j++)
	{
		for (int i = str1.size(); i >= j; i--)
		{
			string key = str1.substr(j,i-j);
			size_t pos = str2.find(key);
			if (string::npos != pos)
			{
				if (key.size() > ret.size())
					ret = key;
			}
		}
	}
	cout << ret << endl;
}
int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		Find_substr(str1, str2);
	}
	return 0;
}