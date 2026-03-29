##########################################
import time
import sys

total = 50
for i in range(total + 1):
    percent = (i / total) * 100
    bar = '█' * i + '-' * (total - i)
    sys.stdout.write(f"\r|{bar}| {percent:.2f}%")
    sys.stdout.flush()
    time.sleep(0.1)

##########################################
