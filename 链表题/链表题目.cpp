#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

//struct list_node {
//	int val;
//	struct list_node * next;
//};
//struct double_list_node {
//	int val;
//	struct double_list_node * pre, *next;
//};
//
//list_node * input_list(void)
//{
//	int n, val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//double_list_node * input_double_list(void)
//{
//	int n, val;
//	double_list_node * phead = new double_list_node();
//	double_list_node * cur_pnode = phead;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//			cur_pnode->pre = NULL;
//		}
//		else {
//			double_list_node * new_pnode = new double_list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			new_pnode->pre = cur_pnode;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//list_node * reverse_list(list_node * head)
//{
//	//////在下面完成代码
//	list_node * newhead = nullptr;
//	list_node * cur = head->next;
//	while (head)
//	{
//		if (newhead == nullptr)
//		{
//			newhead = head;
//			newhead->next = nullptr;
//		}
//		else
//		{
//			cur = head->next;
//			head->next = newhead;
//			newhead = head;
//		}
//		head = cur;
//	}
//	return newhead;
//}
//
//double_list_node * reverse_double_list(double_list_node * head)
//{
//	//////在下面完成代码
//	double_list_node * newhead = nullptr;
//	double_list_node * cur = head->next;
//	while (head)
//	{
//		if (newhead == nullptr)
//		{
//			newhead = head;
//			newhead->next = nullptr;
//		}
//		else
//		{
//			cur = head->next;
//			head->next = newhead;
//			newhead->pre = head;
//			newhead = head;
//		}
//		head = cur;
//	}
//	return newhead;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//void print_double_list(double_list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	list_node * head = input_list();
//	double_list_node * double_head = input_double_list();
//	list_node * new_head = reverse_list(head);
//	double_list_node * new_double_head = reverse_double_list(double_head);
//	print_list(new_head);
//	print_double_list(new_double_head);
//	return 0;
//}


//反转部分单向链表
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list(void)
//{
//	int n, val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//list_node * reverse_list(list_node * head, int L, int R)
//{
//	//////在下面完成代码
//	list_node * pre = nullptr;
//	list_node * cur = head;
//	R -= L;
//	while (--L)
//	{
//		pre = cur;
//		cur = cur->next;
//	}
//	list_node * svr = cur;
//	list_node * svrkeep = cur;
//	cur = cur->next;
//	list_node * keep_pre = nullptr;
//	while (R--)
//	{
//		keep_pre = cur->next;
//		cur->next = svr;
//		svr = cur;
//		cur = keep_pre;
//	}
//	if (pre != nullptr)
//	{
//		pre->next = svr;
//		svr = head;
//	}
//	svrkeep->next = keep_pre;
//	return svr;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//
//int main()
//{
//	int L, R;
//	list_node * head = input_list();
//	scanf("%d%d", &L, &R);
//	list_node * new_head = reverse_list(head, L, R);
//	print_list(new_head);
//	return 0;
//}

//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//	int n, m;
//	list<int> l;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		l.push_back(i);
//	auto it = l.begin();
//	while (l.size() > 1)
//	{
//		int keep = m;
//		while (--m)
//		{
//			it++;
//			if (it == l.end())
//				it = l.begin();
//		}
//		it = l.erase(it);
//		if (it == l.end())
//			it = l.begin();
//		m = keep;
//	}
//	it = l.begin();
//	cout << *it << endl;
//	return 0;
//}


//判断回文结构
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list(void)
//{
//	int n, val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//bool  check(list_node * head)
//{
//	//////在下面完成代码
//	list_node* fast = head;
//	list_node* slow = head;
//	list_node* newhead = nullptr;
//	while (fast)
//	{
//		slow = slow->next;
//		if (fast->next == nullptr)
//			break;
//		fast = fast->next->next;
//	}
//	list_node* keep = nullptr;
//	while (slow)
//	{
//		keep = slow->next;
//		if (newhead == nullptr)
//		{
//			newhead = slow;
//			slow->next = nullptr;
//		}
//		else
//		{
//			slow->next = newhead;
//			newhead = slow;
//		}
//		slow = keep;
//	}
//	while (newhead)
//	{
//		if (newhead->val != head->val)
//			return false;
//		newhead = newhead->next;
//		head = head->next;
//	}
//	return true;
//}
//
//
//int main()
//{
//	int L, R;
//	list_node * head = input_list();
//	check(head);
//	return 0;
//}


//大于 小于，等于给定值，分链表
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//int pivot;
//
//list_node * input_list(void)
//{
//	int n, val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	scanf("%d%d", &n, &pivot);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//list_node * list_partition(list_node * head, int pivot)
//{
//	//////在下面完成代码
//	list_node * head_a = new list_node();
//	list_node * end_a = head_a;
//	list_node * head_b = nullptr;
//	list_node * head_c = nullptr;
//	while (head)
//	{
//		list_node * keep = head->next;
//		if (head->val == pivot)
//		{
//			head->next = head_b;
//			head_b = head;
//		}
//		else if (head->val > pivot)
//		{
//			head->next = head_c;
//			head_c = head;
//		}
//		else
//		{
//			end_a->next = head;
//			end_a = head;
//		}
//		head = keep;
//	}
//	if (head_b)
//	{
//		end_a->next = head_b;
//		while (head_b->next)
//			head_b = head_b->next;
//		head_b->next = head_c;
//	}
//	else
//		end_a->next = head_c;
//	return head_a->next;
//}
//
//
//int main()
//{
//	list_node * head = input_list();
//	list_node * cur = list_partition(head, pivot);
//	while (cur)
//	{
//		cout << cur->val << " ";
//		cur = cur->next;
//	}
//	cout << endl;
//	return 0;
//}

//链表值相加
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list(int n)
//{
//	int val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//int Reserve(list_node *& head)
//{
//	list_node* newhead = nullptr;
//	int count = 0;
//	while (head)
//	{
//		list_node* keep = head->next;
//		head->next = newhead;
//		newhead = head;
//		head = keep;
//		count++;
//	}
//	head = newhead;
//	return count;
//}
//list_node * add_list(list_node * head1, list_node * head2)
//{
//	//////在下面完成代码
//	int len1 = Reserve(head1);
//	int len2 = Reserve(head2);
//	if (len1 < len2)
//	{
//		swap(head1, head2);
//		swap(len1, len2);
//	}
//	list_node * ret = nullptr;
//	int step = 0;
//	int sum = 0;
//	while (head1)
//	{
//		sum += head1->val + step;
//		step = 0;
//		if (head2)
//			sum += head2->val;
//		head1 = head1->next;
//		if (head2)
//			head2 = head2->next;
//		if (sum > 9)
//		{
//			step = 1;
//			sum -= 10;
//		}
//		list_node * cur = new list_node();
//		cur->val = sum;
//		cur->next = ret;
//		ret = cur;
//		sum = 0;
//	}
//	if (step != 0)
//	{
//		list_node * cur = new list_node();
//		cur->val = step;
//		cur->next = ret;
//		ret = cur;
//	}
//	return ret;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	list_node * head1 = input_list(n), *head2 = input_list(m);
//	list_node * new_head = add_list(head1, head2);
//	print_list(new_head);
//	return 0;
//}

//将单链表的每K个节点之间逆序
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list()
//{
//	int val, n;
//	scanf("%d", &n);
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//list_node * reverse_knode(list_node * head1, int K)
//{
//	//////在下面完成代码
//	list_node *cur = head1;
//	int count = 0;
//	while (cur)
//	{
//		cur = cur->next;
//		count++;
//	}
//	count /= K;
//	list_node * newhead = new list_node();
//	list_node * ret = newhead;
//	cur = newhead->next;
//	list_node * keep = nullptr;
//	int kp = K;
//	while (count--)
//	{
//		int kp = K;
//		while (K--)
//		{
//			keep = head1->next;
//			head1->next = cur;
//			cur=head1;
//			ret->next = cur;
//			head1 = keep;
//		}
//		while (cur)
//		{
//			ret = cur;
//			cur = cur->next;
//		}
//		K = kp;
//	}
//	ret->next = keep;
//	return newhead->next;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	list_node * head = input_list();
//	int K;
//	scanf("%d", &K);
//	list_node * new_head = reverse_knode(head, K);
//	print_list(new_head);
//	return 0;
//}

//#include<unordered_set>
////删除无序链表中值重复出现的节点
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list()
//{
//	int val, n;
//	scanf("%d", &n);
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//list_node * remove_rep(list_node * head)
//{
//	//////在下面完成代码
//	list_node* cur = head;
//	list_node* pre = cur;
//	unordered_set<int> home;
//	home.insert(cur->val);
//	cur = cur->next;
//	while (cur)
//	{
//		if (home.end() == home.find(cur->val))
//		{
//			home.insert(cur->val);
//			pre = cur;
//			cur = cur->next;
//		}
//		else
//		{
//			list_node* del = cur;
//			pre->next = del->next;
//			cur = del->next;
//			delete del;
//		}
//	}
//	return head;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	list_node * head = input_list();
//	list_node * new_head = remove_rep(head);
//	print_list(new_head);
//	return 0;
//}

//删除链表中指定的值
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//list_node * input_list()
//{
//	int val, n;
//	scanf("%d", &n);
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//		}
//	}
//	return phead;
//}
//
//
//list_node * remove_value(list_node * head, int num)
//{
//	//////在下面完成代码
//	list_node* cur = head;
//	list_node* pre = nullptr;
//	while (cur)
//	{
//		if (num == cur->val)
//		{
//			list_node* del = nullptr;
//			if (cur->val == head->val)
//			{
//				del = head;
//				head = head->next;
//				cur = head;
//			}
//			else
//			{
//				del = cur;
//				pre->next = del->next;
//				cur = del->next;
//			}
//			delete del;
//		}
//		else
//		{
//			pre = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}
//
//void print_list(list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	list_node * head = input_list();
//	int num;
//	scanf("%d", &num);
//	list_node * new_head = remove_value(head, num);
//	print_list(new_head);
//	return 0;
//}

//二叉搜素树转双向链表
//#include<map>
//#include<vector>
//struct double_list_node {
//	int val;
//	struct double_list_node * pre, *next;
//};
//
//struct BST {
//	int val;
//	struct BST * lch, *rch;
//};
//
//BST * input_BST()
//{
//	int n, fa, lch, rch;
//	scanf("%d", &n);
//	BST * root=nullptr, *new_node;
//	map<int, BST *> mp;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d %d %d", &fa, &lch, &rch);
//		if (mp.find(fa) == mp.end()) {
//			new_node = (BST *)malloc(sizeof(BST));
//			mp[fa] = new_node;
//			new_node->val = fa;
//			if (i == 1) root = new_node;
//		}
//		if (lch && mp.find(lch) == mp.end()) {
//			new_node = (BST *)malloc(sizeof(BST));
//			mp[lch] = new_node;
//			new_node->val = lch; new_node->lch = new_node->rch = NULL;
//		}
//		if (rch && mp.find(rch) == mp.end()) {
//			new_node = (BST *)malloc(sizeof(BST));
//			mp[rch] = new_node;
//			new_node->val = rch; new_node->lch = new_node->rch = NULL;
//		}
//		mp[fa]->lch = (lch ? mp[lch] : NULL);
//		mp[fa]->rch = (rch ? mp[rch] : NULL);
//	}
//	return root;
//}
//
//vector<int> Order(BST * root)
//{
//	static vector<int> ret;
//	if (root)
//	{
//		Order(root->lch);
//		ret.push_back(root->val);
//		Order(root->rch);
//	}
//	return ret;
//}
//double_list_node * convert(BST * root)
//{
//	//////在下面完成代码
//	double_list_node* newhead = new double_list_node();
//	double_list_node* cur = newhead;
//	vector<int> ret = Order(root);
//	for (size_t i = 0; i < ret.size(); i++)
//	{
//		double_list_node* node = new double_list_node();
//		node->val = ret[i];
//		cur->next = node;
//		node->pre = cur;
//		cur = node;
//	}
//	return newhead->next;
//}
//
//void print_double_list(double_list_node * head)
//{
//	while (head != NULL) {
//		printf("%d ", head->val);
//		head = head->next;
//	}
//	puts("");
//}
//
//int main()
//{
//	BST * root = input_BST();
//	double_list_node * new_double_head = convert(root);
//	print_double_list(new_double_head);
//	return 0;
//}

//向环形链表中插入新节点
//struct list_node {
//	int val;
//	struct list_node * next;
//};
//
//
//list_node * input_list(void)
//{
//	int n, val;
//	list_node * phead = new list_node();
//	list_node * cur_pnode = phead;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &val);
//		if (i == 1) {
//			cur_pnode->val = val;
//			cur_pnode->next = NULL;
//		}
//		else {
//			list_node * new_pnode = new list_node();
//			new_pnode->val = val;
//			new_pnode->next = NULL;
//			cur_pnode->next = new_pnode;
//			cur_pnode = new_pnode;
//			if (i == n) {
//				new_pnode->next = phead;
//			}
//		}
//	}
//	return phead;
//}
//
//
//list_node * insert_num(list_node * head, int num)
//{
//	//////在下面完成代码
//	list_node * cur = head;
//	list_node * pre = nullptr;
//	do {
//		if (cur->val < num)
//		{
//			pre = cur;
//			cur = cur->next;
//		}
//		else
//			break;
//	} while (cur != head);
//
//	list_node *node = new list_node();
//	node->val = num;
//	if (pre != nullptr)
//	{
//		node->next = pre->next;
//		pre->next = node;
//	}
//	else
//	{
//		node->next = head;
//		while (cur->next != head)
//			cur = cur->next;
//		cur->next = node;
//		head = node;
//	}
//	return head;
//}
//
//
//void print_list(list_node * head)
//{
//	list_node * h = head;
//	while (1) {
//		printf("%d ", head->val);
//		if (head->next == h) break;
//		head = head->next;
//	}
//	puts("");
//}
//
//
//int main()
//{
//	list_node * head = input_list();
//	int n;
//	scanf("%d", &n);
//	list_node * new_head = insert_num(head, n);
//	print_list(new_head);
//	return 0;
//}


//按照左右半区的方式重新组合单链表
struct list_node {
	int val;
	struct list_node * next;
};


list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node * new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}


list_node * relocate(list_node * head)
{
	//////在下面完成代码
	list_node * fast = head;
	list_node * slow = head;
	list_node * pre = nullptr;
	list_node * newhead = new list_node();
	list_node * cur = newhead;
	int count = 0;
	while (fast)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next;
		count++;
		if (fast)
		{
			fast = fast->next;
			count++;
		}
	}
	if (count % 2 != 0)
		slow = pre;
	int i = 1;
	while (i <= count)
	{
		if (i % 2 == 1)
		{
			if (i == count && count % 2 == 1)
				break;
			cur->next = head;
			cur = head;
			head = head->next;
		}
		else
		{
			cur->next = slow;
			cur = slow;
			slow = slow->next;
		}
		i++;
	}
	cur->next = slow;
	cur = slow;
	return newhead->next;
}


void print_list(list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}


int main()
{
	list_node * head = input_list();
	list_node * new_head = relocate(head);
	print_list(new_head);
	return 0;
}