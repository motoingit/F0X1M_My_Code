# 🗺 The Big Map of Data Structures & Algorithms

## 1. What Are Data Structures? (The "Containers")
How we organize and store data.

### Basic Containers
- *Array*: A fixed-size list of items, like a numbered row of mailboxes.
- *Stack*: A LIFO (Last-In, First-Out) pile, like a stack of plates.
- *Queue*: A FIFO (First-In, First-Out) line, like a checkout line at a store.
- *Linked List*: A chain of items, where each item points to the next.
  - Doubly Linked List: Each item points to the next and the previous.
- *Hash Table (or Map)*: Uses a "hash" to store key-value pairs, like a super-fast coat check.
- *Set*: A container that only stores unique items, like a collection of unique stamps.

### Hierarchical Containers (Trees)
- *Binary Search Tree (BST)*: A tree where the left side is smaller and the right side is larger.
- *Heap*: A tree that's great at finding the "biggest" or "smallest" item quickly.
  - Min-Heap
  - Max-Heap
- *AVL Tree*: A self-balancing BST to keep searches fast.
- *Trie (Prefix Tree)*: A special tree used for storing strings, great for autocompletion.

### Graph Containers (Networks)
- *Graph*: A set of nodes (vertices) connected by edges, like a map of cities and roads.
  - Directed Graph (one-way roads)
  - Undirected Graph (two-way roads)
  - Directed Acyclic Graph (DAG) (one-way roads with no way to loop back)

## 2. What Are Algorithms? (The "Recipes")
A step-by-step set of instructions to solve a problem.

### Measuring Recipes (Time Complexity)
How we measure an algorithm's "speed" as the input gets bigger.
- *$O(1)$ - Constant*: 🚀 Blazing fast (always takes the same time).
- *$O(\log n)$ - Logarithmic*: Very fast (e.g., finding a word in a dictionary).
- *$O(n)$ - Linear*: Good (time scales directly with input size).
- *$O(n \log n)$ - Log-Linear*: The sweet spot for sorting!
- *$O(n^2)$ - Quadratic*: Getting slow (e.g., checking every pair in a list).
- *$O(2^n)$ - Exponential*: 🐢 Extremely slow (avoid at all costs!).

### Common Algorithm "Families"

#### Searching Algorithms
- *Linear Search*: $O(n)$
  - Analogy: Looking for a book on a messy shelf, one by one.
- *Binary Search*: $O(\log n)$
  - Prerequisite: *Must be on a sorted list!*
  - Analogy: Finding a word in a dictionary by splitting it in half repeatedly.

#### Sorting Algorithms
- *Simple (but slower) Sorts*: $O(n^2)$
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
- *Efficient (and fast!) Sorts*: $O(n \log n)$
  - Merge Sort
  - Quick Sort
  - Heap Sort
- *Specialty Sorts*
  - Radix Sort: $O(nk)$ (great for sorting numbers)

#### Traversal Algorithms (How to "visit" every item)
- *Tree Traversal*
  - Pre-order (Root-Left-Right)
  - In-order (Left-Root-Right) - Gives you a sorted list from a BST!
  - Post-order (Left-Right-Root)
- *Graph Traversal*
  - *Depth-First Search (DFS)*: Goes as deep as it can before backtracking.
    - Analogy: Exploring a maze by always taking the first path you see.
  - *Breadth-First Search (BFS)*: Explores all neighbors first.
    - Analogy: Spreading a rumor—it goes to all your friends, then all their friends.
