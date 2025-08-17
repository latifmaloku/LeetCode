/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;

        // Space complexity O(n)
        // lookup is O(1)
        unordered_map<int, int> temp;
        // iterate over all numbers
        // target = nums[i] + num[j] where j<i
        // 1) compute difference = target - num[i]
        // 2) if difference is in hash map, then we found our solution if
        // hashmap[i], i 3) else store index in hashmap with differnce being key
        for (int i = 0; i < nums.size(); i++) {
            // this is the solution we are looging for
            // difference + num[i] = to our target.
            // difference will be stored in unordered map.
            int difference = target - nums[i];

            // check to see if hash map contains our key
            if (temp.count(difference)) {
                solution = {temp[difference], i};
                break;
            }

            // we have not reached a solution yet,
            // add this integer with its index to the hash map.
            // By leaving it at the end, we avoid overiding a previous index
            // with the current index.
            temp[nums[i]] = i;
        }
        return solution;
    }
};