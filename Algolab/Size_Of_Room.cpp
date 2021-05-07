#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct element { char x, y; };
element moveD[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

char room[100][100];
char visited[100][100];

int m, n;
int cnt;
void HowManyRoom(int x, int y) {
    visited[x][y] = '+';
    cnt++;
    for (int i = 0; i < 4; i++) {
        int next_Y = y + moveD[i].y;
        int next_X = x + moveD[i].x;
        if (0 <= next_Y && next_Y < m && 0 <= next_X && next_X < n) {
            if (room[next_X][next_Y] == '.' && visited[next_X][next_Y] != '+') 
                HowManyRoom(next_X, next_Y);
        }
    }
}
int main() {
    string line;
    cin >> m >> n;

    fill(&room[0][0], &room[n - 1][m], 0);
    fill(&visited[0][0], &visited[n - 1][m], 0);

    for (int j = 0; j < n; j++) {
        cin >> line;
        for (int k = 0; k < m; k++) {
            room[j][k] = line[k];
        }
    }
    vector<int>Rcount;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (room[j][k] == '.' && visited[j][k] != '+') {
                cnt = 0;
                HowManyRoom(j, k);
                Rcount.push_back(cnt);
            }
        }
    }
    cout << Rcount.size() << endl;
    sort(Rcount.begin(), Rcount.end(), greater<int>());
    for (int c = 0; c < Rcount.size(); c++) cout << Rcount[c] << " ";
    cout << endl;
    return 0;
}