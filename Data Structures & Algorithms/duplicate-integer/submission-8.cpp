class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Create a hash set to store unique elements
        unordered_set<int> seen;

        // Iterate through the array
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Otherwise, add the number to the set
            seen.insert(num);
        }

        // No duplicates found
        return false;
    }
};