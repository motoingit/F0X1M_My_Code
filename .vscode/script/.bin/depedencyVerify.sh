#!/bin/bash

# ============================================================
#   system_info_report.sh
#   Generates a full system & program version report as .txt
# ============================================================

OUTPUT_FILE="system_report_$(date +%Y%m%d_%H%M%S).txt"

# Helper: print a section header
section() {
    echo "" >> "$OUTPUT_FILE"
    echo "============================================================" >> "$OUTPUT_FILE"
    echo "  $1" >> "$OUTPUT_FILE"
    echo "============================================================" >> "$OUTPUT_FILE"
}

# Helper: run a command and capture output safely
check() {
    local label="$1"
    local cmd="$2"
    printf "%-30s : " "$label" >> "$OUTPUT_FILE"
    if command -v $(echo "$cmd" | awk '{print $1}') &>/dev/null; then
        eval "$cmd" 2>/dev/null >> "$OUTPUT_FILE" || echo "Error running command" >> "$OUTPUT_FILE"
    else
        echo "Not installed" >> "$OUTPUT_FILE"
    fi
}

# ── Header ───────────────────────────────────────────────────
echo "============================================================" > "$OUTPUT_FILE"
echo "   SYSTEM & PROGRAM VERSION REPORT" >> "$OUTPUT_FILE"
echo "   Generated : $(date)" >> "$OUTPUT_FILE"
echo "   Hostname  : $(hostname)" >> "$OUTPUT_FILE"
echo "============================================================" >> "$OUTPUT_FILE"

# ── 1. OS & Kernel ───────────────────────────────────────────
section "OPERATING SYSTEM"
check "OS Name"          "uname -s"
check "OS Version"       "uname -r"
check "Full OS Info"     "uname -a"
check "Distro Info"      "cat /etc/os-release | head -5"
check "Uptime"           "uptime -p"

# ── 2. Hardware ──────────────────────────────────────────────
section "HARDWARE"
check "CPU Model"        "lscpu | grep 'Model name' | sed 's/Model name:\s*//'"
check "CPU Cores"        "nproc --all"
check "Architecture"     "uname -m"
check "Total RAM"        "free -h | awk '/^Mem:/{print \$2}'"
check "Available RAM"    "free -h | awk '/^Mem:/{print \$7}'"
check "Disk Usage"       "df -h --total | tail -1"

# ── 3. Shell & Terminal ──────────────────────────────────────
section "SHELL & TERMINAL"
check "Current Shell"    "echo $SHELL"
check "Bash Version"     "bash --version | head -1"
check "Zsh Version"      "zsh --version"
check "Fish Version"     "fish --version"

# ── 4. Programming Languages ─────────────────────────────────
section "PROGRAMMING LANGUAGES"
check "Python"           "python --version"
check "Python3"          "python3 --version"
check "Python3 Path"     "which python3"
check "pip"              "pip --version"
check "pip3"             "pip3 --version"
check "Node.js"          "node --version"
check "npm"              "npm --version"
check "npx"              "npx --version"
check "yarn"             "yarn --version"
check "Bun"              "bun --version"
check "Deno"             "deno --version | head -1"
check "Java"             "java -version 2>&1 | head -1"
check "javac"            "javac -version"
check "Kotlin"           "kotlin -version 2>&1 | head -1"
check "Scala"            "scala -version 2>&1 | head -1"
check "Ruby"             "ruby --version"
check "gem"              "gem --version"
check "Bundler"          "bundle --version"
check "Go"               "go version"
check "Rust"             "rustc --version"
check "Cargo"            "cargo --version"
check "PHP"              "php --version | head -1"
check "Composer"         "composer --version"
check "Perl"             "perl --version | head -2 | tail -1"
check "Lua"              "lua -v 2>&1"
check "R"                "R --version | head -1"
check "Swift"            "swift --version 2>&1 | head -1"
check "Dart"             "dart --version"
check "Elixir"           "elixir --version | head -1"
check "Erlang"           "erl -eval 'erlang:display(erlang:system_info(otp_release)), halt().' -noshell 2>/dev/null"
check "Julia"            "julia --version"
check "Haskell (GHC)"    "ghc --version"
check "Cabal"            "cabal --version | head -1"
check "Stack"            "stack --version | head -1"
check "C Compiler (gcc)" "gcc --version | head -1"
check "Clang"            "clang --version | head -1"
check "Make"             "make --version | head -1"
check "CMake"            "cmake --version | head -1"
check ".NET SDK"         "dotnet --version"
check "Mono"             "mono --version | head -1"

# ── 5. Version Control ───────────────────────────────────────
section "VERSION CONTROL"
check "Git"              "git --version"
check "Git Config User"  "git config --global user.name"
check "Git Config Email" "git config --global user.email"
check "SVN"              "svn --version | head -1"
check "Mercurial"        "hg --version | head -1"

# ── 6. Databases ─────────────────────────────────────────────
section "DATABASES"
check "MySQL"            "mysql --version"
check "MariaDB"          "mariadb --version"
check "PostgreSQL"       "psql --version"
check "SQLite"           "sqlite3 --version"
check "MongoDB"          "mongod --version | head -1"
check "Redis"            "redis-server --version"
check "Cassandra"        "cassandra -v 2>/dev/null"

# ── 7. Containers & Virtualisation ───────────────────────────
section "CONTAINERS & VIRTUALISATION"
check "Docker"           "docker --version"
check "Docker Compose"   "docker compose version"
check "Podman"           "podman --version"
check "Kubernetes (kubectl)" "kubectl version --client --short 2>/dev/null | head -1"
check "Minikube"         "minikube version | head -1"
check "Helm"             "helm version --short"
check "Vagrant"          "vagrant --version"
check "VirtualBox"       "vboxmanage --version"

# ── 8. Cloud & DevOps Tools ──────────────────────────────────
section "CLOUD & DEVOPS TOOLS"
check "AWS CLI"          "aws --version"
check "Azure CLI"        "az --version 2>/dev/null | head -1"
check "Google Cloud CLI" "gcloud --version 2>/dev/null | head -1"
check "Terraform"        "terraform --version | head -1"
check "Ansible"          "ansible --version | head -1"
check "Jenkins CLI"      "jenkins-cli --version 2>/dev/null"

# ── 9. Web Servers & Networking ──────────────────────────────
section "WEB SERVERS & NETWORKING"
check "Nginx"            "nginx -v 2>&1"
check "Apache"           "apache2 -v 2>&1 | head -1"
check "curl"             "curl --version | head -1"
check "wget"             "wget --version | head -1"
check "OpenSSL"          "openssl version"
check "SSH"              "ssh -V 2>&1"

# ── 10. Text Editors & IDEs ──────────────────────────────────
section "TEXT EDITORS & IDEs"
check "Vim"              "vim --version | head -1"
check "Neovim"           "nvim --version | head -1"
check "Emacs"            "emacs --version | head -1"
check "Nano"             "nano --version | head -1"
check "VS Code"          "code --version | head -1"

# ── 11. Package Managers ─────────────────────────────────────
section "PACKAGE MANAGERS (SYSTEM)"
check "apt"              "apt --version | head -1"
check "apt-get"          "apt-get --version | head -1"
check "dpkg"             "dpkg --version | head -1"
check "snap"             "snap --version"
check "flatpak"          "flatpak --version"
check "brew (Homebrew)"  "brew --version | head -1"
check "dnf"              "dnf --version | head -1"
check "yum"              "yum --version | head -1"
check "pacman"           "pacman --version | head -1"

# ── 12. System Environment ───────────────────────────────────
section "SYSTEM ENVIRONMENT VARIABLES"
echo "" >> "$OUTPUT_FILE"
echo "PATH=$PATH" >> "$OUTPUT_FILE"
echo "HOME=$HOME" >> "$OUTPUT_FILE"
echo "USER=$USER" >> "$OUTPUT_FILE"
echo "LANG=$LANG" >> "$OUTPUT_FILE"
echo "TERM=$TERM" >> "$OUTPUT_FILE"

# ── Footer ───────────────────────────────────────────────────
echo "" >> "$OUTPUT_FILE"
echo "============================================================" >> "$OUTPUT_FILE"
echo "   END OF REPORT — $(date)" >> "$OUTPUT_FILE"
echo "============================================================" >> "$OUTPUT_FILE"

echo ""
echo "✅  Report saved to: $OUTPUT_FILE"
echo ""
