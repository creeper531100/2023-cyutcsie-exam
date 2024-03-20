#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

// 遞迴函數來找出從當前位置 [x, y] 出發的最長路徑
// [dx, dy] 代表移動的方向，例如 [1, 0] 代表向下移動，[0, 1] 代表向右移動
int find_longest_path(vector<string> maze, int x, int y, int dx, int dy) {
    int rows = maze.size();
    int cols = maze[0].length();

    // 首先檢查當前位置 [x, y] 是否在迷宮範圍內
    // 然後檢查該位置是否為路（用 1 表示路）
    if ((x >= 0 && x < rows && y >= 0 && y < cols) && maze[x][y] == '1') {
        // 如果當前位置是有效的且為路，則進行遞迴搜索
        // 此處加 1 的原因是計數從當前位置開始的這一步
        // 遞迴呼叫將探索下一個位置 [x + dx, y + dy]
        return 1 + find_longest_path(maze, x + dx, y + dy, dx, dy);
    }
    // 如果當前位置不在迷宮範圍內或者不是路（即 maze[x][y] 不是 1），則結束遞迴
    // 並返回 0，表示從這個方向上沒有可走的路徑
    return 0;
}

int main() {
    int max_length = 0;
    int rows;
    int cols;

    // vector C++容器，功能類似C的malloc動態陣列
    // 使用上更方便，功能更多
    // 使用方法如下
    // vector<型態> 宣告名稱;
    vector<string> maze;

    ifstream iss("123.txt");
    iss >> rows >> cols;
    printf("%d %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        string tmp;
        iss >> tmp;
        maze.push_back(tmp);
        cout << tmp << endl;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // 分別查找從當前位置出發的所有可能方向
            if (maze[i][j] == '1') {
                max_length = max(max_length, find_longest_path(maze, i, j, -1, 0)); // 向上
                max_length = max(max_length, find_longest_path(maze, i, j, 1, 0));  // 向下
                max_length = max(max_length, find_longest_path(maze, i, j, 0, -1)); // 向左
                max_length = max(max_length, find_longest_path(maze, i, j, 0, 1));  // 向右

                max_length = max(max_length, find_longest_path(maze, i, j, -1, 1)); // 右上對角
                max_length = max(max_length, find_longest_path(maze, i, j, 1, 1));  // 右下對角
                max_length = max(max_length, find_longest_path(maze, i, j, -1, -1)); // 左上對角
                max_length = max(max_length, find_longest_path(maze, i, j, 1, -1));  // 左下對角
            }
        }
    }

    printf("Ans=%d\n", max_length);
}
