#include <stdio.h>
#include <string.h>

char grid[1024][1024];
int vis[1024][1024];
int N, M;
int qx[2000000], qy[2000000];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", grid[i]);

    int ans = 0;
    int fx[4] = {1, -1, 0, 0};
    int fy[4] = {0, 0, 1, -1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                ans++;
                int h = 0, t = 0;
                qx[t] = i; qy[t++] = j;
                vis[i][j] = 1;
                while (h < t) {
                    int x = qx[h], y = qy[h++];
                    for (int k = 0; k < 4; k++) {
                        int nx = x + fx[k], ny = y + fy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (!vis[nx][ny] && grid[nx][ny] == '.') {
                                vis[nx][ny] = 1;
                                qx[t] = nx; qy[t++] = ny;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
