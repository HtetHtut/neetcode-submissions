use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::with_capacity(nums.len());
        
        for (index, &number) in nums.iter().enumerate() {
            let complement = target - number;
            
            if let Some(&matching_index) = map.get(&complement) {
                return vec![matching_index as i32, index as i32];
            }
            
            map.insert(number, index);
        }
        
        vec![]
    }
}