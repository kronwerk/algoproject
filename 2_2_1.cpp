#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <algorithm>
//#include <stdio.h>
using namespace std;

/*char * mul(char * a, char * b) {
    char * res = new char[2];
    char tmp = a[0] * b[0];
    res[0] = tmp / 10;
    res[1] = tmp % 10;
    printf("%d|%d\n", res[0], res[1]);
    return res;
}

char * sm(char * a, char * b, char sign) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int n = max(lenA, lenB) + 1;
    char * res = new char[n];
    char c[n];
    char tmp = 0;
    c[n-1] = 0;
    for(int i = n-1;i >= 0;i--) {
        tmp = c[i];
        if (i < lenA)
           tmp += sign * a[i];
        if (i < lenB)
           tmp += sign * b[i];
        res[i] = tmp % 10;
        if (i > 0)
            c[i-1] = tmp / 10;
    };
    return res;
}

char * half(char * a, int mx, int sx) {
    char * aP = new char[mx];
    int i = 0;
    for(i=sx;i<sx+mx;i++)
        aP[i] = a[i];
    if (i == 0)
        aP[0] = 0;
    return aP;
}

char * dc(char * p, int n) {
    int lenP = strlen(p);
    char * res = new char[lenP + n];
    int i = 0;
    for(i=lenP+n-1;i >= lenP;i--)
        res[i] = 0;
    for(;i >= 0;i--)
        res[i] = p[i];
    return res;
}

char * kara(char * a, char * b) {
    char plus = 1;
    char minus = -1;
    int n = max(strlen(a), strlen(b));
    int i = 0;
    int mx = n / 2;
    if (n == 1)
        return mul(a, b);

    char * aL = half(a, mx, 0);
    char * aR = half(a, n - mx, mx);
    char * bL = half(b, mx, 0);
    char * bR = half(b, n - mx, mx);
    char * p1 = kara(aL, bL);
    char * p2 = kara(aR, bR);
    char * p3 = kara(sm(aL, aR, plus), sm(bL, bR, plus));
    delete [] aL;
    delete [] bL;
    delete [] aR;
    delete [] bR;

    char * r1 = dc(p1, 2 * mx);
    char * r2 = dc(sm(sm(p3, p1, minus), p2, minus), mx);
    char * res = sm(sm(r1, r2, plus), p3, plus);
    delete [] p1;
    delete [] p2;
    delete [] p3;
    delete [] r1;
    delete [] r2;

    return res;
};*/

int in(char a) {
	return a - '0';
}

char out(int x) {
	return (char)(x + '0');
}

int main() {
    int max = 50000;
	int base = 10;
    char * a = new char[max];
    char * b = new char[max];
    cin >> a;
    cin.clear();
    cin >> b;
	int lastC = strlen(a) + strlen(b);
    char * c = new char[lastC + 1];
	for(int i = 0;i <= lastC;i++)
		c[i] = '0';
	int k = 0;
	int x = 0;
	int j = 0;
	int sum = 0;
	for(int i=strlen(a)-1;i >= 0;i--) {
		k = 0;
		for(j=strlen(b)-1;j >= 0;j--) {
			x = in(a[i]) * in(b[j]) + k;
			sum = in(c[i+j+2]) + x % base;
			c[i+j+2] = out(sum % base);
			k = x / base + sum / base;
		};
		c[i+j+2] = out(k);
	};

	j = 1;
	while(c[j] == '0') j++;
	if (j > lastC)
		cout << "0";
	else
		while(j <= lastC)
			cout << c[j++];
	return 0;
}