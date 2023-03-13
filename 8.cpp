#define _CRT_SECURE_NO_WARNINGS // 忽略警告

#include <iostream> // 輸出結果用

int main() {
    // 開啟文件，讀取初始向量
    FILE* file = fopen("b.txt", "r+");
    int x_marix[3] = { 0, 0, 0 };
    fscanf(file, "%d %d %d", &x_marix[0], &x_marix[1], &x_marix[2]);

    // 定義一個3x3的矩陣a和一個長度為3的向量b
    int a_marix[3][3] = {
        { 4, 1, 3 },
        { 2, 9, 5 },
        { 1, 2, 9 }
    };
    int b_marix[3] = { -16, 45, -18 };

    // 定義一個向量l，其中每個元素為向量x和矩陣a的乘積
    int l_marix[3] = { 0, 0, 0 };
    for (int i = 0; i < 3; i++) {
        int tmp = 0;
        for (int j = 0; j < 3; j++) {
            //矩陣相乘的運算方式是把第一個矩陣的每一列與第二個矩陣的每一行做內積運算
            //             [ 4 1 3 ]
            //  [2 -5 3] * [ 2 9 5 ] = (2 * 4 + -5 * 2 + 3 * 1) + (2 * 1 + -5 * 9 + 3 * 2) ...
            //             [ 1 2 9 ]
            tmp += x_marix[j] * a_marix[j][i];
        }
        //填入新矩陣的對應位置
        l_marix[i] = tmp;
    }

    // 計算下一個矩陣
    int ans1 = 0;
    for (int i = 0; i < 3; i++) {
        ans1 += l_marix[i] * x_marix[i];
    }

    // 計算下一個矩陣
    int ans2 = 0;
    for (int i = 0; i < 3; i++) {
        ans2 += b_marix[i] * x_marix[i];
    }

    // 輸出ans1+ans2+36的值
    printf("%d\n", ans1 + ans2 + 36);

    // 關閉文件
    fclose(file);
}



