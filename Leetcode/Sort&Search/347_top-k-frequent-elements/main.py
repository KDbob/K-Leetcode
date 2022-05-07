import collections
import heapq
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = collections.Counter(nums)
        heap = list()
        for key, val in count.items():
            if len(heap) < k:
                heapq.heappush(heap, (val, key))
            else:
                if val > heap[0][0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap, (val, key))
        return [item[1] for item in heap]


if __name__ == '__main__':
    nums = [1, 1, 1, 1, 2, 2, 2, 3, 4]
    res = Solution().topKFrequent(nums, 2)
    print(res)