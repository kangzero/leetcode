class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        
        if (numRows <= 0) return pascal; 
        
        vector<int> row = {1};
        pascal.push_back(row);
        
        for (int i = 1; i < numRows; i++) {
            vector<int> nextRow(row.size()+1);
            nextRow[0] = 1;
            nextRow[nextRow.size()-1] = 1; 
            for (int j = 1; j < (nextRow.size()-1); j++) {
                nextRow[j] = row[j-1] + row[j];
            }
            pascal.push_back(nextRow);
            row = nextRow;
        }
        
        return pascal;
    }
};
