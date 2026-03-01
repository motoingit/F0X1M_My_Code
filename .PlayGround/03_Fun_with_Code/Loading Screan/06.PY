
from rich.progress import Progress, BarColumn, DownloadColumn, TextColumn, TimeRemainingColumn, TransferSpeedColumn
import time
import random

# simulate downloading a file
total_size = 39 * 1024 * 1024  # 39 MB

with Progress(
    TextColumn("[bold blue]Downloading opencv_python[/]", justify="left"),
    BarColumn(),
    DownloadColumn(),
    TransferSpeedColumn(),
    TimeRemainingColumn(),
) as progress:

    task = progress.add_task("", total=total_size)
    
    while not progress.finished:
        # simulate random download chunk
        chunk = random.randint(1024 * 200, 1024 * 500)  # 200-500 KB
        progress.update(task, advance=chunk)
        time.sleep(0.1)
