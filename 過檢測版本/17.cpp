#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> // std::sort

/*
 * 此題與自學程檢題目不符
 *
 * 需要注意的是，程式碼中的 std::sort 函式需要使用 algorithm 標頭檔案。
 * 因此編譯失敗需要在檔案開頭加上 "#include<algorithm>" 才能順利編譯。
 */

using namespace std;

/* 若你不想使用函數庫提供的演算法，你可以使用氣泡排序法。並取消代碼塊註解
 * void bubble_sort(int arr[], int n) {
 *    for (int i = 0; i < n - 1; i++) {
 *        for (int j = 0; j < n - i - 1; j++) {
 *            if (arr[j] > arr[j + 1]) {
 *                int temp = arr[j];
 *                arr[j] = arr[j + 1];
 *                arr[j + 1] = temp;
 *            }
 *        }
 *    }
 * }
 */

int main() {
    int data[99] = { 0 }; // 儲存輸入的正整數序列
    int len = 0; // 正整數序列的長度

    string input_str;

    //讀取第一行
    getline(cin, input_str);
    stringstream ss(input_str);
    cout << input_str << endl;

    // 讀入正整數序列
    while (ss >> data[len]) {
        len++; // 更新正整數序列的長度
    }

    //讀取第二行長度
    getline(cin, input_str);
    int K = atoi(input_str.c_str()); // 視窗大小

    printf("%d\nAns=", K);

    /*
     * 以視窗大小為單位進行中值濾波
     * len - (K - 1) 解釋:
     * 假設你有一個長度為 len 的數列，而你想對這個數列進行 K 個數為一個窗口的中值濾波。
     * 那麼，你需要對這個數列中的前 N-K+1 個數進行中值濾波，因為在這之後的數量已經無法構成一個完整的窗口，無法計算中值。
     *
     * ex 1 2 3 4
     * 第一次 1 2 3
     * 第二次 2 3 4
     * 第三次 3 4 (無法構成一個完整的窗口)
     *
     * 因此，在程式碼中，循環的終止條件是 i < len - (K-1)，也就是對前 len - (K-1) 個數進行中值濾波。
     * 這樣做是為了避免最後 K-1 個數無法構成一個完整的窗口，導致計算中值時出錯。
     */
    for (int i = 0; i < len - (K - 1); i++) {
        int window[10] = { 0 }; // 儲存目前的視窗

        for (int j = 0; j < K; j++) {
            if (i + j >= len) {
                // 超出正整數序列的範圍，不處理
                break;
            }
            window[j] = data[i + j]; // 把正整數序列中的數字加入視窗
        }

        sort(window, window + K); // 對視窗內的數字進行排序
        // 若你不想使用函數庫提供的演算法，請替換上面代碼塊
        // bubble_sort(window, K);
        printf("%d", window[K / 2]); // 輸出排序後中間位置的數字

        // 注意這邊不能多印出一個空格，所以需要判斷
        if (i < len - (K - 1) - 1) {
            printf(" ");
        }
    }
}

/*
 * 中值濾波演算法常用於影像處理，底下使用一串資料來說明演算法的運作：
 * 假設輸入一串正整數如下：
 * 5 16 9 20 3 14 6 8 9 18 32 2
 * 濾波器需要設定一個視窗大小，K(奇數: 3, 5, …)，假設 K=3，將該串數字從左到右，
 * 每 3 個數字排序後，輸出排在中間的數值，針對上面的例子，輸出結果如下：
 * 5  字串一開始，個數不足 3 個不處理濾波動作
 * 5 16  字串一開始，個數不足 3 個不處理濾波動作
 * 5 16 9  排序後 5 9 16，所以輸出 9
 * 16 9 20 排序後 9 16 20，所以輸出 16
 * 9 20 3  排序後 3 9 20，所以輸出 9
 * …
 * 上面正整數的輸出結果為：
 * 9 16 9 14 6 8 8 9 18 18
 * 所以，數字中幾個特別大或小的數字就被過濾掉了，如：3 20 32 2
 * 請從資料檔 e.txt 中第一行讀入一串正整數，個數 N(最多 100 個)，以及第二行讀入
 * 一個 K 值(奇數 K>=3, K<=N)，接著輸出濾波結果。
 * 範例輸入：
 * 5 16 9 20 3 14 6 8 9 18 32 2
 * 3
 * 範例輸出：
 * 5 16 9 20 3 14 6 8 9 18 32 2
 * 3
 * Ans=9 16 9 14 6 8 8 9 18 18
 */