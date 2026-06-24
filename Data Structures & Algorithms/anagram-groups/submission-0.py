class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        string_list = []

        for i in range(0, len(strs)):
            for sublist in string_list:
                subliststring = "".join(sorted(sublist[0]))
                sorted_string = "".join(sorted(strs[i]))
                if sorted_string == subliststring:
                    sublist.append(strs[i])
            flag = 0
            for sublist in string_list:
                if strs[i] in sublist:
                    flag = 1
            
            if flag == 0:
                string_list.append([strs[i]])




        return string_list
