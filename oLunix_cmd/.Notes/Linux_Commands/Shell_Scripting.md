
---

# 🐚 Shell Scripting 101: Automation Essentials

A shell script is simply a text file containing a list of commands that the shell (usually `bash`) executes in order. It’s like a "recipe" for your computer.

## 1. The Anatomy of a Script

### The Shebang (`#!`)

The very first line of your script tells Linux which "interpreter" to use to read the file.

```bash
#!/bin/bash

```

* **Why?** Without this, the system might try to run your script using a different shell (like `sh` or `zsh`), which could cause errors.

### Making it Executable

By default, new files don't have permission to "run" as programs.

1. **Change Permission:** `chmod +x myscript.sh`
2. **Run it:** `./myscript.sh` (The `./` tells Linux to look in the *current* folder).

---

## 2. Variables & Input

Variables store data for later use. **Crucial Rule:** Do not put spaces around the `=` sign.

```bash
# Correct
NAME="Skywalker" 
# Incorrect (will throw an error)
NAME = "Skywalker" 

echo "The Force is strong with $NAME"

```

### Dynamic Input

Use `read` to make your scripts interactive:

```bash
echo "What is your mission?"
read MISSION
echo "Beginning mission: $MISSION..."

```

---

## 3. Logic & Decision Making

### If-Else Statements

In Bash, the syntax is specific. You **must** have spaces inside the square brackets `[ ]`.

```bash
if [ $age -ge 18 ]; then
    echo "Access Granted."
else
    echo "Access Denied."
fi

```

**Cheat Sheet for Comparisons:**

* `-eq` / `-ne`: Equal / Not Equal
* `-gt` / `-lt`: Greater Than / Less Than
* `-ge` / `-le`: Greater or Equal / Less or Equal

---

## 4. Repeating Tasks (Loops)

### For Loops

Best for iterating over a known list or range.

```bash
# Renaming multiple files or backing up items
for file in *.txt; do
    cp "$file" "$file.bak"
done

```

### While Loops

Best for running until a specific condition changes.

```bash
timer=5
while [ $timer -gt 0 ]; do
    echo "Self-destruct in $timer..."
    sleep 1
    ((timer--))
done

```

---

## 5. Pro-Tip: Command Substitution

You can save the **output** of a Linux command into a variable using `$(command)`.

```bash
CURRENT_DATE=$(date +%F)
echo "Today's backup date is: $CURRENT_DATE"

```

---

## Summary: Scripting Workflow

| Step | Action | Command |
| --- | --- | --- |
| **1** | Create file | `touch backup.sh` |
| **2** | Add Shebang | `#!/bin/bash` (Top line) |
| **3** | Write Code | Add your commands and logic. |
| **4** | Set Permissions | `chmod +x backup.sh` |
| **5** | Execute | `./backup.sh` |

---

Would you like me to create a guide on **Crontab**, which allows you to schedule these scripts to run automatically every day or hour?
