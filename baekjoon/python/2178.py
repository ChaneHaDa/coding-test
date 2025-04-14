import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
maps = [str(input()).strip() for _ in range(N)]

# maps -> M*M 배열
# (0, 0) -> (N-1, M-1)
# 1만 이동 가능
# 항상 도착 가능

dq = deque()
visit = set()

# 시작 X, 시작 Y, 현재까지 이동칸수
dq.append((0, 0, 0))
visit.add((0, 0))

while dq:
    cx, cy, cd = dq.popleft()

    if cx==N-1 and cy==M-1:
        print(cd+1)
        break

    # 상하좌우
    # 새로 방문하는 x, y
    for (nx, ny) in ((cx+1, cy), (cx-1, cy), (cx, cy+1), (cx, cy-1)):
        
        # 방문이 가능한지 -> 경계값 체크(가능한지)
        # 중복체크(방문한적이 있는지)

        if nx<0 or nx>=N or ny<0 or ny>=M:
            continue
        
        # 방문한 적이 없고, 1일 때 -> 방문가능
        if (nx, ny) not in visit and maps[nx][ny]=='1':
            # 새로운 위치, 거리+1
            dq.append((nx, ny, cd+1))
            visit.add((nx, ny))