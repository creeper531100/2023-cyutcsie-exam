﻿#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ifstream iss("e.txt", ios::in);
    int len = 0, max = 0;
	//99是隨便定的一個數字，只要足夠大就可以了
    int arr[99];
    while (iss >> arr[len]) {
        printf("%d ", arr[len]);
        len++;
    }
    for (int i = 0; i < len; i++) {
        int sum = 0;
        for (int j = i; j < len; j++) {
            sum += arr[j];
            if (sum > max)
                max = sum;
        }
    }
    printf("\nAns=%d\n", max);
}

/*
 * 1[1] 2[3] -6[-3] 3[0]  -2[-2] 4[2]  -1[1]  3[4] 2[6] -4[2]    =  2, 6
 *      2[2] -6[-4] 3[-1] -2[-3] 4[1]  -1[0]  3[3] 2[5] -4[1]    =  1, 6
 *           -6[-6] 3[-3] -2[-5] 4[-1] -1[-2] 3[1] 2[3] -4[-1]   = -1, 6
 *                  3[3]  -2[1]  4[5]  -1[4]  3[7] 2[9] -4[5]    =  5, 9
 *                        -2[-2] 4[2]  -1[1]  3[4] 2[6] -4[2]    =  2, 9
 *                               4[4]  -1[3]  3[6] 2[8] -4[4]    =  4, 9
 *                                     -1[-1] 3[2] 2[4] -4[0]    =  0, 9
 *                                            3[3] 2[5] -4[1]    =  1, 9
 *                                                 2[2] -4[-2]   = -2, 9
 *                                                      -4[-4]   = -4, 9
 */