from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutes = list()
        permute = list()

        def backtrace(index: int):
            if index == len(nums):
                permutes.append(permute[:])  # 注：permutes.append(permute) 写法是错误的，相当于深拷贝。但是需求是只需要数组里的值，而不是引用
            else:
                for num in nums:
                    if not permute.__contains__(num):
                        permute.append(num)
                        backtrace(index + 1)
                        permute.pop()

        backtrace(0)
        return permutes


if __name__ == '__main__':
    nums = [1, 2, 3]
    s = Solution()
    res = s.permute(nums)
    print(res)  # expect：[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
