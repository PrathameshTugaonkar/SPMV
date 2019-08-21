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

##Refernces

[1] Paul Burkhardt, “Optimal algebraic Breadth-First Search for sparse graphs”.
https://arxiv.org/pdf/1906.03113.pdf
[2] Kepner et al., “Mathematical Foundations of the GraphBLAS”.
https://people.eecs.berkeley.edu/~aydin/GraphBLAS-Math.pdf
[3] Maciej Besta et al. “SlimSell: A Vectorizable Graph Representation for Breadth-First
Search, the 31st IEEE International Parallel & Distributed Processing Symposium
(IPDPS'17).
[4] A. Buluc and K. Madduri. “Graph partitioning for scalable distributed graph computations”
Graph Partitioning and Graph Clustering, 588:83, 2013.
[5] Aydin Buluç, Kamesh Madduri, Parallel breadth-first search on distributed memory
systems. SC 2011: 65:1-65:12
[6] Carl Yang, Yangzihao Wang, and John D. Owens, Fast Sparse Matrix and Sparse Vector
Multiplication Algorithm on the GPU, IEEE International Parallel and Distributed
Processing Symposium Workshop 2015.
[7] Kepner, Jeremy & Bader, David & Buluç, Aydin & Gilbert, John & Mattson, Tim & Meyerhenke, Henning. (2015). Graphs, matrices, and the GraphBLAS: Seven good reasons. Procedia Computer Science. 51. 10.1016/j.procs.2015.05.353. 
[8] https://snap.stanford.edu/data/

