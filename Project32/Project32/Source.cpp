#include <iostream>
using namespace std;

int main() {
    int h = 0, m = 0, n = 0;
    cin >> h >> m >> n;
    char** arr = new char* [m];
    for (int i = 0; i < m; ++i)
        arr[i] = new char[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int* count = new int[h];
    int* maxCount = new int[h];
    for (int i = 0; i < h; i++) {
        count[i] = 0;
        maxCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (char(arr[j][i]) - 97 <= h) {
                count[char(arr[j][i]) - 97]++;
            }
            if (count[char(arr[j][i]) - 97] > maxCount[char(arr[j][i]) - 97]) maxCount[char(arr[j][i]) - 97] = count[char(arr[j][i]) - 97];
            if (j + 1 < m && char(arr[j][i]) != char(arr[j + 1][i])) count[char(arr[j][i]) - 97] = 0;
            if (j == m - 1 && i + 1 < n && char(arr[j][i]) != char(arr[0][i + 1])) count[char(arr[j][i]) - 97] = 0;
            if (m == 1) count[char(arr[j][i]) - 97] = 0;
        }
    }


    for (int i = 0; i < h; i++)
        cout << char(i + 97) << " " << maxCount[i] << endl;
    //delete[]arr;
}
