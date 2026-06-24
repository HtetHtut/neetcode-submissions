impl Solution {
    pub fn has_duplicate(mut nums: Vec<i32>) -> bool {
    nums.sort();

    if nums.len() == 0 {
        return false;
    }
    
    for i in 0..(nums.len() - 1){
        if nums[i] == nums[i+1]{
            return true;
        }
    }

    false
    }
}
