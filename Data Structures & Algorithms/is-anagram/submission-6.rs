impl Solution {
    pub fn is_anagram(mut s: String, mut t: String) -> bool {
        if s.len() != t.len(){
            return false;
        }

        let s_t_combined = s.bytes().zip(t.bytes());

        let mut letter_count = [0i32; 26];

        for (s_byte, t_byte) in s_t_combined{
            letter_count[(s_byte - b'a') as usize] += 1;
            letter_count[(t_byte - b'a') as usize] -= 1;
        }

        letter_count.iter().all(|&v| v == 0)
    }
}
