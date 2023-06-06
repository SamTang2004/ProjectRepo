class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        # with sorted
        sortedNums = sorted(nums)
        if nums == sortedNums:
            return 0
        res = 0
        errStart = 0
        errEnd = 0
        for i in range(len(nums)):
            if nums[i] != sortedNums[i]:
                errStart = i
                break
        
        for i in reversed(range(len(nums))):
            if nums[i] != sortedNums[i]:
                errEnd = i
                break
        return errEnd - errStart + 1