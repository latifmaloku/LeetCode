/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

/*
* first and last element is always going to be one for each row

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> returnVect;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j < i+1; j++)
            {
                if(j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(returnVect[i-1][j-1]+returnVect[i-1][j]);
                }

            }
            returnVect.push_back(row);


        }
        return returnVect;
    }
};