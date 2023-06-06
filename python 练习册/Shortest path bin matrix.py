class Solution:
    def shortestPathBinaryMatrix(self, grid) -> int:
        if grid[0][0] == 1:
                return -1
        def checkSurrounding(row, col, grid):
            possiblePaths = []
            probe = ()
            if row+1 < len(grid):
                if col+1 < len(grid):
                    if grid[row+1][col+1] == 0:
                        possiblePaths.append((row+1, col+1))
                if grid[row+1][col] == 0:
                    if grid[row+1][col] == 0:
                        possiblePaths.append((row+1, col))
                if col-1 >= 0:
                    if grid[row+1][col-1] == 0:
                        possiblePaths.append((row+1,col-1))
            if col-1 >= 0:
                if grid[row][col-1] == 0:
                    possiblePaths.append((row, col-1))
            if col+1 < len(grid):
                if grid[row][col+1] == 0:
                    possiblePaths.append((row, col+1))
            if row-1 >= 0:
                if col+1 < len(grid):
                    if grid[row-1][col+1] == 0:
                        possiblePaths.append((row-1, col+1))
                if grid[row-1][col] == 0:
                    possiblePaths.append((row-1, col))
                if col-1 >= 0:
                    if grid[row-1][col-1] == 0:
                        possiblePaths.append((row-1,col-1))
            return possiblePaths
        def dp(row, col, visited):
            
            visited[row][col] = 1
            if row == len(grid) -1 and col == len(grid) -1:
                return 1
            possiblePaths = checkSurrounding(row, col, visited)
            if len(possiblePaths) == 0:
                return 25536
            possibilities = []
            
            for i in possiblePaths:
                possibilities.append(dp(i[0],i[1], visited.copy()))
            print(possibilities,(row, col), possiblePaths)
            return 1 + min(possibilities)
        sol = dp(0,0,grid.copy())
        if sol > 10000:
            return -1
        return sol
sol = Solution()
print(sol.shortestPathBinaryMatrix([[0,1,0,0,0,0],[0,1,0,1,1,0],[0,1,1,0,1,0],[0,0,0,0,1,0],[1,1,1,1,1,0],[1,1,1,1,1,0]]))
