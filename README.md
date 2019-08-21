# SPMV
Above code explains the three different pardigms of the graphs. 
* Use of linear algebra for graph traversal.
* Breadth First Strategy
* Parallellism using OpenMP

### Linear Algebra 

* It has different implementations like:
  - SpMV (Sparse Matrix-Vector Multiplication)
  - SpMSpV (Sparse Matrix-Sparse Vector Multiplication)
  
* Breadth First Search Traversal is predominantly used method for traversing. 

 <!--- just --->
 
 
### How to run:
- cd SPMV/code  
- make 
- ./executable [dataset] [vector] [number_of_threads] 

## References

> [1] Paul Burkhardt, “Optimal algebraic Breadth-First Search for sparse graphs”.
> https://arxiv.org/pdf/1906.03113.pdf

> [2] Kepner et al., “Mathematical Foundations of the GraphBLAS”.
> https://people.eecs.berkeley.edu/~aydin/GraphBLAS-Math.pdf

> [3] Maciej Besta et al. “SlimSell: A Vectorizable Graph Representation for Breadth-First
Search, the 31st IEEE International Parallel & Distributed Processing Symposium
(IPDPS'17).

> [4] A. Buluc and K. Madduri. “Graph partitioning for scalable distributed graph computations”
Graph Partitioning and Graph Clustering, 588:83, 2013.

> [5] Aydin Buluç, Kamesh Madduri, Parallel breadth-first search on distributed memory
systems. SC 2011: 65:1-65:12

> [6] Carl Yang, Yangzihao Wang, and John D. Owens, Fast Sparse Matrix and Sparse Vector
Multiplication Algorithm on the GPU, IEEE International Parallel and Distributed
Processing Symposium Workshop 2015.

> [7] Kepner, Jeremy & Bader, David & Buluç, Aydin & Gilbert, John & Mattson, Tim & Meyerhenke, Henning. (2015). Graphs, matrices, and the GraphBLAS: Seven good reasons. Procedia Computer Science. 51. 10.1016/j.procs.2015.05.353. 

> [8] https://snap.stanford.edu/data/

> [9] https://github.com/puckbee/CVR

> [10] https://github.com/chaihf/BFS-OpenMP

