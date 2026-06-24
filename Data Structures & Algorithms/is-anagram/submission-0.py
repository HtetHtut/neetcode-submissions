class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map = {}
        t_map = {}

        for char in s:
            if char in s_map:
                s_map[char] += 1
            else:
                s_map[char] = 0
        for char in t:
            if char in t_map:
                t_map[char] += 1
            else:
                t_map[char] = 0
        
        if t_map != s_map:
            return False
        return True