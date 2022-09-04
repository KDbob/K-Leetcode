from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = dict()
        for i,num in enumerate(numbers):
            if target - num in d:
                return [d[target - num], i]
            d[numbers[i]] = i
        return []


if __name__ == '__main__':
    res = Solution().twoSum([3, 2, 4], 6)
    print(res)
