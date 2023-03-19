#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream ss("123.txt", ios::in);

    // 用陣列 arr 儲存所有牌面的值，初始化為 -1。
    int arr[99] = { -1 };
    int len;

    // 從檔案讀取牌的數量，將 len 設為牌數的兩倍，因為每張牌都有兩個面。
    ss >> len;
    len *= 2;

    for (int i = 0; i < len; i++) {
        ss >> arr[i];
        cout << arr[i] << " ";
    }

    cout << "\n";

    // pos用來記錄每個牌面是否已經被翻開過了。
    bool pos[99] = { false };
    // ans用來統計翻開和翻回去的總次數。
    int ans = 0;

    // 從 i 等於 0 開始，每次增加 1，直到 i 等於 len 為止。這個迴圈用來遍歷所有的牌面。
    for (int i = 0; i < len; i++) {
        // 這個迴圈用來與外層的 for 迴圈對所有的牌面進行配對。為了避免與本身配對，起始值必須+1
        for (int j = i + 1; j < len; j++) {
            if (pos[j] == true || pos[i] == true) {
                /*
                 * 如果其中一張牌已經被翻開，就跳過這一對牌。
                 * 這裡的 pos 陣列用來標記哪些牌已經被翻開過了。
                 * 如果 pos[j] 或 pos[i] 為 true，表示其中一張牌已經被翻開過，跳過這一對牌。
                 */
                continue;
            }
            if (arr[i] == arr[j]) {
                /*
                 * 如果這一對牌面相同，就翻開這一對牌。
                 * pos[j] 就設為 true 表示這張牌已經被翻開過了，讓下一輪跳過這張牌。
                 * 同時，ans 會增加 2 (一次翻開兩張牌，只會翻開不會蓋回去)
                 * break 會跳出內層的迴圈，表示一組牌面已經配對成功，可以繼續尋找下一組配對。
                 */
                pos[j] = true;
                ans += 2;
                break;
            }
            // 如果不是一對，就把兩張牌蓋回去
            // ans 加 4 (一次兩張牌，失敗蓋回去)
            ans += 4;
        }
    }

    cout << "Ans=" << ans << endl;
}

/*
 * 翻牌配對的過程如下:
 * 先翻開前兩張 4 8 ->2 次，配對失敗翻回去 -> 2 次
 * 接著翻開第 2 個 4，也記住已經翻過的第 1 個 4，配對成功 -> 2 次
 * 接著依序翻開 10 8 ->2 次，配對失敗翻回去 -> 2 次
 * 接著翻開第 2 個 8 與第一個 8，配對成功-> 2 次
 * 接著翻開第 2 個 10，也記住已經翻過的第 1 個 10，配對成功 -> 2 次
 * 合計翻開與翻回去共 14 次
 */
