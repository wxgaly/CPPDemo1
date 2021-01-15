/*
 * @Author: gary.wang
 * @Date: 2021-01-15 20:22:44
 * @Last Modified by: gary.wang
 * @Last Modified time: 2021-01-15 20:49:14
 *

    On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

    A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

    Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone,
    return the largest possible number of stones that can be removed.

     

    Example 1:

    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    Output: 5
    Explanation: One way to remove 5 stones is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,1].
    2. Remove stone [2,1] because it shares the same column as [0,1].
    3. Remove stone [1,2] because it shares the same row as [1,0].
    4. Remove stone [1,0] because it shares the same column as [0,0].
    5. Remove stone [0,1] because it shares the same row as [0,0].
    Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.


 *
 */
#include "../ITest.h"

class Most StonesRemovedwithSameRoworColumn : public ITest {
  public:
    int removeStones1(vector<vector<int>> &stones) {
        vector<vector<int>> temp;
        int col = 0;
        int row = 0;
        int len = stones.size();
        for (size_t i = 0; i < len; i++) {
        }
    }
    void dfs(int x, vector<vector<int>> &edge, vector<int> &vis) {
        vis[x] = true;
        for (auto &y : edge[x]) {
            if (!vis[y]) {
                dfs(y, edge, vis);
            }
        }
    }
    // 并查集，，，，又是划水的一天
    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        vector<vector<int>> edge(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    edge[i].push_back(j);
                }
            }
        }
        vector<int> vis(n);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                num++;
                dfs(i, edge, vis);
            }
        }
        return n - num;
    }
    void test() {}
};