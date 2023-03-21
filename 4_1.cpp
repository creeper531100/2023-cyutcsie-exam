#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
    //999是隨便定的一個數字，只要足夠大就可以了
    char res[999] = { '\0' };
    FILE* file = fopen("d.txt", "r+");
    fread(res, 1, sizeof(res), file); //fgets 讀檔案所有內容

    int ans = 0;
    int index = 0;
    string tmp[99] = { "0" };

    for (int i = 0; i < strlen(res); i++) {
        if (res[i] >= '0' && res[i] <= '9') {
            tmp[index] += res[i];
            continue;
        }
        index++;
    }

    for (int i = 0; i < 99; i++) {
        ans += atoi(tmp[i].c_str());
    }

    printf("%s\n", res);
    printf("Ans=%d\n", ans);
}