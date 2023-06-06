class Solution:
    def gameOfLife(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        d= [0] * len(board[0])
        delta = []
        for i in range(len(board)):
            delta.append(d.copy())
        
        #print(delta)
        # return neighbour count
        def getNeighbourCount(x:int, y:int) -> int:
            count = 0
            try:
                count += board[y][x+1]
            except Exception:
                count += 0
            try:
                count += board[y+1][x]
            except Exception:
                count += 0

            if (x-1>=0):
                try:
                    count += board[y][x-1]
                except Exception:
                    count += 0
            if (y-1>=0):
                try:
                    count += board[y-1][x]
                except Exception:
                    count += 0
            try:
                count += board[y+1][x+1]
            except Exception:
                count += 0
            if (y-1>=0):
                try:
                    count += board[y-1][x+1]
                except Exception:
                    count += 0
            if (x-1>=0):
                try:
                    count += board[y+1][x-1]
                except Exception:
                    count += 0
            if x-1>=0 and y-1>=0:
                try:
                    count += board[y-1][x-1]
                except Exception:
                    count += 0
            
            return count
            
        
        # 0, -1, 1
        def getDelta(y: int, x :int) -> int:
            if board[y][x] == 0:
                if getNeighbourCount(x,y) != 3:
                    return 0
                else:
                    return 1
                    
            elif board[y][x] == 1:
                if getNeighbourCount(x,y) < 2:
                    return -1
                elif getNeighbourCount(x,y) > 3:
                    return -1
                else:
                    return 0
        for i in range(len(delta)):
            for j in range(len(delta[i])):
                delta[i][j]= getDelta(i,j)

        for i in range(len(delta)):
            for j in range(len(delta[i])):
                board[i][j] += delta[i][j]
            
Sol = Solution()
board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Sol.gameOfLife(board)
print(board)
