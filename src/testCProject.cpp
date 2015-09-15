#include <stdio.h>

char grid[100][100];

int m, n;
int counter;

void dfs(int i, int j) {
	if (grid[i][j] == '@') {
		grid[i][j] = ' ';
	}
	//1
	if (i - 1 >= 0 && i - 1 <= m && j - 1 >= 0 && j - 1 <= n) {
		if (grid[i - 1][j - 1] == '@') {
			dfs(i - 1, j - 1);
		}
	}

	//2
	if (i - 1 >= 0 && i - 1 <= m && j >= 0 && j <= n) {
		if (grid[i - 1][j] == '@') {
			dfs(i - 1, j);
		}
	}

	//3
	if (i - 1 >= 0 && i - 1 <= m && j + 1 >= 0 && j + 1 <= n) {
		if (grid[i - 1][j + 1] == '@') {
			dfs(i - 1, j + 1);
		}
	}

	//4
	if (i >= 0 && i <= m && j - 1 >= 0 && j - 1 <= n) {
		if (grid[i][j - 1] == '@') {
			dfs(i, j - 1);
		}
	}

	//5
	if (i >= 0 && i <= m && j + 1 >= 0 && j + 1 <= n) {
		if (grid[i][j + 1] == '@') {
			dfs(i, j + 1);
		}
	}

	//6
	if (i + 1 >= 0 && i + 1 <= m && j - 1 >= 0 && j - 1 <= n) {
		if (grid[i + 1][j - 1] == '@') {
			dfs(i + 1, j - 1);
		}
	}

	//7
	if (i + 1 >= 0 && i + 1 <= m && j >= 0 && j <= n) {
		if (grid[i + 1][j] == '@') {
			dfs(i + 1, j);
		}
	}

	//8
	if (i + 1 >= 0 && i + 1 <= m && j + 1 >= 0 && j + 1 <= n) {
		if (grid[i + 1 ][j + 1 ] == '@') {
			dfs(i + 1, j + 1);
		}
	}

}

int main() {
	while (true) {
		counter = 0;
		scanf("%d %d", &m, &n);

		if (m == 0) {
			break;
		}

		for (int i = 0; i < m; ++i) {
			scanf("%s", grid[i]);
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '@') {
					dfs(i, j);
					counter++;
				}
			}
		}

		printf("%d\n", counter);
	}

	return 0;
}
