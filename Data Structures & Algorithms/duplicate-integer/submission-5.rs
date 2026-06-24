impl Solution {
    pub fn has_duplicate(mut nums: Vec<i32>) -> bool {
        if nums.len() == 0 {
            return false;
        }
    
        nums.sort();

        for index in 0..(nums.len() -1){
            if nums[index] == nums[index + 1]{
                return true;
            }
        }

        false

    }
}
