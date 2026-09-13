import argparse
from io import BufferedReader
import json
from pathlib import Path

rom: BufferedReader = open("data_new/charging_beam.gfx", "rb")
entry_bytes = rom.read()

# all values in the .inc are unsigned
entry_values = []
for i in range(0, len(entry_bytes)):
    entry_values.append(entry_bytes[i])
with open("data_new/charging_beam.gfx.inc", "w") as f:
    f.write(",".join([str(v)+"u" for v in entry_values]))
