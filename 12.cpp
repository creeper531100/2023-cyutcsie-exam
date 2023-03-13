#include <fstream>
#include<iostream>
using namespace std;

int main() {
    ifstream ifs("123.txt", ios::in);

    int max_len; //最大長度
    int ans = 0; //答案
    string str;  //文件內容字符串

    //從文件中讀取字符串和最大長度
    ifs >> str >> max_len;

    //從頭到尾遍歷整個字符串，每次從 i 開始取出最大長度的子串，每次遞增3
    for(int i = 0; i < str.length(); i+= max_len) {
        string spilit = str.substr(i, max_len); //使用 .substr() 函數截取子串 .substr(起始位置, 長度)
        ans += atoi(spilit.c_str());                //將子串轉換為整數，並將其加到答案中
    }

    //TODO: 不使用STL容器方法（可替換上面的代碼塊）
    /* for (int i = 0; i < str.length(); i += 3) {
     *     char tmp[4] = { '\0' }; // 暫存，用於轉整數
     *     //從頭到尾遍歷整個字符串，每次從 i 開始取出最大長度的子串，每次遞增3
     *     //以防數值超過字串長度造成溢位，需要加入i + j < str.length()判斷
     *     for (int j = 0; j < 3 ; j++) {
	 *		   if(i + j < str.length()){
	 *			   break;
	 *		   }
     *         tmp[j] = str[i + j];
     *     }
     *     ans += atoi(tmp);
     * }
     */

    cout << ans << endl;
}
