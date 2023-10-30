#include<iostream>
#include<string>
#include<vector>
using namespace std;
int find(string str, string pattern,int pos) {
	int num = 0;
	for (int i = pos; i < str.length(); i++) {
		num++;
		if (str[i] == pattern[0]) {
			int k = 1, j = i + 1;
			while (k < pattern.length()) {
				num++;
				if (str[j] == pattern[k]) {
					j++;
					k++;
				}
				else
					break;
			}
			if (k == pattern.length()) {
				cout << "暴力算法共比较" << num << "次" << endl;
				return i;
			}
		}
	}
	cout << "暴力算法共比较" << num << "次" << endl;
	return -1;
}
int kmp(string str, string pattern, int pos) {
	vector<int> next{ -1 };
	int j = 1, k = -1, num = 0;
	//求next数组
	while (j < pattern.length()) {
		if (k==-1||pattern[j - 1] == pattern[k]) {
			/*next.push_back(++k);
			j++;*/
			k++;
			j++;
			next.push_back(pattern[j - 1] != pattern[k] ? k : next[k]);
		}
		else {
			k = next[k];
		}
	}
	j = 0;
	int i = pos;
	while (i < str.length()) {
		num++;
		if (str[i] == pattern[j]) {
			i++;
			j++;
			if (j == pattern.length()) {
				cout << "KMP算法共比较" << num << "次" << endl;
				return i - j;
			}
		}
		else {
			j = next[j];
			if (j == -1) {
				i++;
				j++;
			}
		}
	}
	cout << "KMP算法共比较" << num << "次" << endl;
	return -1;
}
int main() {
	string a, b;
	cin >> a >> b;
	cout << find(a, b, 0) << endl;
	cout << kmp(a, b, 0) << endl;
}
//abcadabcdc	abcd
//abcaabcabbcabdabcaabcabdcabcaabcdcabca	abcabdc
//abcaabbabbcabcaabcaabbcabcaabdaabcaabbcababcaabbcabcaabdababcaabbcabcaabdab	abcaabbcabcaabdab 

//abjdsjdjabjhkkdsjjabjdkkldkabjdkabjd	abjdhk
//bccabcacabccabccdaabcbcdbcbcddcbcdbcc	abcdc