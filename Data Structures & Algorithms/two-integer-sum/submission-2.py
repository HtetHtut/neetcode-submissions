class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numhash = {}
        for i in range(0, len(nums)):
            if (target - nums[i]) in numhash:
                return [numhash[target-nums[i]], i]
            else:
                numhash[nums[i]] = i

# need to practice again