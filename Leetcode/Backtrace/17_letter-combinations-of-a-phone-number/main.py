from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return list()
        phone_map = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        combination = list()
        combinations = list()

        def backtrack(index: int):
            if index == len(digits):
                combinations.append("".join(combination))  # ['a', 'd', 'g'] → 'adg'
            else:
                num = digits[index]
                for letter in phone_map[num]:
                    combination.append(letter)
                    backtrack(index + 1)
                    combination.pop()

        backtrack(0)  # 执行内部的回溯子程序
        return combinations


if __name__ == '__main__':
    digits = "23"
    s = Solution()
    res = s.letterCombinations(digits)
    print(res)
