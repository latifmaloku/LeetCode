/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

/*
* first and last element is always going to be one for each row
* for i 0...numRows
* for j 0...numCels=i+1
* 1. if first cell or last then insert one into row
* 2. else add  cell = previousRow[j-1]+previousRow[j] to current row
* end loop
* end loop
* return solution
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> returnVect;
        for(int i = 0; i < numRows; i++)
        {
            // store row i
            vector<int> row;
            for (int j = 0; j < i+1; j++)
            {
                // is this first or last cell in current row
                if(j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    // cell = previousRow[j-1]+previousRow[j] to current row
                    row.push_back(returnVect[i-1][j-1]+returnVect[i-1][j]);
                }

            }
            // add current row to solution
            returnVect.push_back(row);


        }
        // return solution
        return returnVect;
    }
};