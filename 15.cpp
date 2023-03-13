#include <iostream>

using namespace std;

//蘇佑緯學長提供

/*
 * 解題思路
 * 從檔案中讀入兩個整數，分別代表上限和目標值。
 * 使用迴圈從 0 到上限進行數字的計算。
 * 將每個數字轉換成字串，並逐位計算數字總和。
 * 如果數字總和等於目標值，就把計數器加 1。
 * 最後輸出計數器的值，即為結果。
 */

/* chatgpt:
 * 整段程式碼的流程非常清晰，每個步驟都有明確的註解，讓讀者很容易理解每個步驟所做的事情。
 * 程式也沒有使用複雜的算法，只是使用基本的數學運算，因此易於理解和修改。
 */

int main() {
    int range; // range: 上限數字
    int target; //target: 目標數字和
    int count = 0; //count: 符合條件的數字個數

    FILE* file = fopen("123.txt", "r"); // 開啟檔案
    fscanf(file, "%d %d", &range, &target); // 從檔案讀入上限數字與目標數字和
    printf("%d %d \nAns=", range, target);

    // 搜尋範圍內的每個數字
    for (int i = 0; i <= range; i++) {
        // 目前數字的數字和
        int digit_sum = 0;

        // 宣告字串變數用來處理每個數字
        char str_num[10];

        // 將目前數字轉成字串
        sprintf(str_num, "%d", i);

        // 計算目前數字的數字和
        for (int j = 0; j < strlen(str_num); j++) {
            digit_sum += str_num[j] - '0';
        }
     
        // 如果數字和符合條件，則計數器加一
        if (digit_sum == target) {
            count++;
        }
    }

    printf("%d\n", count);
}