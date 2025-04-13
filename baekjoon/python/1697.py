import sys
from collections import deque
input = sys.stdin.readline

# N -> K
# N+1, N-1, N*2

N, K=map(int, input().split())

dq=deque()
visit=set()
# 위치, 시간
dq.append((N, 0))
visit.add(N)

while dq:
    # 현재위치, 시간
    cx, ct = dq.popleft()

    if cx==K:
        print(ct)
        # 멈추기
        break

    if cx > 100_000:
        # 이거는 건너뜀
        continue

    # N+1, N-1, N*2
    # 방문이 가능한지 -> 경계값 체크(가능한지)
    # 중복체크(방문한적이 있는지)
    
    # 방문 가능 체크 X
    # 중복 체크 -> 없으면 반복
    
    # nx = cx+1
    # if nx not in visit:
    #     # 새로운 지점, 시간+1
    #     dq.append((nx, ct+1))
    #     visit.add(nx)
    
    # nx = cx-1
    # if nx not in visit:
    #     # 새로운 지점, 시간+1
    #     dq.append((nx, ct+1))
    #     visit.add(nx)

    # nx = cx*2
    # if nx not in visit:
    #     # 새로운 지점, 시간+1
    #     dq.append((nx, ct+1))
    #     visit.add(nx)

    for nx in (cx + 1, cx - 1, cx * 2):
        if nx not in visit:
            dq.append((nx, ct + 1))
            visit.add(nx)