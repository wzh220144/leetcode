class Solution {
public:
  const int32_t XS[4] = {0, 0, -1, 1};
  const int32_t YS[4] = {1, -1, 0, 0};
  const int32_t DIRECTION_NUM = 4;

  int32_t xl = 0;
  int32_t yl = 0;

  void dfs(const vector<vector<char>> &grid, const int32_t &i, const int32_t &j,
           vector<vector<bool>> *m) {
    (*m)[i][j] = true;
    for (int32_t d = 0; d < DIRECTION_NUM; ++d) {
        int32_t next_i = i + XS[d];
        int32_t next_j = j + YS[d];
        if ( next_i < xl && next_i >= 0 && next_j < yl && next_j >= 0 ) {
            if ( (!(*m)[next_i][next_j]) && grid[next_i][next_j] == '1') {
                dfs(grid, next_i, next_j, m);
            }
        }
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    std::vector<std::vector<bool>> m;
    xl = grid.size();
    for (const auto &x : grid) {
      yl = x.size();
      std::vector<bool> t;
      for (const auto &y : x) {
        t.emplace_back(false);
      }
      m.emplace_back(std::move(t));
    }
    int32_t res = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      const auto &line = grid[i];
      for (size_t j = 0; j < line.size(); ++j) {
        if (m[i][j]) {
          continue;
        }
        if (line[j] == '0') {
          continue;
        }
        dfs(grid, i, j, &m);
        ++res;
      }
    }
    return res;
  }
};