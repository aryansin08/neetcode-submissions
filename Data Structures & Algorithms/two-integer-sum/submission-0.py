class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        i, j = 0, len(nums) - 1
        while(i<j):
            sum = nums[i]+nums[j]
            if(sum==target):
                return [i, j]
            elif(sum<target):
                i+=1
            else:
                j-=1
        