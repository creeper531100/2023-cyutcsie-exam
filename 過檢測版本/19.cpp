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

/*
 * 部分序列字串指原字串中刪掉一個以上字元且不改變原順序的部份字串。請撰寫程式從
 * 資料檔 d.txt 讀入兩個字串(每一字串皆不超過 50 字元)，判斷第一個字串是否為第二個
 * 字串的部份序列字串，若是則輸出 Yes 以及被刪除之部分序列字串，否則輸出 No。
 * 範例輸入一：
 * bcfg gcbgcefgjvk
 * 範例輸出一：
 * bcfg gcbgcefgjvk
 * Ans=Yes gcgejvk
 * 範例輸入二：
 * bcfg gcagcefgjvk
 * 範例輸出二：
 * bcfg gcagcefgjvk
 * Ans=No
 */