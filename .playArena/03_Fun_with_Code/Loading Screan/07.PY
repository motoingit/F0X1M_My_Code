from tqdm import tqdm
import time

for i in tqdm(range(100), desc="Downloading", unit="MB"):
    time.sleep(0.05)  # simulate work
