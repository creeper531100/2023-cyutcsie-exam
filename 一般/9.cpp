#include <iostream>
#include <algorithm>
#include <fstream>
/*
 * 需要注意的是，程式碼中的 count 函式需要使用 algorithm 標頭檔案。
 * 因此編譯失敗需要在檔案開頭加上 "#include<algorithm>" 才能順利編譯。
 */

using namespace std;

int main() {
    ifstream ifs("123.txt");

    // 分別用來存儲讀入的字串和計算結果的字串
    string res;
    string ans;

    // 從檔案中讀入字串
    ifs >> res;
    ans = res;

    cout << res << endl;

    // 逐個字符檢查，如果是大炸彈，則將其爆炸範圍內的 0 替換為 '-'
    // 如果是小炸彈，也做同樣的替換
    for (int i = 0; i < res.length(); i++) {
        if (res[i] == 'X') {
            ans[i - 2] = '-';
            ans[i + 2] = '-';
        }

        if (res[i] == 'x' || res[i] == 'X') {
            ans[i - 1] = '-';
            ans[i] = '-';
            ans[i + 1] = '-';
        }
    }

    // 計算剩餘的 0 的個數並輸出
    printf("Ans=%d\n", count(ans.begin(), ans.end(), '0'));
}

/*
 * 恐怖份子在一條巷子中放入了好幾顆炸彈，炸彈有分小炸彈與大炸彈，請計算這條巷子
 * 在所有炸彈引爆後，還有那些地方是安全的。這裡假設巷子以一連串的 0 來表示，小 x
 * 表示小炸彈，爆炸範圍是 1(會炸到左右各一個 0)，大 X 是大炸彈，爆炸範圍是 2(會炸
 * 到左右各 2 個 0)，請從 d.txt 中讀入一串由 0, x, X 組成的字串(最長 80 個字元)，
 * 接著輸出炸彈爆炸後還剩下幾個 0。
 * 範例輸入一：
 * 00x00000X0xX0000x
 * 上面的炸彈爆炸後的結果為:
 * 0---00--------0--
 * 剩下 4 個 0
 * 範例輸出一：
 * 00x00000X0xX0000x
 * Ans=4
 */
