#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>

/*
 * 注意!!!，以下是一段像一坨屎山，程式碼不夠簡潔，可讀性差
 * 這只是示範，其目的在於提供想法，請慎用當參考作為範例使用。
 * 目前只能過自學平台檢測與題目提供解答，所以還存在許多問題和缺陷
 * 還有存在大量的重複程式碼，有善心人士可以求求幫我進行優化或重構嗎😭。
 */

using namespace std;

int ctoi(char ch) {
    return ch - '0';
}

int main() {
    fstream file("123.txt", ios::in); // 開啟檔案，設定為讀取模式
    string line;
    int case_count;

    getline(file, line);
    // 將字串轉換成 stringstream 方便從中取出數字
    stringstream ss(line);

    ss >> case_count;
    cout << case_count << endl;
    
    string ans_str = "Ans="; // 儲存結果的字串
    for(int i = 0; i < case_count; i++) {
        getline(file, line);
        cout << line << endl;

        // 儲存保齡球得分的字元陣列，初始值為 -1 方便後續的處理
        char scores[99] = { -1 };
        int size = 0;

        // 將字串轉換成 stringstream 方便從中取出數字
        stringstream iss(line);

        // 逐一取出字元並存入 scores 陣列中
        while (iss >> scores[size]) {
            if(scores[size] == 'X') {
                // 把X改為 '9' + 1，方便後續的計算
                // ('9' + 1) - '0' = 10
                scores[size] = '9' + 1;
            }
            // 已讀入的保齡球得分數量加 1
            size++;
        }

        int score = 0;
        int chk_idx = 1; // 用來檢查局數的變數
        for(int j = 0; j < size; j++) {
            // 計算兩次計分中有沒有超過10
            if (scores[chk_idx] >= '0' && scores[chk_idx] <= '9') {
                if (!(scores[j - 1] >= '0' && scores[chk_idx - 1] <= '9')) {
                    // 如果是兩次計分之間有X或/，就要跳過計算下一個數字
                    chk_idx++;
                }

                if (ctoi(scores[chk_idx]) + ctoi(scores[chk_idx - 1]) > 10) {
                    // 檢查兩次計分中有沒有超過 10 分
                    // 如果兩次計分總和超過10，就代表不合法
                    score = -1;
                    break;
                }
            }
            chk_idx += 2;

            // 局數不夠計分失敗
            if(scores[j] == '/' && (j - 1 <= 0 || j + 1 >= size)) {
                score = -1;
                break;
            }

            // 局數不夠計分失敗
            if (scores[j] == '9' + 1 && j + 2 >= size) {
                score = -1;
                break;
            }

            // 保齡球不可能連續Spare兩次
            if (scores[j] == '/' && (scores[j - 1] == '/' || scores[j + 1] == '/')) {
                score = -1;
                break;
            }

            if (scores[j] == '/') {
                // 如果有/，代表這局計分為 Spare
                // 計算上一次投球擊倒瓶數和下一次的第一次投球擊倒瓶數
                int last_count = 10 - ctoi(scores[j - 1]);
                int next_count = ctoi(scores[j + 1]);
                score += last_count + next_count;
                continue;
            }

            // 全倒情況
            if (scores[j] == '9' + 1) {
                // 如果第一次投球全倒，代表這局計分為 Strike
                // 計算接下來兩次投球擊倒瓶數
                int add = ctoi(scores[j]) + ctoi(scores[j + 1]) + ctoi(scores[j + 2]);
                score += add;
                continue;
            }

            // 如果不是 Spare 或 Strike，就只要加上這次投球擊倒瓶數
            score += ctoi(scores[j]);
        }

        // 檢查是否有計分失敗 -1 即為 Unknown
        if(score > 0) {
            char tmp[99];
            //sprintf 用於數字轉字串
            sprintf(tmp, "%d ", score);
            ans_str += tmp;
        }
        else {
            ans_str += "Unknown ";
        }
    }
    cout << ans_str << endl;
}