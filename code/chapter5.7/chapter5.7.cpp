#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//例5.4 函数
int sumTo(int i) {
	if (i == 0) return 0;
	return sumTo(i - 1) + i;
}

//例5.5 汉诺塔函数
void hanoi(int n, char src, char mid, char tar) {
	if (n == 1)
		cout << src << "-->" << tar << '\t';
	else {
		hanoi(n - 1, src, tar, mid);//将n-1个盘子移到中间柱上
		cout << src << "-->" << tar << '\t';//将最后一个盘子移到目标柱上
		hanoi(n - 1, mid, src, tar);//将n-1个盘子从中间柱移到目标柱上
	}
}

//例5.6 函数
bool isSafe(int i, const vector<int> &que) {
	for (int k = 0; k < i; ++k) {
		if (que[k] == que[i] || (abs(que[i] - que[k]) == abs(i - k)))
			return false;
	}
	return true;
}
void queen(int i, vector<int> &que, int&cnt) {
	if (i == 8) {
		cout << "方案" << ++cnt << ":";
		for (int k = 0; k < que.size(); ++k)
			cout << que[k];
		cout << endl;
		return;
	}

	for (int k = 0; k < que.size(); ++k) {
		que[i] = k;
		if (isSafe(i, que)) { //如果安全，安排下一行皇后
			queen(i + 1, que, cnt);
		}
	}
}
int main()
{
	//例5.4 
	std::cout << sumTo(3);
	cout << "5.4yunxing" << endl;

	//例5.5 汉诺塔问题
	{
		int n;
		cin >> n;
		hanoi(n, 'A', 'B', 'C');
	}

	//例5.6 递归方法求解八皇后问题
	{
		constexpr int sz = 8;
		vector<int> que(sz);
		int cnt = 0;
		queen(0, que, cnt);
	}

}

