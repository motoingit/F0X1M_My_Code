# 🐍 Minimal Python Installation Guide (Using `uv`)

A clean and modern Python setup using **uv** as the only Python manager.

---

# 1. Check Existing Python Installations

Check installed Python versions:

```powershell
py --list
```

Check which Python is being used:

```powershell
where.exe python
```

Check current Python version:

```powershell
python --version
```

---

# 2. Remove Existing Python (Optional)

List installed Python packages:

```powershell
winget list Python
```

Uninstall Python:

```powershell
winget uninstall "Python 3.14.6"
```

or

```powershell
winget uninstall 9NCVDN91XZQP
```

> Replace the package ID/version with your installed version if different.

---

# 3. Install `uv`

Search package:

```powershell
winget search uv
```

Install:

```powershell
winget install --id astral-sh.uv -e
```

Verify installation:

```powershell
uv --version
```

---

# 4. Install Python

Install the latest Python 3.13:

```powershell
uv python install 3.13
```

or install a specific version:

```powershell
uv python install 3.13.14
```

---

# 5. Verify Installation

List available Python versions:

```powershell
uv python list
```

Run Python through `uv`:

```powershell
uv run python --version
```

Check executable:

```powershell
uv run python -c "import sys; print(sys.executable)"
```

---

# 6. Create a Project

```powershell
mkdir my-project
cd my-project
```

Initialize project:

```powershell
uv init
```

Create virtual environment:

```powershell
uv venv
```

---

# 7. Install Packages

Recommended:

```powershell
uv add requests
uv add numpy
uv add fastapi
```

Or use pip-compatible commands:

```powershell
uv pip install requests
```

---

# 8. Run Python

```powershell
uv run main.py
```

or

```powershell
uv run python main.py
```

---

# 9. Useful Commands

Install Python

```powershell
uv python install 3.13
```

List installed Python versions

```powershell
uv python list
```

Remove a Python version

```powershell
uv python uninstall 3.13
```

Create virtual environment

```powershell
uv venv
```

Add dependency

```powershell
uv add requests
```

Remove dependency

```powershell
uv remove requests
```

Synchronize dependencies

```powershell
uv sync
```

Run script

```powershell
uv run main.py
```

Run Python

```powershell
uv run python
```

List installed packages

```powershell
uv pip list
```

Freeze dependencies

```powershell
uv pip freeze
```

---

# Project Structure

```
my-project/
│
├── .venv/
├── pyproject.toml
├── uv.lock
├── main.py
└── README.md
```

---

# Recommended Workflow

```powershell
# Install Python (once)
uv python install 3.13

# Create project
uv init

# Create virtual environment
uv venv

# Install dependencies
uv add requests

# Run project
uv run main.py
```

---

# Summary

Instead of:

| Traditional | `uv` |
|-------------|-------|
| Install Python manually | `uv python install 3.13` |
| `python -m venv .venv` | `uv venv` |
| `pip install requests` | `uv add requests` |
| `pip uninstall requests` | `uv remove requests` |
| `python main.py` | `uv run main.py` |
| `pip list` | `uv pip list` |
| `pip freeze` | `uv pip freeze` |

> **Rule of thumb:** If it's related to Python, start with `uv`.
