from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = list()
        current = []

        def dfs(idx: int, tar: int):
            if idx == len(candidates):
                return
            if tar == 0:
                results.append(current[:])   # 注：results.append(current) 写法是错误的，相当于浅。但是需求是只需要数组里的值，而不是引用
                return
            dfs(idx + 1, tar)  # 直接跳过
            if tar - candidates[idx] >= 0:
                current.append(candidates[idx])
                tar -= candidates[idx]
                dfs(idx, tar)
                current.pop()
        dfs(0, target)
        return results

if __name__ == '__main__':
    candidates = [2, 3, 6, 7]
    target = 7
    results = Solution().combinationSum(candidates, target)
    print(results)
