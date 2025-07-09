#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class maze {
public:
    using Cell = pair<int, int>;
    vector<vector<int>> m_distance;
    vector<vector<Cell>> m_parent;
    const Cell unvisited_block = {-1, -1};
    Cell goal;
    Cell start;
    vector<vector<char>> matrix; // Add matrix as a member variable

    void inmaze(int row, int col) {
        m_distance.resize(row, vector<int>(col, -1));
        m_parent.resize(row, vector<Cell>(col, unvisited_block));
        matrix.resize(row, vector<char>(col));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                char c;
                cin >> c;
                matrix[i][j] = c;
                if (c == 'S') {
                    start.first = i;
                    start.second = j;
                }
                if (c == 'G') {
                    goal.first = i;
                    goal.second = j;
                }
            }
        }
    }

    int& distance(Cell& coord) {
        return m_distance[coord.first][coord.second];
    }

    Cell& parent(Cell& coord) {
        return m_parent[coord.first][coord.second];
    }

    bool unvisited(Cell& coord) {
        return parent(coord) == unvisited_block;
    }

    bool valid(Cell& coord) {
        int row = m_distance.size();
        int col = m_distance[0].size();
        if (coord.first >= 0 && coord.first < row && coord.second >= 0 && coord.second < col) {
            char cell = matrix[coord.first][coord.second];
            return cell == ' ' || cell == 'x' || cell == '0';
        }
        return false;
    }

    void bfs() {
        queue<Cell> q;
        Cell curr, temp;
        distance(start) = 0;
        parent(start) = {-2, -2};
        q.push(start);

        while (!q.empty() && unvisited(goal)) {
            curr = q.front();
            q.pop();

            temp = {curr.first + 1, curr.second};
            if (valid(temp) && unvisited(temp)) {
                distance(temp) = distance(curr) + 1;
                parent(temp) = curr;
                q.push(temp);
            }

            temp = {curr.first, curr.second - 1};
            if (valid(temp) && unvisited(temp)) {
                distance(temp) = distance(curr) + 1;
                parent(temp) = curr;
                q.push(temp);
            }

            temp = {curr.first - 1, curr.second};
            if (valid(temp) && unvisited(temp)) {
                distance(temp) = distance(curr) + 1;
                parent(temp) = curr;
                q.push(temp);
            }

            temp = {curr.first, curr.second + 1};
            if (valid(temp) && unvisited(temp)) {
                distance(temp) = distance(curr) + 1;
                parent(temp) = curr;
                q.push(temp);
            }
        }

        if (q.empty() && curr != goal) {
            cout << "No Path" << endl;
        } else {
            curr = parent(goal);
            while (curr != start) {
                matrix[curr.first][curr.second] = '*';
                curr = parent(curr);
            }

            // Print the updated maze
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    cout << matrix[i][j];
                }
                cout << endl;
            }
        }
    }
};

int main() {
    int row, col;
    cin >> row >> col;

    maze obj;
    obj.inmaze(row, col);
    obj.bfs();

    return 0;
}
