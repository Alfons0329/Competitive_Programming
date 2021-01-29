class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        res = nums[0] # at least one
        seen = [0 for i in range(10005)]
        i = 0
        while i < len(nums) - 1:
            tmp = []
            tmp.append(nums[i])
            seen[nums[i]] += 1
            j = i + 1
            while j < len(nums) and j > i:
                if(seen[nums[j]]):
                    seen[nums[i]] -= 1
                    i += 1
                    tmp.pop(0)
                else:
                    tmp.append(nums[j])
                    res = max(sum(tmp), res)
                    seen[nums[j]] += 1
                    j += 1                
        
        res = max(res, nums[-1])
        return res
