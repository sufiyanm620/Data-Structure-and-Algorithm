class Solution:
    def pacificAtlantic(self, grid: List[List[int]]) -> List[List[int]]:

        rows = len(grid)
        cols = len(grid[0])

        pacific = set()
        atlantic = set()
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        def dfs(r, c, ocean):
            if (r, c) in ocean:
                return
            ocean.add((r, c))
            for dr, dc in directions:
                nr = r + dr
                nc = c + dc
                if (
                    0 <= nr < rows
                    and 0 <= nc < cols
                    and grid[nr][nc] >= grid[r][c]
                ):
                    dfs(nr, nc, ocean)
        for c in range(cols):
            dfs(0, c, pacific)
        for r in range(rows):
            dfs(r, 0, pacific)
        for c in range(cols):
            dfs(rows - 1, c, atlantic)
        for r in range(rows):
            dfs(r, cols - 1, atlantic)
        ans = []
        for r in range(rows):
            for c in range(cols):
                if (r, c) in pacific and (r, c) in atlantic:
                    ans.append([r, c])
        return ans

