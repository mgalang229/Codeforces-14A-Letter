#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	// set variables to get the starting and ending
	// indices of both the row and column
	int starting_column_index = INT_MAX;
	int ending_column_index = INT_MIN;
	int starting_row_index = -1;
	int ending_row_index = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			// store the starting row and column index in the variable if it
			// encounters the first asterisk symbol
			// however, override the starting column index if and only if there is an 
			// asterisk symbol farther to the left of the
			// stored index of the former asterisk symbol
			if (v[i][j] == '*' && j < starting_column_index) {
				starting_column_index = j;
				if (starting_row_index == -1) {
					// store the row index ONLY in the first encounter of an asterisk symbol
					starting_row_index = i;
				}
			}
			// do same logic with the ending column index but override it
			// if and only if there is an asterisk farther to the right
			// of the stored index of the former asterisk symbol
			if (v[i][j] == '*' && j > ending_column_index) {
				ending_column_index = j;
			}
			// store the ending row index everytime it encounters an asterisk
			// symbol so gets updated everytime
			if (v[i][j] == '*') {
				ending_row_index = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		bool space = false;
		for (int j = 0; j < m; j++) {
			// check if the 'i' iterator is within the range of the starting and
			// ending row index (e.g., 'starting_row_index' <= i <= 'ending_row_index'
			if (i >= starting_row_index && i <= ending_row_index) {
				// check if the 'j' iterator is within the range of the starting and
				// ending column index (e.g., 'starting_column_index' <= j <= 'ending_column_index'
				if (j >= starting_column_index && j <= ending_column_index) {
					space = true;
					cout << v[i][j];
				}
			}
		}
		if (space) {
			cout << '\n';
		}
	}
	return 0;
}
