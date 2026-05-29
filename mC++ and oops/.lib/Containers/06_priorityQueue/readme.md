Perfect. Let’s build **serious, interview-ready notes** on `priority_queue` in C++ STL. No fluff — only what actually matters. 🧠⚙️

---

# 🔷 What is `priority_queue`?

`std::priority_queue` is a **container adaptor** built on top of a **heap** (usually a binary heap).

It always keeps the **highest priority element at the top**.

By default:

> 🔥 It is a **max-heap**

---

## 📌 Header

```cpp
#include <queue>
```

---

# 🔹 Default Behavior (Max Heap)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << pq.top();  // 20
}
```

### Internally:

```
20
/  \
5   10
```

---

# 🔹 Core Operations

| Function  | What it does       | Time     |
| --------- | ------------------ | -------- |
| `push(x)` | Insert element     | O(log n) |
| `pop()`   | Remove top         | O(log n) |
| `top()`   | Access top         | O(1)     |
| `empty()` | Check empty        | O(1)     |
| `size()`  | Number of elements | O(1)     |

⚠️ `pop()` does NOT return value.
You must do:

```cpp
int x = pq.top();
pq.pop();
```

---

# 🔷 Min Heap (Most Important Trick)

Default is max-heap.

To make **min-heap**:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Example:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(5);
pq.push(20);

cout << pq.top();  // 5
```

---

# 🔷 Custom Comparator (Advanced)

Example: sort by second element of pair

```cpp
priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;
```

Or custom struct:

```cpp
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // min heap behavior
    }
};

priority_queue<int, vector<int>, Compare> pq;
```

⚠️ Comparator returns `true` if order is wrong.

This confuses many people.

---

# 🔷 How It Works Internally

It uses:

```
vector + heap operations
```

Heap operations:

* `push_heap`
* `pop_heap`
* `make_heap`

Binary heap → complete binary tree stored in array.

Index formula:

```
parent = (i-1)/2
left = 2*i+1
right = 2*i+2
```

---

# 🔷 Common Interview Uses

### ✅ K Largest Elements

### ✅ Dijkstra's Algorithm

### ✅ Merge K Sorted Arrays

### ✅ Top K Frequent Elements

### ✅ Scheduling problems

### ✅ Sliding window problems

---

# 🔷 Difference: `set` vs `priority_queue`

| Feature                  | priority_queue           | set              |
| ------------------------ | ------------------------ | ---------------- |
| Top access               | O(1)                     | O(log n)         |
| Remove arbitrary element | ❌                        | ✅                |
| Ordered traversal        | ❌                        | ✅                |
| Best for                 | Highest priority element | Sorted structure |

If you need:

* Always max/min → use `priority_queue`
* Sorted structure with deletion anywhere → use `set`

---

# 🔷 Important Limitation

You **cannot iterate** over a priority queue directly.

If you want to print:

```cpp
while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
```

But this destroys it.

---

# 🔷 Build from existing container

```cpp
vector<int> v = {3,1,4,2};

priority_queue<int> pq(v.begin(), v.end());
```

Build heap in O(n).

---

# 🔷 Memory & Performance Notes

* Backed by vector
* Grows dynamically
* Logarithmic insert/remove
* Very cache friendly

---

# 🔷 Common Mistakes

### ❌ Forgetting `greater<int>` for min heap

### ❌ Expecting sorted order when popping

### ❌ Thinking it supports searching

### ❌ Trying to access second largest directly

---

# 🔥 Strong Take

If you don’t understand:

* max vs min heap
* custom comparator logic
* why pop doesn’t return value

You don’t really understand heaps.

And heaps are core to serious algorithmic work.

---

# 🎯 Quick Practice Question

Given array:

```
5 1 9 3 7
```

Write code to print 3 largest elements using `priority_queue`.

---

If you want next, we can:

* 🧠 Deep dive into heap theory
* ⚡ Solve Dijkstra step-by-step
* 🧪 Practice 5 priority queue problems
* 🎯 Explain comparator logic visually

Where do you want to go?
