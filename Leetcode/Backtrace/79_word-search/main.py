from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # h, w = len(board), len(board[0])
        # visited = set()
        def check(i: int, j: int, k: int) -> bool:
            if board[i][j] != word[k]:
                return False
            elif k == len(word) - 1:
                return True
            visited.add((i, j))
            result = False
            for new_i, new_j in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= new_i < h and 0 <= new_j < w:
                    if (new_i, new_j) not in visited:
                        if check(new_i, new_j, k + 1):
                            result = True
                            break
            visited.remove((i, j))
            return result

        h, w = len(board), len(board[0])
        visited = set()
        for i in range(h):
            for j in range(w):
                if check(i, j, 0):
                    return True
        return False


if __name__ == '__main__':
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "ABCCED"
    is_exist = Solution().exist(board, word)
    if is_exist:
        print("true")  # expect: true
    else:
        print("false")
