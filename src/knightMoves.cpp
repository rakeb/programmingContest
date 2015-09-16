#include <stdio.h>
#include <vector>
#include <queue>
#define INFINITY 99999
#define M 8
#define N 8

bool isValidIndex(int i, int j) {
	return (i >= 0 && i <= M -1 && j >= 0 && j <= N -1);
}


int main() {
	char start[3], end[3];
	int sx, sy, ex, ey, xx, yy, distant;
	int grid[8][8];
	int neighbor[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {+1, -2}, {+2, -1}, {+2, +1}, {-1, +2}, {+1, +2},};

	std::vector <int> point(2);
	std::queue <std::vector <int> > queuePoints;

	while (scanf("%s  %s", start, end) == 2) {
		sx = start[0] - 'a';
		sy = start[1] - '1';
		ex = end[0] - 'a';
		ey = end[1] - '1';

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				grid[i][j] = INFINITY;
			}
		}

		grid[sx][sy] = 0;
		point[0] = sx;
		point[1] = sy;

		queuePoints.push(point);

		while(!queuePoints.empty()) {
			point = queuePoints.front();
			queuePoints.pop();

			xx = point[0];
			yy = point[1];

			distant = grid[xx][yy];

			for (int i = 0; i < M; ++i) {
				int x =xx + neighbor[i][0];
				int y =yy + neighbor[i][1];

				if (isValidIndex(x, y)) {
					if (grid[x][y] == INFINITY) {
						grid[x][y] = distant +1;

						point[0] = x;
						point[1] = y;
						queuePoints.push(point);
					}
				}
			}
		}

//		for (int i = 0; i < 8; ++i) {
//			for (int j = 0; j < 8; ++j) {
//				printf("%d ",grid[i][j]);
//			}
//			printf("\n");
//		}
		printf("To get from %s to %s takes %d knight moves.\n", start, end,
				grid[ex][ey]);
	}

	return 0;
}
