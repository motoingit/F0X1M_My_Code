## 🌿 Git Branch Commands

### View current branch
```bash
git branch
```

Current branch is marked with `*`.

---

### Create a new branch

```bash
git branch newBranch
```

---

### Create and switch to a new branch

```bash
git checkout -b newBranch
```

or (modern Git)

```bash
git switch -c newBranch
```

> ❌ `git checkout -n newain` is incorrect.

---

### Switch to an existing branch

```bash
git checkout branchName
```

or

```bash
git switch branchName
```

---

### Push a branch to GitHub

First time:

```bash
git push -u origin branchName
```

After the first push:

```bash
git push
```

> `-u` sets the upstream branch so future pushes only require `git push`.

---

### View all branches

```bash
git branch
```

Remote branches:

```bash
git branch -r
```

All branches:

```bash
git branch -a
```

---

### Delete a local branch

```bash
git branch -d branchName
```

Force delete:

```bash
git branch -D branchName
```

---

### Delete a remote branch

```bash
git push origin --delete branchName
```
