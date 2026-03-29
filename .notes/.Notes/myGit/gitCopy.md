# Git & GitHub Tutorial — Push Your First Project

A beginner-friendly guide to uploading your project from VS Code to GitHub.

---

## Part 1: Create a GitHub Repository

### Step 1: Access GitHub
Log in to your GitHub account at [github.com](https://github.com)

### Step 2: Create New Repository
Click the **`+`** icon in the top-right corner and select **New repository**

### Step 3: Configure Repository

- **Repository name:** Choose a descriptive name (e.g., `my-first-app`)
- **Description:** (Optional) Brief description of your project
- **Visibility:** 
  - **Public** — Anyone can view
  - **Private** — Restricted access

### Step 4: Important Configuration

**Do NOT initialize with:**
- README file
- .gitignore
- License

We need a completely empty repository for this workflow.

### Step 5: Create Repository
Click the green **Create repository** button

Keep this page open — you'll need the repository URL in the next steps.

---

## Part 2: Connect Your Project to GitHub

### Step 1: Open Your Project in VS Code

1. Launch VS Code
2. Go to **File → Open Folder**
3. Select your project's root directory

### Step 2: Open Integrated Terminal

Access the terminal via **Terminal → New Terminal** from the menu bar, or use:
- Windows/Linux: `Ctrl + ~`
- macOS: `Cmd + ~`

### Step 3: Initialize Git Repository

```bash
git init
```

This creates a hidden `.git` folder that tracks all changes in your project.

### Step 4: Stage Your Files

```bash
git add .
```

The `.` stages all files in the current directory and subdirectories.

### Step 5: Create Your First Commit

```bash
git commit -m "Initial commit"
```

The commit message should describe what's being saved. "Initial commit" is the standard first message.

### Step 6: Link to GitHub Repository

Return to your GitHub repository page and copy the URL from the **"…or push an existing repository from the command line"** section.

#### Set Remote URL

```bash
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git
```

**Replace with your actual GitHub URL**

#### Alternative: Update Existing Remote

If you need to change the remote URL:

```bash
git remote set-url origin https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git
```

Or remove and re-add:

```bash
git remote remove origin
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPO-NAME.git
```

### Step 7: Push to GitHub

First, check your current branch name:

```bash
git branch
```

Then push using the appropriate branch name (usually `main` or `master`):

```bash
git push -u origin main
```

Or if your branch is named `master`:

```bash
git push -u origin master
```

**Flag explanation:**
- `-u` — Sets upstream tracking (only needed once)
- After this, you can use just `git push` in the future

You may be prompted to authenticate with GitHub. After completion, refresh your repository page to see your files.

---

## Useful Git Commands

### Verify Remote URL

```bash
git remote -v
```

### View All Branches

```bash
git branch -a
```

### Create and Switch to a New Branch

```bash
git checkout -b main
```

Or for master:

```bash
git checkout -b master
```

---

## Daily Workflow

Once your project is on GitHub, use this simple workflow for updates:

### 1. Make Changes
Edit your files and save them in VS Code

### 2. Stage Changes
```bash
git add .
```

### 3. Commit Changes
```bash
git commit -m "Descriptive message about what changed"
```

### 4. Push to GitHub
```bash
git push
```

---

## Alternative: Use VS Code GUI

VS Code provides a graphical interface for Git operations:

1. Click the **Source Control** icon in the left sidebar (branch icon)
2. Review changed files
3. Stage changes by clicking the **`+`** icon
4. Write a commit message in the text box
5. Click the **checkmark** to commit
6. Click **`⋯`** (more actions) → **Push** to upload

---

## Common Issues

### Authentication Required
GitHub may prompt for credentials. Use a Personal Access Token instead of your password for HTTPS authentication.

### Branch Name Mismatch
If you encounter errors about `main` vs `master`, check your branch name with `git branch` and use the correct one in push commands.

### Remote Already Exists
If you see "remote origin already exists," use `git remote remove origin` before adding a new remote.

---

## Next Steps

- Learn about **branches** for feature development
- Explore **pull requests** for collaboration
- Set up a `.gitignore` file to exclude unwanted files
- Add a README.md to document your project

---

**Happy coding!** �