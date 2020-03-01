class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        res = []
        n = len(nums)
        for i in range(n):
            cnt = 0
            for j in range(n):
                cnt += (nums[j] < nums[i])
            res.append(cnt)
        
        return res