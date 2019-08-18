# SPMV
General BFS SpMV algorithm

Input: Sparse matrix G, source vertex s, diameter d.

Output: Dense vector π where π[v] is the shortest path
from s to v, or -1 if u is unreachable.

1: for each v ∈ V in parallel do

2:w[v] ⇐ 0

3:π[v] ⇐ −1

4: end for

5: w[s] ⇐ 1

6: π[s] ⇐ 0

7: for i ← 1, d do

8:w ⇐ M ULTIPLY BFS(G T , w)

9:for each v ∈ V in parallel do

10:if w[v]=1 and π[v] = −1 then

11:π[v] ⇐ i

12:else

13:w[v] ⇐ 0

14:end if

15:end for

16: end for
