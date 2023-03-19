#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream ss("123.txt", ios::in);

    int arr[99] = { -1 };
    int len;
    ss >> len;
    len *= 2;

    for(int i = 0; i < len; i++) {
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
        for(int j = i + 1; j < len; j++) {
            if (pos[j] == true || pos[i] == true) {
                /*
                 * if用來檢查是否已經有其中一個牌面被翻開過了。
                 * 如果已經翻開了，那麼這個牌面就不能再次翻開了，所以需要繼續執行下一輪
                 */
                continue;
            }
            if(arr[i] == arr[j]) {
                /*
                 * 這邊判斷用來檢查，比對是否已經有其中一個牌面被翻開過了。
                 * 如果已經翻開了，那麼這個牌面就不能再次翻開了。
                 * pos[j] 就設為 true 讓下一輪跳過這張牌，避免重複翻開。
                 * 同時，ans 會增加 2 (一次兩張牌，只會翻開不會蓋回去)
                 * break 會跳出內層的迴圈，因為已經找到了一組配對成功的牌，可以繼續尋找下一組配對。
                 */ 
                pos[j] = true;
                ans += 2;
                break;
            }
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
