#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
	//99是隨便定的一個數字，只要足夠大就可以了
    char res[99] = { '\0' };
    FILE* file = fopen("d.txt", "r+");
    fread(res, 1, sizeof(res), file); //fgets 讀檔案所有內容

    string dst = "0";
    int ans = 0;

    for (int i = 0; i < strlen(res); i++) {
        if (res[i] >= '0' && res[i] <= '9') {
            //若在0~9範圍內將數字加入字串中
            dst += res[i];
            continue;
        }

        ans += atoi(dst.c_str()); //atoi將字串轉為數字
        dst = "0"; //清除 dst
    }
    printf("%s\n", res);
    printf("Ans=%d", ans);
}