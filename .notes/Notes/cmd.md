
# Almost everything is gone.

rm -rf ./* ./.* 2>/dev/null

Get-Location
Get-ChildItem -Force | Remove-Item -Recurse -Force

# Execution time

``` ps1
Measure-Command { java Main }
```

# 🔧 File & Directory Navigation

* `pwd` → Print current working directory
* `ls` → List files (`ls -la` for hidden + details)
* `cd folder/` → Change directory
* `cd ..` → Go one directory up
* `cd ~` → Go to home
