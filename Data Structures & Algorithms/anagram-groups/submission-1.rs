impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagram_groups: HashMap<String, Vec<String>> = HashMap::new();

        for string in strs{
            let mut vec_string: Vec<char> = string.chars().collect();
            vec_string.sort();
            let sorted_string = vec_string.into_iter().collect();
            anagram_groups.entry(sorted_string).or_default().push(string);
        }
        return anagram_groups.into_values().collect();
    }
}
