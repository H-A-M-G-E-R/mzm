import argparse
from io import BufferedReader
import json
from pathlib import Path

rom: BufferedReader = open("data_new/common_sprites.gfx", "rb")
entry_bytes = rom.read()

# all values in the .inc are unsigned
entry_values = []
for i in range(0, len(entry_bytes), 4):
    entry_values.append(int.from_bytes(entry_bytes[i:i+4], byteorder='little', signed=False))
with open("data_new/common_sprites.gfx.inc", "w") as f:
    f.write(",".join([str(v)+"u" for v in entry_values]))
