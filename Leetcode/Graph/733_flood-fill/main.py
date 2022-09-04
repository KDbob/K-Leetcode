from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        nr = len(image)
        nc = len(image[0])
        cur_color = image[sr][sc]
        image[sr][sc] = color

        def dfs(r, c):
            for i, j in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
                if 0 <= i < nr and 0 <= j < nc and image[i][j] != color and image[i][j] == cur_color:
                    image[i][j] = color
                    dfs(i, j)

        dfs(sr, sc)
        return image


if __name__ == '__main__':
    image = [
        ["1", "1", "1"],
        ["1", "1", "0"],
        ["1", "0", "1"],
    ]
    res = Solution().floodFill(image, 1, 1, 2)
    print(res)
