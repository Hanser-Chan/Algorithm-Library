#include <iostream>
#include <algorithm>
#include <vector>


using std::min,std::max,std::vector;

int maxScore(vector<vector<int>>& grid) {
    size_t row{grid.size()},col{grid[0].size()};
    int maxRes{INT_MIN};
    vector<vector<int>> minMat(row,vector<int>(col,INT_MIN));

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            int num = INT_MAX;

            if (i > 0) {
                num = min(num,minMat[i - 1][j]);
                std::cout << "if i>0 " << num << '\n';
            }

            if (j > 0) {
                num = min(num, minMat[i][j - 1]);
                std::cout << "if j>0 " << num << '\n';
            }

            if (i + j > 0){
                maxRes = max(maxRes, grid[i][j] - num);
                std::cout << "if i+j>0 " << maxRes << '\n';
            }

            minMat[i][j] = min(num, grid[i][j]);
            std::cout << "for " << minMat[i][j] << '\n';
        }
    }
    return maxRes;
}

int main() {
    vector<vector<int>> grid1 {{4,3,2},{3,2,1}};
    vector<vector<int>> grid2{{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    std::cout << maxScore(grid2);
}
