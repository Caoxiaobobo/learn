#include<iostream>
#include<string>
#include<vector>

/*
--------------------------
KMP
-----------------------------
*/
void cal_next(string str, int* next)
{
	int len = str.size();
	int k = -1;
	next[0] = -1;
	for (int i = 1; i < len; i++)
	{
		while (k>-1 && str[k + 1] != str[i])
		    k = next[k];
		if (str[k + 1] == str[i])
			++k;
		next[i] = k;
	}
}
int KMP(string str, string tmp)
{
	int len1 = str.size();
	int len2 = tmp.size();
	int *next = new int[len2];
	cal_next(tmp, next);
	int k = -1;
	for (int i = 0; i < len1; i++)
	{
		while (k>-1 && tmp[k + 1] != str[i])
		{
			k = next[k];
		}
		if (tmp[k+1] == str[i])
			k++;
		if (k == len2-1)
			return i - len2 + 1;
	}
	delete[] next;
	return -1;
}
int main()
{
	string str = "bacbababadababacambabacaddababacasdsd";
	string tmp = "ababaca";
	int start = 0;
	start = KMP(str, tmp);
	cout << start<<endl;
	return 0;

}