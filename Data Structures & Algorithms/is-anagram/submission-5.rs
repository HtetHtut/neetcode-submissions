use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len(){
            return false;
        }

        let mut char_counts: HashMap<char, usize> = HashMap::with_capacity(s.len());
        for character in s.chars() {
            *char_counts.entry(character).or_insert(0) += 1
        }
        for character in t.chars() {
            let entry = char_counts.entry(character).or_insert(0);
            if *entry == 0 {
                return false;
            }
            *entry -= 1;
        }

        true
    }
}
