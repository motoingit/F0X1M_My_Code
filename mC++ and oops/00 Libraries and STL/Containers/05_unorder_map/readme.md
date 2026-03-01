Perfect 👍
Here’s a **clean, practical Markdown (`.md`) cheat sheet** for **`std::unordered_map`**, focused on **most-used functions**, exactly like your vector one.

You can paste this directly into
👉 `cpp_unordered_map_cheatsheet.md`

---

````md
# C++ `std::unordered_map` – Most Used Functions

`std::unordered_map` is a **hash table–based associative container** that stores key–value pairs with **average O(1)** time complexity for search, insert, and delete.

Header required:
```cpp
#include <unordered_map>
````

---

## 🔹 Declaration & Initialization

### Declare unordered_map

```cpp
unordered_map<int, int> mp;
```

### Initialize with values

```cpp
unordered_map<string, int> mp = {
    {"apple", 3},
    {"banana", 5}
};
```

---

## 🔹 Insertion Methods

### `operator[]`

Inserts key if not present.

```cpp
mp[1] = 10;
```

### `insert()`

```cpp
mp.insert({2, 20});
```

### `emplace()`

Constructs in-place (faster).

```cpp
mp.emplace(3, 30);
```

---

## 🔹 Accessing Elements

### Access using key

```cpp
int val = mp[1];
```

⚠️ Creates key if not present.

### `at()`

Safe access (throws exception).

```cpp
mp.at(1);
```

---

## 🔹 Searching

### `find()`

```cpp
auto it = mp.find(key);
if (it != mp.end()) {
    cout << it->second;
}
```

### `count()`

```cpp
if (mp.count(key)) {
    // key exists
}
```

---

## 🔹 Deletion

### `erase(key)`

```cpp
mp.erase(key);
```

### `erase(iterator)`

```cpp
mp.erase(it);
```

### `clear()`

```cpp
mp.clear();
```

---

## 🔹 Size & Capacity

### `size()`

```cpp
mp.size();
```

### `empty()`

```cpp
mp.empty();
```

### `bucket_count()`

```cpp
mp.bucket_count();
```

### `load_factor()`

```cpp
mp.load_factor();
```

### `rehash()`

```cpp
mp.rehash(50);
```

---

## 🔹 Iteration

### Range-based loop

```cpp
for (auto &p : mp) {
    cout << p.first << " " << p.second << endl;
}
```

### Iterator-based

```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " " << it->second;
}
```

⚠️ Order is **NOT guaranteed**.

---

## 🔹 Checking Presence Safely

### Preferred way

```cpp
if (mp.find(key) != mp.end()) {
    // exists
}
```

❌ Avoid:

```cpp
if (mp[key])  // may insert key unintentionally
```

---

## 🔹 Updating Values

```cpp
mp[key] += 1;
```

Common use: **frequency counting**.

---

## 🔹 Custom Hash (Advanced)

```cpp
unordered_map<pair<int,int>, int, customHash> mp;
```

---

## 🔹 Common Use Cases

* Frequency counting
* Hash-based lookup
* Cache implementation
* Counting duplicates
* Mapping IDs to values

---

## 🔹 Time Complexity (Average Case)

| Operation  | Time |
| ---------- | ---- |
| Insert     | O(1) |
| Search     | O(1) |
| Delete     | O(1) |
| Worst Case | O(n) |

---

## 🔹 unordered_map vs map

| Feature        | unordered_map | map            |
| -------------- | ------------- | -------------- |
| Ordering       | ❌ No          | ✅ Yes          |
| Search         | O(1) avg      | O(log n)       |
| Implementation | Hash table    | Red-black tree |

---

## 🎯 Most Used Functions (Remember These)

* `operator[]`
* `insert`
* `emplace`
* `find`
* `count`
* `erase`
* `size`
* `clear`

---

## 🧠 One-line Exam Answer

> `std::unordered_map` stores key–value pairs using hashing and provides average constant-time operations.

---

```

---

If you want next, I can:
- Do **`map` vs `unordered_map` (deep)**
- Create **DSA patterns using unordered_map**
- Make **STL full cheatsheet**
- Add **examples for interview problems**

Just say 👍
```
