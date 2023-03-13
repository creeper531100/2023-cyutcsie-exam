#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream ifs("123.txt", ios::in);
    int chicken_foot = 2;
    int rabbit_foot = 4;

    int total_animals = 15;
    int total_foots = 42;

    ifs >> chicken_foot >> rabbit_foot >> total_animals >> total_foots;
    printf("%d %d %d %d\n", chicken_foot, rabbit_foot, total_animals, total_foots);

    /*
     *  x +  y = 頭的總數，其中 x 表示雞的數量，y 表示兔子的數量。
     * 2x + 4y = 腳的總數，其中 2x 表示雞的腳的數量，4y 表示兔子的腳的數量。
     *
     *     (1)   (2)  (3)
     *       x +  y = 15 (擴分x4)
     * -)   2x + 4y = 42
     *     (4)  (5)   (6)
     * -----------------
     *      4x + 4y = 60
     *      2x + 4y = 42
     * -)
     * -----------------
     *      2x + 0  = 18
     *            x = 9
     */     

    // 計算兔子的腳的總數
    // 先計算(3)，我們要先擴分 y (兔子的腳 * 總數)
    //   (2) * (3)
    // = 4 * 15
    // = 60
    int total_rabbit_foots = rabbit_foot * total_animals;

    // 計算兔子的腳的數量
    // 再計算(1)，我們要先擴分 x (兔子的腳 * 雞)
    //   (2) * (1)
    // = 4 * 1
    // = 4
    int rabbit_foots = rabbit_foot * 1; //你也可以省略 * 1

    // 計算兔子的數量
    // 計算 (6) - (3) / (1) - (4)
    // 60 - 42    18
    // ------- = ----- = 9
    // 4  -  2     2
    int rabbit_count = (total_rabbit_foots  - total_foots) / (rabbit_foots  - chicken_foot);

    cout << "Ans=";

    // 判斷是否有解，當不整除即無解
    if((total_rabbit_foots  - total_foots) % (rabbit_foots  - chicken_foot) != 0) {
        cout << "No Solution" << endl;
        return 0;
    }

    // 判斷是否有解，數量不正確即無解
    if (rabbit_count < 0 || total_animals - rabbit_count < 0) {
        cout << "No Solution" << endl;
        return 0;
    }

    printf("%d %d\n", rabbit_count, total_animals - rabbit_count);
}