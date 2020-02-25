#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

#if 0
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> v1;
	vector<int> v2(5, 3);
	vector<int> v3(&arr[0],&arr[10]);
	vector<int> v4(&arr[0], &arr[10]);
	vector<int>::reverse_iterator left;
	left = v4.rbegin();
	while (left < v4.rend())
	{
		cout << *left;
		cout << ' ';
		left++;
	}
	cout << endl;
	vector<int>::iterator s=v3.begin();
	for (auto& e : v3)
	{
		e = 0;
		cout << e;
		cout << ' ';
	}
	cout << v3[3] << endl;
	cout << endl;
	auto end = v3.end();
	while (end > v3.begin())
	{
		end--;
		cout << *end;
		cout << ' ';
	}
	cout << endl;

	system("pause");
	return 0;

}
#endif 
#if 0
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> v(arr,arr+10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(1);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(5, 9);
 	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	system("pause");
	return 0;
}
#endif 

#if 0
//class Solution {
//public:
//	vector<vector<int>> generate(int numRows)
//	{
//		vector<vector<int>>  vv;
//		vv.resize(numRows);
//		for (int i = 0; i < numRows; i++)
//		{
//			vv[i].resize(i + 1);
//		}
//		for (int i = 2; i < numRows; i++)
//		{
//			for (int j = 1; j < i; j++)
//			{
//
//				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//			}
//		}
//		return vv;
//	}
//};

//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums)
//	{
//
//		int sz = nums.size();
//		for (int i = 0; i < sz - 1;)
//		{
//			if (nums[i] == nums[i + 1])
//			{
//				nums.erase(nums.begin()+i+1);
//				sz = nums.size();
//			}
//			else
//			{
//				i++;
//			}
//		}
//		return sz;
//	}
//};

#include<algorithm>
//class Solution {
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		sort(nums.begin(), nums.end());
//		int sz = nums.size();
//		int ret = 0;
//		if (sz == 1)
//		{
//			ret = nums[0];
//			return ret;
//		}
//		int pre = nums[0];
//		int count = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (pre != nums[i])
//			{
//				if (count != 3)
//					ret = pre;
//				count = 0;
//				pre = nums[i];
//				count++;
//			}
//			else
//			{
//				count++;
//			}
//		}
//		return ret;
//	}
//};


//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		sort(numbers.begin(), numbers.end());
//		int ret = 0;
//		int sz = numbers.size();
//		int midsz = sz / 2;
//		int count = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (ret != numbers[i])
//			{
//				count = 0;
//				ret = numbers[i];
//			}
//			count++;
//			if (count > midsz)
//				return ret;
//		}
//		return ret;
//	}
//};

//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums)
//	{
//		vector<int> ret;
//		ret.reserve(2);
//		sort(nums.begin(), nums.end());
//		int sz = nums.size();
//		int count = 0;
//		int cur = 0;
//		int j = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (cur != nums[i])
//			{
//				if (count == 1)
//					ret.push_back(cur);
//				count = 0;
//				cur = nums[i];
//			}
//			count++;
//		}
//		if (count == 1)
//			ret.push_back(cur);
//		return ret;
//	}
//};

#if 0
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		int sz = array.size();
		if (sz == 0)
			return 0;
		int max = array[0];
		for (int i = 1; i < sz; i++)
		{
			if (max < array[i])
				max = array[i];
		}
		int sum = 0;
		int n = 0;
		while (n < sz)
		{
			sum = 0;
			for (int i = n; i < sz; i++)
			{
				sum = sum + array[i];
				if (max < sum)
					max = sum;
			}
			n++;
		}
		return max;
	}
};
int main()
{
	Solution s;
	//s.generate(5);
	int nums[] = { 6,-3,-2,7,-15,1,2,2 };
	vector<int> v(nums, nums +8);
	s.FindGreatestSumOfSubArray(v);
	system("pause");
	return 0;
}
#endif 

#include<stack>
class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		int sz = tokens.size();
		stack<int> s;
		for (int i = 0; i < sz; i++)
		{
			char* str = (char*)(tokens[i]).c_str();
			if ((str[0] != '+') && (str[0] != '-' || str[1] != '\0') && (str[0] != '*') && (str[0] != '/'))
			{
				s.push(atoi(str));
			}
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
	};
int main()
{
	Solution s;
	const char* arr[] = { "2", "1", "+", "3", "*" };
	vector<string> v(arr, arr + 5);
	s.evalRPN(v);
	system("pause");
	return 0;
}
#endif 

//#include<algorithm>
//using namespace std;
//class Solution
//{
//public:
//	void Sum(vector<int>& v, int n)
//	{
//		int len = v.size();
//		int ret = 0;
//		int count = 0;
//		sort(v.begin(), v.end());
//		for (int i = len - 2; i >= 0; i -= 2)
//		{
//			if (count >= n)
//				break;
//
//			ret += v[i];
//			count++;
//		}
//		cout << ret << endl;
//	}
//};
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	vector<int> v;
//	cin >> n;
//	v.resize(n * 3,0);
//	for (int i = 0; i < n * 3; i++)
//	{
//		cin >> v[i];
//	}
//	Solution s;
//	s.Sum(v, n);
//	return 0;
//}

#include<algorithm>
//class Solution {
//public:
//	void MoreThanHalfNum_Solution(vector<int> numbers)
//	{
//		int sz = numbers.size();
//		int ret = 0;
//		if (sz == 0)
//			ret = 0;
//		sort(numbers.begin(), numbers.end());
//		int midsz = sz / 2;
//		int count = 0;
//		for (int i = 0; i < sz; i++)
//		{
//			if (ret != numbers[i])
//			{
//				count = 0;
//				ret = numbers[i];
//			}
//			count++;
//			if (count > midsz)
//				break;
//		}
//		cout << ret << endl;
//	}
//};
//int main()
//{
//	vector<int> v;
//	while (getchar() != '\n')
//	{
//		int x = 0;
//		cin >> x;
//		v.push_back(x);
//	}
//	Solution s;
//	s.MoreThanHalfNum_Solution(v);
//	return 0;
//}


//class LongestDistance {
//public:
//	int getDis(vector<int> A, int n)
//	{
//		if (n == 0)
//			return 0;
//		int max = 0;
//		for (int i = 0; i < n - 1; i++)
//		{
//			int cur = A[i];
//			for (int j = i + 1; j < n; j++)
//			{
//				if (A[j] - cur < n)
//				{
//					int ret = A[j] - cur;
//					if (ret > max)
//						max = ret;
//				}
//			}
//		}
//		return max;
//	}
//};
//
//int main()
//{
//	int arr[] = {10,5 };
//	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	LongestDistance l;
//	l.getDis(v, sizeof(arr) / sizeof(arr[0]));
//	return 0;
//}
using namespace std;
//class Solution
//{
//public:
//	void  _count(vector<int> v, int n)
//	{
//		int i = 0;
//		sort(v.begin(), v.end());
//		int ret = 0;
//		int count = 0;
//		int key = n / 2;
//		for (i = 0; i < n; i++)
//		{
//			if (ret != v[i])
//			{
//				ret = v[i];
//				count = 0;
//			}
//			count++;
//			if (count >= key)
//				break;
//		}
//		cout<< ret;
//	}
//};
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	Solution s;
//	s._count(v, n);
//	return 0;
//}

//class Solution
//{
//public:
//	void Fib(vector<int>& v, int x)
//	{
//		int f0 = 0;
//		int f1 = 1;
//		int f2 = 0;
//		v.push_back(f0);
//		v.push_back(f1);
//		for (int i = 2; i <= x; i++)
//		{
//			f2 = f0 + f1;
//			f0 = f1;
//			f1 = f2;
//			if (f2 > 1000000)
//				break;
//			v.push_back(f2);
//		}
//	}
//	void Binarysearch(vector<int>& v, int* array, int n)
//	{
//		size_t len = v.size();
//		int left = 0;
//		int right = len - 1;
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = ((right - left) / 2) + left;
//			if (v[mid == n])
//				return;
//			else if (v[mid] > n)
//			{
//				array[1] = v[mid];
//				right = mid - 1;
//			}
//			else
//			{
//				array[0] = v[mid];
//				left = mid + 1;
//			}
//		}
//		return;
//	}
//	int min_steep(vector<int>& v, int n)
//	{
//		Fib(v, n);
//		int array[2] = { 0 };
//		Binarysearch(v, array, n);
//		if (array[0] == 0 && array[1] == 0)
//			return 0;
//		int min = array[1] - n;
//		if (min > n - array[0])
//		{
//			min = n - array[0];
//		}
//		return min;
//	}
//};
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.reserve(1000000);
//	Solution s;
//	cout << s.min_steep(v, n);
//	return 0;
//}

//#include<string>
//#include<stack>
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n)
//	{
//		string B;
//		B.reserve(n);
//		if (n == 0)
//			return true;
//		for (int i = n - 1; i >= 0; i--)
//		{
//			B.push_back(A[i]);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if ((A[i] == '('&&B[i] == ')')
//				|| (A[i] == ')'&&B[i] == '(')
//				|| (A[i] == ')'&&B[i] == ')')
//				|| (A[i] == '('&&B[i] == '('))
//				;
//			else
//				return false;
//		}
//		return true;
//	}
//};
//int main()
//{
//	string s("()()(((())))");
//	Parenthesis p;
//	cout<<p.chkParenthesis(s,s.size());
//	return 0;
//}


//int main()
//{
//	int w, h;
//	int ret = 0;
//	cin >> h;
//	cin >> w;
//	vector<vector<int>> v;
//	v.resize(h);
//	for (int i = 0; i < h; i++)
//	{
//		v[i].resize(w,1);
//	}
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			if (i + 2 < h)
//				v[i + 2][j] = 1;
//			if (j + 2 < w)
//				v[i][j + 2] = 1;
//		}
//	}
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			if (v[i][j] != 1)
//				ret++;
//		}
//
//	}
//	cout << ret;
//}

//class Solution
//{
//public:
//	int Steep(int n, int m)
//	{
//		int h = n + 1;
//		int l = m + 1;
//		vector<vector<int>> v;
//		v.resize(h);
//		for (int i = 0; i < h; i++)
//		{
//			v[i].resize(l, 1);
//		}
//		for (int i = 1; i < h; i++)
//		{
//			for (int j = 1; j < l; j++)
//			{
//				v[i][j] = v[i - 1][j] + v[i][j - 1];
//			}
//		}
//		return v[h - 1][l - 1];
//	}
//};
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	Solution s;
//	cout << s.Steep(n, m);
//	return 0;
//}




//int main() {
//	int m, n;
//	while (cin >> m >> n) {
//		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				if (i == 0 && j == 0) {
//					dp[i][j] = 1;
//					continue;
//				}
//				if (i == 0) {    // 上边界
//					dp[i][j] = dp[i][j - 1];
//				}
//				else if (j == 0) {    // 左边界
//					dp[i][j] = dp[i - 1][j];
//				}
//				else {
//					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//				}
//			}
//		}
//		cout << dp[n][m] << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i)
//	{
//		int index = 0;
//		bool flag = true;
//		int arr_n[32] = { 0 };
//		int ret = 0;
//		int m_count = 0;
//		int c = 0;
//		for (index = 0; index < 32; index++)
//		{
//				c++;
//				if (((m >> index) & 1) == 1)
//					m_count = c;
//		}
//		for (index = 0; index < 32; index++)
//		{
//			arr_n[31 - index] = ((n >> index) & 1);
//		}
//		for (index = j; index < i + 1; index++)
//		{
//			if (((n >> index) & 1) != 0)
//				flag = false;
//		}
//		if ((i - j + 1 >= m_count) && flag)
//		{
//			for (index = 0; index < m_count; index++)
//			{
//				arr_n[31 - j] = ((m >> index) & 1);
//				j++;
//			}
//		}
//		for (index = 0; index < 32; index++)
//		{
//			int pow = 1;
//			if (arr_n[31 - index] == 1)
//			{
//				if (index == 0)
//					pow = 1;
//				for (int k = 1; k <= index; k++)
//				{
//					pow = pow * 2;
//				}
//				ret = ret + arr_n[31 - index] * pow;
//			}
//		}
//		return ret;
//	}
//};
//
//int main()
//{
//	BinInsert b;
//	b.binInsert(1024, 19, 2, 6);
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	int arr[2] = { 0 };
//	v.reserve(20000);
//	int min = n;
//	int ret = 0;
//	int flag = 0;
//	int j = 0;
//	for (int i = 1; i <= n / 2; i++)
//	{
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(i))
//			v.push_back(i);
//	}
//	int len = v.size();
//	for (int i = 0; i < len; i++)
//	{
//		for ( j = 2; j <= sqrt(n - v[i]); j++)
//		{
//			if ((n - v[i]) % j == 0)
//			{
//				break;
//			}
//		}
//		if (j > sqrt(n - v[i]))
//		{
//			ret = (n - v[i]) - v[i];
//			if (min > ret)
//			{
//				min = ret;
//				arr[0] = v[i];
//				arr[1] = n - v[i];
//			}
//		}
//	}
//	cout << arr[0] << endl;
//	cout << arr[1] << endl;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	bool Is_leap(int year)
//	{
//		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
//			return true;
//		return false;
//	}
//	Date(int year, int month, int day)
//	{
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		{
//			if (day >= 1 && day <= 31)
//			{
//				_year = year;
//				_month = month;
//				_day = day;
//				outday = 0;
//			}
//			else
//				outday = -1;
//		}
//		else if (month == 4 || month == 6 || month == 9 || month == 11)
//		{
//			if (day >= 1 && day <= 30)
//			{
//				_year = year;
//				_month = month;
//				_day = day;
//				outday = 0;
//			}
//			else
//				outday = -1;
//		}
//		else if (month == 2)
//		{
//			if (Is_leap(year))
//			{
//				if (day >= 1 && day <= 29)
//				{
//					_year = year;
//					_month = month;
//					_day = day;
//					outday = 0;
//				}
//				else
//					outday = -1;
//			}
//			else
//			{
//				if (day >= 1 && day <= 28)
//				{
//					_year = year;
//					_month = month;
//					_day = day;
//					outday = 0;
//				}
//				else
//					outday = -1;
//			}
//		}
//		else
//			outday = -1;
//	}
//	int Sum()
//	{
//		if (outday == -1)
//			return -1;
//		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		int sum = 0;
//		for (int i = 1; i < _month; i++)
//		{
//			sum += arr[i];
//		}
//		sum += _day;
//		if (Is_leap(_year))
//		{
//			sum += 1;
//		}
//		return sum;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int outday;
//};
//int main()
//{
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		Date d(year, month, day);
//		cout << d.Sum();
//	}
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int Sum(vector<int>& v)
//{
//	int count = 0;
//	int n = v.size();
//	int sum = v[0] + v[1];
//	int mul = v[0] * v[1];
//	if (sum > mul)
//		count++;
//	for (int i = 2; i < n; i++)
//	{
//		if ((sum + v[i]) > (mul*v[i]))
//			count++;
//	}
//	for (int i = 3; i < n; i++)
//	{
//		if ((sum + v[i]) > (mul*v[i]))
//		{
//			count++;
//			sum = sum + v[i];
//			mul = mul * v[i];
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	v.reserve(n);
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//	cout << Sum(v) << endl;
//}

//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target)
//	{
//		sort(nums.begin(), nums.end());
//		int min = 0;
//		int sum = 0;
//		int min_sum = 0;
//		int cur_min = INT_MAX;
//		for (size_t i = 0; i < nums.size() - 2; i++)
//		{
//			int left = i+1;
//			int right = nums.size() - 1;
//			while (left < right)
//			{
//				sum = nums[i] + nums[left] + nums[right];
//				min = abs(sum - target);
//				if (cur_min > min)
//				{
//					min_sum = sum;
//					cur_min = min;
//				}
//				if (sum < target)
//				{
//					left++;
//				}
//				else
//				{
//					right--;
//				}
//			}
//		}
//		return min_sum;
//	}
//};

//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums)
//	{
//		sort(nums.begin(), nums.end());
//		int sum = 0;
//		vector<vector<int>> v;
//		int j = 1;
//		for (size_t i = 0; i < nums.size() - 2; i++)
//		{
//			int left = i + 1;
//			int right = nums.size() - 1;
//			while (left < right)
//			{
//				sum = nums[i] + nums[left] + nums[right];
//				if (sum==0)
//				{
//					v.resize(j);
//					v[j-1].push_back(nums[i]);
//					v[j-1].push_back(nums[left]);
//					v[j-1].push_back(nums[right]);
//					j++;
//				}
//				if (sum < 0)
//				{
//					left++;
//					while (nums[left] == nums[left - 1 ]&& left < right)
//						left++;
//				}
//				else
//				{
//					right--;
//					while (nums[right] == nums[right + 1]&&left<right)
//						right--;
//				}
//			}
//			while(nums[i] == nums[i + 1] && i < nums.size() - 3)
//				i++;
//		}
//		return 1;
//	}
//};

//class Solution {
//public:
//	vector<vector<int>> fourSum(vector<int>& nums, int target)
//	{
//		sort(nums.begin(), nums.end());
//		int sum = 0;
//		vector<vector<int>> v;
//		int j = 1;
//		for (size_t cur = 0; cur < nums.size() - 3; cur++)
//		{
//			for (size_t i = cur + 1; i < nums.size() - 2; i++)
//			{
//				int left = i + 1;
//				int right = nums.size() - 1;
//				while (left < right)
//				{
//					sum = nums[cur] + nums[i] + nums[left] + nums[right];
//					if (sum == target)
//					{
//						v.resize(j);
//						v[j - 1].push_back(nums[cur]);
//						v[j - 1].push_back(nums[i]);
//						v[j - 1].push_back(nums[left]);
//						v[j - 1].push_back(nums[right]);
//						j++;
//					}
//					if (sum < target)
//					{
//						left++;
//						while (nums[left] == nums[left - 1] && left < right)
//							left++;
//					}
//					else
//					{
//						right--;
//						while (nums[right] == nums[right + 1] && left < right)
//							right--;
//					}
//				}
//				while (nums[i] == nums[i + 1] && i < nums.size() - 2)
//					i++;
//			}
//			while (nums[cur] == nums[cur + 1] && cur < nums.size() - 3)
//				cur++;
//		}
//		return v;
//	}
//};
//int main()
//{
//	Solution s;
//	int arr[] = { -1,-5,-5,-3,2,5,0,4};
//	vector<int> v(arr, arr + 8);
//	s.fourSum(v,-7);
//	system("pause");
//	return 0;
//}

//class Solution {
//	int Mid(vector<int>& nums, int left, int right,int target)
//	{
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = (left + right) / 2;
//			if (nums[mid] == target)
//			{
//				return mid;
//			}
//			else if (nums[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else
//			{
//				left = mid + 1;
//			}
//		}
//		return -1;
//	}
//public:
//	int search(vector<int>& nums, int target)
//	{
//		if (nums.size() == 0)
//			return -1;
//		if (nums.size() == 1)
//		{
//			if (nums[0] == target)
//				return 0;
//			else
//				return -1;
//		}
//		int left = 0;
//		int right = nums.size() - 1;
//		int mid = 0;
//		while (nums[left] >= nums[right])
//		{
//			if (right - left == 1)
//			{
//				mid = right;
//				break;
//			}
//			mid = (left + right) / 2;
//			if (nums[mid] >= nums[left])
//			{
//				left = mid;
//			}
//			else if (nums[mid] <= nums[right])
//			{
//				right = mid;
//			}
//		}
//		if (mid == 0)
//		{
//			return Mid(nums, 0, nums.size() - 1, target);
//		}
//		if (nums[0] > nums[mid] && nums[0] > target)
//		{
//			return Mid(nums, mid, nums.size() - 1, target);
//		}
//		else
//		{
//			return Mid(nums, 0, mid - 1, target);
//		}
//	}
//};

//class Solution {
//public:
//	int Mid(vector<int>& nums, int left, int right, int target)
//	{
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = (left + right) / 2;
//			if (nums[mid] == target)
//			{
//				return mid;
//			}
//			else if (nums[mid] > target)
//			{
//				right = mid - 1;
//			}
//			else
//			{
//				left = mid + 1;
//			}
//		}
//		return -1;
//	}
//public:
//	vector<int> searchRange(vector<int>& nums, int target)
//	{
//		vector<int> v;
//		v.resize(2, -1);
//		if (nums.size() == 0)
//			return v;
//		int left = 0;
//		int right = nums.size() - 1;
//		int cur = Mid(nums, left, right, target);
//		int pos1 = cur, pos2 = cur;
//		int start = -1, end = -1;
//		while (pos1 != -1)
//		{
//			start = pos1;
//			pos1 = Mid(nums, left, pos1-1, target);
//		}
//		while (pos2 != -1)
//		{
//			end = pos2;
//			pos2 = Mid(nums, pos2+1, right, target);
//		}
//		v[0] = start;
//		v[1] = end;
//		return v;
//	}
//};

//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums)
//	{
//		size_t i = 0;
//		while (1)
//		{
//			bool flag = false;
//			for (i = 0; i < nums.size(); i++)
//			{
//				if (nums[i]>0&&nums[i] <= (int)nums.size()&& nums[i]!= nums[nums[i] - 1])
//				{
//					swap(nums[i], nums[nums[i] - 1]);
//					flag = true;
//				}
//			}
//			if (flag == false)
//				break;
//		}
//		for (i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] != i + 1)
//				break;
//		}
//		return i + 1;
//	}
//};

//class Solution {
//public:
//	int trap(vector<int>& height)
//	{
//		int sz = height.size();
//		int left = 0;
//		vector<int> copy(height);
//		int right = sz - 1;
//		int left1 = 0;
//		int right1 = sz - 1;
//		int sum = 0;
//		while (left < right)
//		{
//			if (height[left] == 0)
//				left++;
//			if (height[right] == 0)
//				right--;
//			left1 = left;
//			int k = 0;
//			if (height[left1] <= height[right])
//			{
//				while (left1 < right)
//				{
//					k = height[left];
//					left1++;
//					if (height[left1] < k)
//						height[left1] = k;
//				}
//				while (left<right)
//				{
//					left++;
//					if (height[left] > k)
//						break;
//				}
//			}
//			if(height[left] > height[right])
//			{	
//				right1 = right;
//				while (left < right1)
//				{
//					 k = height[right];
//					right1--;
//					if (height[right1] < k)
//						height[right1] = k;
//				}
//				while (left < right)
//				{
//					right--;
//					if (height[right] > k)
//						break;
//				}
//			}
//		}
//		for (int i = 0; i < sz; i++)
//		{
//			sum = sum + (height[i] - copy[i]);
//		}
//		return sum;
//	}
//};
//int main()
//{
//	Solution s;
//	int arr[] = { 0,2,0};
//    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
//	s.trap(v);
//	return 0;
//}

//
//class Solution {
//public:
//	int jump(vector<int>& nums)
//	{
//		int len = nums.size();
//		int cur = nums[0];
//		if (cur >= len)
//			return 1;
//		int j = 1;
//		int max = -1;
//		int minstep = 0;
//		int pos = 0;
//		while (j < len)
//		{
//			for (int i = j; i < cur+j; i++)
//			{
//				if (i<len && nums[i] >= max)
//				{
//					max = nums[i];
//					pos = i + 1;
//				}
//			}
//			if (max < cur)
//			{
//				pos = j + cur;
//			}
//			cur = max;
//			max = -1;
//			j = pos;
//			minstep++;
//		}
//		return minstep;
//	}
//};


//class Solution {
//	public:
//		int jump(vector<int>& nums)
//		{
//			int end = 0;
//			int maxPosition = 0;
//			int i = 0;
//			for (; i < (int)nums.size() - 1; i++)
//			{
//				//找能跳的最远的
//				if(maxPosition < (nums[i] + i))
//					maxPosition =  nums[i] + i;
//				if (i == end)
//				{ //遇到边界，就更新边界，并且步数加一
//					end = maxPosition;
//				}
//			}
//			if (end != (int)nums.size()-1)
//				return false;
//			else
//				return true;
//		}
//};
//int main()
//{
//	int arr[] = { 2,0};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	vector<int> v(arr,arr+sz);
//	Solution s;
//	cout<<s.jump(v);
//	return 0;
//}

//class Solution {
//public:
//	int uniquePaths(int m, int n)
//	{
//		if (m == 1 || n == 1)
//			return 1;
//		int path_count = 0;
//		vector<vector<int>> v;
//		v.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			v[i].resize(m, 1);
//		}
//		int i = 1;
//		int j = 1;
//		for (; i < n; i++)
//		{
//			j = 1;
//			for (; j < m; j++)
//			{
//					v[i][j] = v[i - 1][j] + v[i][j - 1];
//			}
//		}
//		path_count = v[i-1][j-1];
//		return path_count;
//	}
//};

//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& v)
//	{
//
//		long long path_count = 0;
//		vector<vector<long long>> v1;
//		int n = v.size();
//		int m = v[n - 1].size();
//		bool row = false;
//		bool col = false;
//		v1.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			v1[i].resize(m, 0);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				v1[i][j] = v[i][j];
//			}
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (v1[i][0] == 0)
//				v1[i][0] = 1;
//			else if (v1[i][0] == 1)
//			{
//				v1[i][0] = 0;
//				col = true;
//			}
//		}
//		for (int i = 1; i < m; i++)
//		{
//			if (v1[0][i] == 0)
//				v1[0][i] = 1;
//			else if (v1[0][i] == 1)
//			{
//				v1[0][i] = 0;
//				row = true;
//			}
//		}
//		if ((n == 1 && row)||(m == 1 && col))
//			return 0;
//		if ((n == 1 && !row) || (m == 1 && !col))
//			return 1;
//		int i = 1;
//		int j = 1;
//		for (; i < n; i++)
//		{
//			j = 1;
//			for (; j < m; j++)
//			{
//				if (v1[i][j] != 1)
//					v1[i][j] = v1[i - 1][j] + v1[i][j - 1];
//				else
//					v1[i][j] = 0;
//			}
//		}
//		path_count = v1[i - 1][j - 1];
//		return (int)path_count;
//	}
//};

//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits)
//	{
//		int len = digits.size();
//		digits.resize(len+1);
//		int step = 0;
//		for (int i = len - 1; i >= 0; i--)
//		{
//			if (i == len - 1)
//				digits[i+1] = digits[i] + 1;
//			else
//				digits[i+1] = digits[i] + step;
//			step = 0;
//			if (digits[i+1] > 9)
//			{
//				step = 1;
//				digits[i+1] -= 10;
//			}
//		}
//		if (step == 1)
//			digits[0] = 1;
//		else
//			digits.erase(digits.begin());
//		return digits;
//	}
//};
//int main()
//{ 
//	int arr[] = { 1,2,3 };
//	vector<int> v(arr,arr+3);
//	Solution s;
//	s.plusOne(v);
//	return 0;
//}


//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix)
//	{
//		int m = matrix.size();
//		int n = matrix[m - 1].size();
//		vector<int> v;
//		v.reserve(m*n);
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (matrix[i][j] == 0)
//				{
//					v.push_back(i);
//					v.push_back(j);
//				}
//			}
//		}
//		for (int i = 0; i < (int)v.size(); i += 2)
//		{
//			int x = v[i];
//			int y = v[i + 1];
//			while (v[i] > 0)
//			{
//				v[i]--;
//				matrix[v[i]][v[i + 1]] = 0;
//			}
//			v[i] = x;
//			while (v[i] < m-1)
//			{
//				v[i]++;
//				matrix[v[i]][v[i + 1]] = 0;
//			}
//			v[i] = x;
//			while (v[i+1] > 0)
//			{
//				v[i+1]--;
//				matrix[v[i]][v[i + 1]] = 0;
//			}
//			v[i+1] = y;
//			while (v[i + 1] < n-1)
//			{
//				v[i + 1]++;
//				matrix[v[i]][v[i + 1]] = 0;
//			}
//			v[i + 1] = y;
//		}
//	}
//};


//class Solution {
//private:
//	bool Binary_search(vector<int>& v, int sz, int target)
//	{
//		int left = 0;
//		int right = sz - 1;
//		int mid = 0;
//		while (left <= right)
//		{
//			mid = (left + right) / 2;
//			if (v[mid] == target)
//				return true;
//			else
//				if (v[mid] > target)
//				{
//					right = mid - 1;
//				}
//				else
//					left = mid + 1;
//		}
//		return false;
//	}
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target)
//	{
//		//if (matrix.empty())
//			//return false;
//		if (matrix.size() == 0)
//			return false;
//		if (matrix.size() != 0 && matrix[0].size() == 0)
//			return false;
//		int m = matrix.size();
//		int n = matrix[m - 1].size();
//		if (target<matrix[0][0] || target>matrix[m - 1][n - 1])
//			return false;
//		for (int i = 0; i < m - 1; i++)
//		{
//			if (target >= matrix[i][0] && target < matrix[i + 1][0])
//				return Binary_search(matrix[i], n, target);
//		}
//		if(target >= matrix[m-1][0] && target <= matrix[m-1][n-1])
//			return Binary_search(matrix[m-1], n, target);
//		return false;
//	}
//};
//int main()
//{
//	int arr[3][4] = { {1,3,5,7},
//					{10,11,16,20},
//					{23,30,34,50} };
//	vector<vector<int> > v;
//	Solution s;
//	s.searchMatrix(v,23);
//	return 0;
//}

//class Solution {
//public:
//	void sortColors(vector<int>& nums)
//	{
//		int len = nums.size();
//		vector<int> v;
//		v.resize(3, 0);
//		for (int i = 0; i < len; i++)
//		{
//			v[nums[i]]++;
//		}
//		int j = 0;
//		for (int i = 0; i < (int)v.size(); i++)
//		{
//			while (v[i] != 0)
//			{
//				nums[j++] = i;
//				v[i]--;
//			}
//		}
//	}
//};


//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int> > res(1);
//		for (int i = 0; i < (int)nums.size(); i++) {
//			int cnt = res.size();
//			for (int j = 0; j < cnt; j++) {
//				vector<int> tmp = res[j];
//				tmp.push_back(nums[i]);
//				res.push_back(tmp);
//			}
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	int arr[] = {1,2,3,4};
//	vector<int> v(arr, arr + 4);
//	Solution s;
//	s.subsets(v);
//	return 0;
//}


//class Solution {
//private:
//	bool search_path(int x, int y, vector<vector<char>>& board, string word)
//	{
//
//		int sz = word.size();
//		int m = board.size();
//		int n = board[m - 1].size();
//		int i = 1;
//		bool flag = false;
//		bool bz = false;
//		bool left = true;
//		bool right = true;
//		bool up = true;
//		bool down = true;
//		while (1)
//		{
//			if (x - 1 >= 0 && up)
//			{
//				if (board[x - 1][y] == word[i])
//				{
//					sz--;
//					i++;
//					x--;
//					bz = true;
//					down = false;
//					 left = true;
//					 right = true;
//					 up = true;
//				}
//			}
//			if (y - 1 >= 0 && left)
//			{
//				if (board[x][y - 1] == word[i])
//				{
//					sz--;
//					i++;
//					y--;
//					bz = true;
//					right = false;
//					down = true;
//					left = true;
//					up = true;
//				}
//			}
//			if (x + 1 < m && down)
//			{
//				if (board[x + 1][y] == word[i])
//				{
//					sz--;
//					i++;
//					x++;
//					bz = true;
//					up = false;
//					right = true;
//					down = true;
//					left = true;
//				}
//			}
//			if (y + 1 < n && right)
//			{
//				if (board[x][y + 1] == word[i])
//				{
//					sz--;
//					i++;
//					y++;
//					bz = true;
//					left = false;
//					up = true;
//					right = true;
//					down = true;
//				}
//			}
//			if (sz - 1 == 0)
//			{
//				flag = true;
//				break;
//			}
//			if (bz == false)
//			{
//				flag = false;
//				break;
//			}
//		}
//		return flag;
//	}
//public:
//	bool exist(vector<vector<char>>& board, string word)
//	{
//		int m = board.size();
//		int n = board[m - 1].size();
//		vector<int> v;
//		v.reserve(m*n);
//		bool flag = false;
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (board[i][j] == word[0])
//				{
//					v.push_back(i);
//					v.push_back(j);
//				}
//			}
//		}
//		for (int i = 0; i < (int)v.size(); i += 2)
//		{
//			flag = search_path(v[i], v[i + 1], board, word);
//			if (flag == true)
//				break;
//		}
//		return flag;
//	}
//};
//int main()
//{
//	char arr[3][4] = { {'C','A','A' },
//	{'A','A','A' },
//  {'B','C' ,'D'}
//					 };
//	vector<vector<char> > b(3,vector<char>(3));
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			b[i][j] = arr[i][j];
//		}
//	}
//	Solution s;
//	s.exist(b,"AAB");
//	return 0;
//}


//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums)
//	{
//		int len = nums.size();
//		int cur = 1;
//		int ptr = 1;
//		int key = nums[0];
//		int count = 1;
//		for (int i = 1; i < len; i++)
//		{
//			if (cur != ptr)
//				nums[cur] = nums[ptr];
//			if (nums[i] == key)
//				count++;
//			else
//			{
//				count = 1;
//				key = nums[i];
//			}
//			if (count < 3)
//			{
//				cur++;
//			}
//			ptr++;
//		}
//		return cur;
//	}
//};


//int main()
//{
//	int arr[] = { 0,0,1,1,1,1,2,3,3 };
//	vector<int> v(arr, arr + 9);
//	Solution s;
//	s.removeDuplicates(v);
//	return 0;
//}


//class Solution {
//public:
//	vector<int> getRow(int rowIndex)
//	{
//		vector<int> v;
//		if (rowIndex < 0)
//			return v;
//		v.resize(rowIndex+1, 1);
//		vector<vector<int>> vv;
//		vv.resize(rowIndex+1);
//		for (int i = 0; i <= rowIndex; i++)
//		{
//			vv[i].resize(i+1 , 1);
//		}
//		for (int i = 2; i <= rowIndex; i++)
//		{
//			for (int j = 1; j < i; j++)
//			{
//				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//			}
//		}
//		for (int i = 0; i <= rowIndex; i++)
//		{
//			v[i] = vv[rowIndex][i];
//		}
//		return v;
//	}
//};

//class Solution {
//public:
//	vector<int> getRow(int rowIndex) {
//		vector<int> res(rowIndex + 1, 0);
//		res[0] = 1;
//		for (int i = 1; i < rowIndex + 1; i++)
//		{
//			for (int j = i; j >= 1; j--)
//				res[j] += res[j - 1];
//		}
//
//		return res;
//	}
//};
//
//int main()
//{
//	Solution s;
//	s.getRow(3);
//	return 0;
//}


//int count(int n)
//{
//	int count = 0;
//	for (int i = 2; i <= n; i++)
//	{
//		int k = i;
//		for (int j = 1; j <= i / 4; j++)
//		{
//			if (i%j == 0)
//			{
//				int p = i / j;
//				if (j != 1)
//					k = k - j - p;
//				else
//					k = k - j;
//			}
//			if (k == 0)
//			{
//				count++;
//				break;
//			}
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//		cout << count(n) << endl;
//	return 0;
//}

#include<stdio.h>
int main()
{
	char *p = "abc";
	char *q = "abc123";
	while (*p = *q)
		printf("%c %c", *p, *q);
}