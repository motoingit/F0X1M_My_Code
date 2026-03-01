Here’s a **clean, ready-to-use Markdown (`.md`) file** that lists the **most popular and most-used functions from the C++ `<algorithm>` library**.
This is **practical-focused**, not exhaustive junk.

You can paste this directly into a file like `cpp_algorithm_cheatsheet.md`.

---

````md
# C++ `<algorithm>` Library – Commonly Used Functions

The `<algorithm>` header provides a collection of functions for searching, sorting, modifying, and querying containers.  
Most functions work on **iterator ranges**: `[begin, end)`.

---

## 🔹 Sorting & Rearranging

### `sort`
Sorts elements in ascending order.
```cpp
sort(v.begin(), v.end());
````

### `stable_sort`

Sorts while preserving relative order of equal elements.

```cpp
stable_sort(v.begin(), v.end());
```

### `partial_sort`

Sorts only the first `k` elements.

```cpp
partial_sort(v.begin(), v.begin()+k, v.end());
```

### `nth_element`

Places the nth element in correct position.

```cpp
nth_element(v.begin(), v.begin()+k, v.end());
```

### `reverse`

Reverses the range.

```cpp
reverse(v.begin(), v.end());
```

### `rotate`

Rotates elements.

```cpp
rotate(v.begin(), v.begin()+k, v.end());
```

---

## 🔹 Searching & Counting

### `find`

Finds first occurrence of a value.

```cpp
find(v.begin(), v.end(), x);
```

### `binary_search`

Checks if element exists (sorted range).

```cpp
binary_search(v.begin(), v.end(), x);
```

### `lower_bound`

First position ≥ value.

```cpp
lower_bound(v.begin(), v.end(), x);
```

### `upper_bound`

First position > value.

```cpp
upper_bound(v.begin(), v.end(), x);
```

### `equal_range`

Returns both lower and upper bound.

```cpp
equal_range(v.begin(), v.end(), x);
```

### `count`

Counts occurrences of a value.

```cpp
count(v.begin(), v.end(), x);
```

### `count_if`

Counts elements satisfying a condition.

```cpp
count_if(v.begin(), v.end(), pred);
```

---

## 🔹 Min / Max Operations

### `min`

Returns smaller of two values.

```cpp
min(a, b);
```

### `max`

Returns larger of two values.

```cpp
max(a, b);
```

### `min_element`

Returns iterator to smallest element.

```cpp
min_element(v.begin(), v.end());
```

### `max_element`

Returns iterator to largest element.

```cpp
max_element(v.begin(), v.end());
```

### `minmax_element`

Returns both min and max.

```cpp
minmax_element(v.begin(), v.end());
```

---

## 🔹 Modifying Sequences

### `copy`

Copies elements.

```cpp
copy(src.begin(), src.end(), dest.begin());
```

### `copy_if`

Copies elements satisfying condition.

```cpp
copy_if(v.begin(), v.end(), dest.begin(), pred);
```

### `fill`

Fills range with value.

```cpp
fill(v.begin(), v.end(), x);
```

### `replace`

Replaces values.

```cpp
replace(v.begin(), v.end(), oldVal, newVal);
```

### `replace_if`

Conditional replace.

```cpp
replace_if(v.begin(), v.end(), pred, newVal);
```

### `remove`

Removes value (logical removal).

```cpp
remove(v.begin(), v.end(), x);
```

### `remove_if`

Removes by condition.

```cpp
remove_if(v.begin(), v.end(), pred);
```

⚠️ Use with `erase()`:

```cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

---

## 🔹 Checking Conditions

### `all_of`

Checks if all satisfy condition.

```cpp
all_of(v.begin(), v.end(), pred);
```

### `any_of`

Checks if any satisfy condition.

```cpp
any_of(v.begin(), v.end(), pred);
```

### `none_of`

Checks if none satisfy condition.

```cpp
none_of(v.begin(), v.end(), pred);
```

### `is_sorted`

Checks if range is sorted.

```cpp
is_sorted(v.begin(), v.end());
```

---

## 🔹 Permutations

### `next_permutation`

Next lexicographical permutation.

```cpp
next_permutation(v.begin(), v.end());
```

### `prev_permutation`

Previous permutation.

```cpp
prev_permutation(v.begin(), v.end());
```

---

## 🔹 Numeric-like Utilities (non `<numeric>`)

### `accumulate` *(actually from `<numeric>` but widely used with algorithms)*

```cpp
accumulate(v.begin(), v.end(), 0);
```

---

## 🔹 Heap Operations

### `make_heap`

```cpp
make_heap(v.begin(), v.end());
```

### `push_heap`

```cpp
push_heap(v.begin(), v.end());
```

### `pop_heap`

```cpp
pop_heap(v.begin(), v.end());
```

### `sort_heap`

```cpp
sort_heap(v.begin(), v.end());
```

---

## 🔹 Set Operations (Sorted Ranges)

### `set_union`

### `set_intersection`

### `set_difference`

```cpp
set_union(a.begin(), a.end(), b.begin(), b.end(), out.begin());
```

---

## 📌 Key Notes

* Works on **iterators**
* Many algorithms require **sorted input**
* `remove` does NOT shrink container
* `<algorithm>` is **header-only**

---

## 🎯 Most Used in Practice

* `sort`
* `find`
* `count`
* `lower_bound`
* `upper_bound`
* `min_element`
* `max_element`
* `remove + erase`
* `all_of / any_of`

---

```

---

If you want, I can:
- Split this into **DSA-only** vs **STL-heavy**
- Add **time complexity table**
- Convert to **one-page cheat sheet**
- Add **examples per function**
- Do the same for `<numeric>`, `<vector>`, `<map>`

Just say 👍
```
