impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {

        let mut prev_map = HashMap::new(); // val -> index

        for (i, &n) in nums.iter().enumerate() {
            let diff = target - n;
            if let Some(&index) = prev_map.get(&diff) {
                return vec![index as i32, i as i32];
            }
            prev_map.insert(n, i);
        }

        vec![]
    }
}
