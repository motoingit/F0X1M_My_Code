# loading_ui.py

import time
import sys
import random
from tqdm import tqdm
from rich.progress import (
    Progress,
    BarColumn,
    DownloadColumn,
    TextColumn,
    TimeRemainingColumn,
    TransferSpeedColumn,
)


class LoadingUI:
    """
    Enterprise-grade console loading animations.
    All loaders are modular and reusable.
    """

    # ------------------------------
    # 1. TQDM Progress Bar
    # ------------------------------
    def tqdm_loader(self, total=100, delay=0.05):
        """
        Simple tqdm-based progress bar
        Source: :contentReference[oaicite:0]{index=0}
        """
        for _ in tqdm(range(total), desc="Processing", unit="step"):
            time.sleep(delay)

    # ------------------------------
    # 2. Rich Download Loader
    # ------------------------------
    def rich_loader(self, total_size_mb=39):
        """
        Advanced rich progress bar (download style)
        Source: :contentReference[oaicite:1]{index=1}
        """
        total_size = total_size_mb * 1024 * 1024

        with Progress(
            TextColumn("[bold blue]Downloading file[/]"),
            BarColumn(),
            DownloadColumn(),
            TransferSpeedColumn(),
            TimeRemainingColumn(),
        ) as progress:

            task = progress.add_task("", total=total_size)

            while not progress.finished:
                chunk = random.randint(1024 * 200, 1024 * 500)
                progress.update(task, advance=chunk)
                time.sleep(0.1)

    # ------------------------------
    # 3. Manual ASCII Progress Bar
    # ------------------------------
    def ascii_loader(self, total=50, delay=0.1):
        """
        Custom CLI progress bar (C++ style converted)
        Source: :contentReference[oaicite:2]{index=2}
        """
        for i in range(total + 1):
            percent = (i / total) * 100
            bar = '█' * i + '-' * (total - i)
            sys.stdout.write(f"\r|{bar}| {percent:.2f}%")
            sys.stdout.flush()
            time.sleep(delay)
        print()

    # ------------------------------
    # 4. Typing Effect (C++ → Python)
    # ------------------------------
    def typing_effect(self, text="Loading...", delay=0.05):
        """
        Simulates typing animation (converted from typical C++ logic)
        """
        for char in text:
            sys.stdout.write(char)
            sys.stdout.flush()
            time.sleep(delay)
        print()

    # ------------------------------
    # 5. Spinner Loader (C++ style)
    # ------------------------------
    def spinner_loader(self, duration=3):
        """
        Classic rotating spinner animation
        """
        spinner = ['|', '/', '-', '\\']
        end_time = time.time() + duration
        i = 0

        while time.time() < end_time:
            sys.stdout.write(f"\rLoading {spinner[i % len(spinner)]}")
            sys.stdout.flush()
            time.sleep(0.1)
            i += 1

        print("\rDone!     ")

    # ------------------------------
    # 6. Dot Animation
    # ------------------------------
    def dot_loader(self, duration=3):
        """
        Animated dots (C++ equivalent)
        """
        end_time = time.time() + duration

        while time.time() < end_time:
            for dots in ["", ".", "..", "..."]:
                sys.stdout.write(f"\rLoading{dots}")
                sys.stdout.flush()
                time.sleep(0.5)

        print("\rCompleted   ")


# ------------------------------
# Example Usage (Demo)
# ------------------------------
if __name__ == "__main__":
    ui = LoadingUI()

    print("\n--- Typing Effect ---")
    ui.typing_effect("Initializing system...")

    print("\n--- ASCII Loader ---")
    ui.ascii_loader()

    print("\n--- Spinner ---")
    ui.spinner_loader()

    print("\n--- Dot Loader ---")
    ui.dot_loader()

    print("\n--- TQDM Loader ---")
    ui.tqdm_loader()

    print("\n--- Rich Loader ---")
    ui.rich_loader()
