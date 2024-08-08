class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        // To store the path of cells visited
        vector<vector<int>> paths;
        // Start from the initial position
        paths.push_back({rStart, cStart});

        // Directions: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int steps = 0, direction = 0;

        // Loop until all cells are visited
        while (paths.size() != rows * cols) {

            // Increase steps after completing a right or left move
            if (direction == 0 || direction == 2) {
                steps++;
            }

            // Move `steps` number of cells in the current direction
            for (int i = 0; i < steps; i++) {
                rStart += directions[direction].first;
                cStart += directions[direction].second;

                // Check if the new position is within the bounds of the matrix
                if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols) {
                    paths.push_back({rStart, cStart});
                }
            }

            // Move to the next direction in the sequence
            direction = (direction + 1) % 4;
        }

        return paths;
    }
};