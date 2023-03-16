#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
int main() {
	string pattern;
	string text;

	fstream ss("123.txt", ios::in);
	// 讀取輸入的兩個字串，並存入 pattern 和 text 變數中
	ss >> pattern >> text;
	cout << pattern << " " << text << endl;

	int pattern_idx = 0;
	string ans;
	/*
	 * 建立迴圈，從 gcbgcefgjvk 字串的第一個字元開始，並依序比對是否為 bcfg 的字元
	 * 若相同則增加 bcfg 的索引，否則將該字元加入到 ans 被刪除之部分序列字串中。
	 */
	for (int i = 0; i < text.length(); i++) {
		// 若目前的字元相同
		if (pattern[pattern_idx] == text[i]) {
			// 增加 pattern 索引
			pattern_idx++;
		}
		else {
			// 其餘加入 ans 內
			ans += text[i];
		}
	}

	// 若索引與 pattern 長度相同，代表目標字串與部分序列字串中
	if (pattern.length() == pattern_idx) {
		cout << "Ans=Yes " << ans << endl;
	}
	else {
		cout << "Ans=No" << endl;
	}
}
