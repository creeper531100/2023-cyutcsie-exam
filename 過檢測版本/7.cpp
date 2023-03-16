#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
int main() {
    fstream ifs("b.txt", ios::in);

    float dec;
    int integer;

    string res;
    getline(ifs, res);
    cout << res << endl;

    stringstream ss(res);
    ss >> integer >> dec;
    printf("Ans=");

    string tmp;
    while (integer != 0) {
        /*
         * 使用 while 迴圈將整數部分轉換為二進位數字，把每個二進位位數存入字串變數 tmp 中。
         * 轉換過程是不斷地除以 2，直到整數部分變為 0 為止。
         * 這邊為了方便反轉輸出結果，我們使用C++的字串加總
         */
        tmp += integer % 2 + '0';
        integer /= 2;
    }

    //將二進制數字反轉輸出
    for (int i = tmp.length(); i >= 0; i--) {
        printf("%c", tmp[i]);
    }

    printf("+");
    //取小數點後三位
    for (int i = 0; i < 3; i++) {
        /*
         * 先把小數部分乘上 2，然後把整數部分取出來。
         * 如果整數部分為 1，就代表需要進位，把小數部分扣掉 1。
         * 這樣就可以不斷地乘以 2，取整數，直到小數部分轉換完畢。
         */
        dec *= 2.0; //十進制轉二進制小數, 不斷乘二
        printf("%d", (int)dec);

        if ((int)dec == 1) {
            //若進位扣1
            dec--;
        }
    }
    printf("\n");
}

/*
 * 請撰寫一程式，此程式從 b.txt 中讀取一個正的十進位數字(含小數)後將此十進位數字轉
 * 換成二進位數字，轉換後的數字請取至小數點第三位(小數點第三位以後的數字直接捨
 * 去)。輸出格式為：轉換後的整數+轉換後的小數部分
 * 範例輸入：
 * 21.33
 * 說明：
 * 21.33 轉換成二進位數字為 10101.010101…
 * 取小數點後三位後的數字為 10101.010
 * 因此輸出結果為 10101+010
 * 範例輸出：
 * 21.33
 * Ans=10101+010
 */