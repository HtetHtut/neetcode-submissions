impl Solution {
    pub fn encode(strs: Vec<String>) -> String
    {
        strs.iter()
        .map(|string| format!("{}:{}", string.len(), string))
        .collect()
    }

    pub fn decode(s: String) -> Vec<String>
    {
        let mut res: Vec<String> = Vec::new();
        let mut i = 0;
        let bytes = s.as_bytes();

        while i < bytes.len()
        {
            let mut j = i;
            while bytes[j] != b':' {j += 1; }
            let length: usize = s[i..j].parse().unwrap();
            i = j+1;
            res.push(s[i..i+length].to_string());
            i += length;
        }
        res
    }
}

//    pub fn decode(s: String) -> Vec<String> {

//         let mut res = Vec::new();
//         let mut i = 0;
//         let bytes = s.as_bytes();
//         while i < bytes.len() {
//             let mut j = i;
//             while bytes[j] != b':' { j += 1; }
//             let len: usize = s[i..j].parse().unwrap();
//             i = j + 1;
//             res.push(s[i..i + len].to_string());
//             i += len;
//         }
//         res

//     }