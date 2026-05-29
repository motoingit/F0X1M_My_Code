Perfect 👍
Here’s a **clean, practical Markdown (`.md`) file** for **`std::vector`** — focused on the **most used, real-world functions**, not noise.

You can paste this directly into
👉 `cpp_vector_cheatsheet.md`

---

````md
# C++ `std::vector` – Most Used Functions

`std::vector` is a **dynamic array** provided by the C++ STL.  
It supports fast random access and automatic resizing.

Header required:
```cpp
#include <vector>
````

---

## 🔹 Declaration & Initialization

### Declare vector

```cpp
vector<int> v;
```

### Initialize with values

```cpp
vector<int> v = {1, 2, 3};
```

### Initialize with size

```cpp
vector<int> v(5);        // size 5, default 0
vector<int> v(5, 10);    // size 5, all values 10
```

---

## 🔹 Capacity & Size

### `size()`

Returns number of elements.

```cpp
v.size();
```

### `empty()`

Checks if vector is empty.

```cpp
v.empty();
```

### `capacity()`

Returns allocated capacity.

```cpp
v.capacity();
```

### `reserve()`

Pre-allocate memory.

```cpp
v.reserve(100);
```

### `shrink_to_fit()`

Reduce capacity to size.

```cpp
v.shrink_to_fit();
```

---

## 🔹 Element Access

### `operator[]`

Fast access (no bounds check).

```cpp
v[i];
```

### `at()`

Safe access (throws exception).

```cpp
v.at(i);
```

### `front()` / `back()`

```cpp
v.front();
v.back();
```

### `data()`

Returns raw pointer.

```cpp
int* ptr = v.data();
```

---

## 🔹 Adding Elements

### `push_back()`

Add at end.

```cpp
v.push_back(10);
```

### `emplace_back()`

Construct element in-place.

```cpp
v.emplace_back(20);
```

### `insert()`

Insert at position.

```cpp
v.insert(v.begin() + 1, 100);
```

---

## 🔹 Removing Elements

### `pop_back()`

Remove last element.

```cpp
v.pop_back();
```

### `erase()`

Remove element or range.

```cpp
v.erase(v.begin() + 2);
v.erase(v.begin(), v.begin() + 3);
```

### `clear()`

Remove all elements.

```cpp
v.clear();
```

---

## 🔹 Resize & Assign

### `resize()`

Change size.

```cpp
v.resize(10);
v.resize(3);
```

### `assign()`

Replace contents.

```cpp
v.assign(5, 7);
```

---

## 🔹 Iterators

### Basic iterators

```cpp
v.begin();
v.end();
```

### Reverse iterators

```cpp
v.rbegin();
v.rend();
```

### Const iterators

```cpp
v.cbegin();
v.cend();
```

---

## 🔹 Traversal Methods

### Index-based

```cpp
for (int i = 0; i < v.size(); i++)
    cout << v[i];
```

### Range-based for loop

```cpp
for (int x : v)
    cout << x;
```

### Iterator-based

```cpp
for (auto it = v.begin(); it != v.end(); it++)
    cout << *it;
```

---

## 🔹 Vector with Algorithms

### Sort

```cpp
sort(v.begin(), v.end());
```

### Find

```cpp
auto it = find(v.begin(), v.end(), x);
```

### Count

```cpp
count(v.begin(), v.end(), x);
```

### Remove–Erase Idiom

```cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

---

## 🔹 2D Vector (Matrix)

```cpp
vector<vector<int>> mat(3, vector<int>(4, 0));
```

Access:

```cpp
mat[i][j];
```

---

## 🔹 Important Properties

* Contiguous memory
* O(1) random access
* O(n) insertion/deletion in middle
* Automatically resizes
* Not thread-safe

---

## 🎯 Most Used Functions (Remember These)

* `push_back`
* `pop_back`
* `size`
* `empty`
* `clear`
* `erase`
* `insert`
* `at`
* `front`
* `back`

---

## 🧠 One-line Exam Answer

> `std::vector` is a dynamic array that provides fast random access and automatic resizing.

---

```

---

If you want next, I can:
- Do **`map` / `unordered_map`**
- Do **`set` / `unordered_set`**
- Create **one-page STL cheat sheet**
- Add **time complexity table**
- Make **DSA-focused vector usage**

Just say 👍
```
