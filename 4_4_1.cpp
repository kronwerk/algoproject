#include <iostream>
using namespace std;

class Sorter {
public:
	int * a;
	int * b;
	int n;

	Sorter(int * a, int * b, int n) {
		this->a = a;
		this->b = b;
		this->n = n;
	};

	void swap(int i, int j) {
		if (i == j)
			return;
		int tmpA = a[i];
		int tmpB = b[i];
		a[i] = a[j];
		b[i] = b[j];
		a[j] = tmpA;
		b[j] = tmpB;
	};
	
	int partition(int x, int left, int right) {
		int j = left;
		for(int i = left + 1;i <= right;i++)
			if (a[i] <= x) {
				j++;
				swap(i, j);
			};
		swap(left, j);
		return j;
	};

	void quickSort(int left, int right) {
		int mR = 0;
		while (left < right) {
			mR = partition(a[left], left, right);
			quickSort(left, mR-1);
			left = mR + 1;
		};
	};

	int binSearchLeft(int p) {
		int left = 1;
		int right = n;
		int m = 0;
		bool condition = false;
		while (left <= right) {
			m = (left + right) / 2;
			if (p >= a[m])
				left = m + 1;
			else
				right = m - 1;
		};
		if (p < a[m])
			m--;
		int count = 0;
		for(int i = 1;i <= m;i++)
			if (p <= b[i])
				count++;
		return count;
	};

	void getCount(int * p, int m, int * result) {
		quickSort(1, n);
		int left = 0;
		int right = 0;
		for(int i = 1;i <= m;i++)
			result[i] = binSearchLeft(p[i]);
	};

};

int main() {
	int n = 0;
	int m = 0;
	cin >> n;
	cin >> m;
	int * a = new int[n+1];
	int * b = new int[n+1];
	int * p = new int[m+1];
	//int a[7] = {0, 2, 3, 4, 6, 5, 99998};
	//int b[7] = {0, 10, 9, 8, 8, 7, 100000};
	//int p[7] = {0, 1, 6, 11, 7, 8, 99999};
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		cin >> b[i];
	};
	Sorter s = Sorter(a, b, n);
	for(int i = 1;i <= m;i++)
		cin >> p[i];
	int * result = new int[m+1];
	s.getCount(p, m, result);
	for(int i = 1;i <= m;i++)
		cout << result[i] << " ";
	return 0;
}