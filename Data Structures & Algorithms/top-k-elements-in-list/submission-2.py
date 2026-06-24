class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        element_frequency_map = {}
        for num in nums:
            if num in element_frequency_map:
                element_frequency_map[num] += 1
            else:
                element_frequency_map[num] = 1
        result= []
        sorted_list = sorted(element_frequency_map.items(), key=lambda item: item[1])
        for i in range(0, k):
            result.append(sorted_list.pop()[0])

        return result