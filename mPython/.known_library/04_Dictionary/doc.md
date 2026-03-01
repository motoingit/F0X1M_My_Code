# Python Dictionary (`dict`) Documentation

## Overview

The `dict` type in Python is a built-in data structure that stores data in **key–value pairs**.  
It is implemented as a **hash table**, providing average-case constant time complexity for lookups, insertions, and deletions.

- Keys must be **immutable**
- Values can be of any type
- Insertion order is preserved (Python 3.7+)

---

## Creating Dictionaries

### 1. Using Literal Syntax

```python
d = {"name": "Moto", "age": 20}
