# atcoder-cpp

Utility for AtCoder written in c++

# Contents

## root directory

- main.cpp
    - including some macros, functions, and constants
    - including some pre-processing in main function

## lib directory

- dijkstra.cpp
    - utility of dijkstra Algorithm
- geometry.cpp
    - computing a intersection of two lines
    - distanse between point and line
- math_lib.cpp
    - gcd and lcm
    - is prime?
    - prime factorization
    - divisors
- mod_lib.cpp
    - some function for computing large numbers
- string_lib.cpp
    - explode (featuring same function from PHP)
    - z_algorithm
- unionfind.cpp
    - union-find data structure by size
- warshall_floyd.cpp
    - utility of Warshall-Floyd Algorithm

### lib/combination

containing combination libraries

- combination_class.cpp
    - combination calculator
- next_combination.cpp
    - next_combination function
        - imitating next_premutation
- order_k_combination.cpp
    - calculate the number of combinations as formula (required inverse list)
- pascals_triangle.cpp
    - Pascal's triangle calculator

### lib/segment_tree

- point_add_range_sum.cpp
    - range sum
- range_minimum_query.cpp
    - RMQ
- with_min_index.cpp
    - RMQ with minimum index

