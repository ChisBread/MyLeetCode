class Solution {
public:
	int numIslands(vector<vector<char> > &grid);
	void search(vector<vector<char> > &grid, int i, int j);
};
int Solution::numIslands(vector<vector<char> > &grid) {
	int num = 0;
	for(int i = 0; i < grid.size(); ++i) {
		for(int j = 0; j < grid[i].size(); ++j) {
			if(grid[i][j] == '1') {
				search(grid, i, j);//Delete this island
				++num;
			}
		}
	}
	return num;
}
void Solution::search(vector<vector<char> > &grid, int i, int j) {
	if(i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && (grid[i][j] == '1')) {
		grid[i][j] = '2';//or '0', just not '1'
		search(grid, i + 1, j);
		search(grid, i - 1, j);
		search(grid, i, j + 1);
		search(grid, i, j - 1);
	}
}
//not fastest, but easy
