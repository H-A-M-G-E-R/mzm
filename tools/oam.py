#python3 tools/oam.py ../mzm.gba 0x339aa8
import argparse
from typing import BinaryIO
from copy import deepcopy
from PIL import Image
from labels import extract_labels


DIMS = [[(8,8),(16,16),(32,32),(64,64)],[(16,8),(32,8),(32,16),(64,32)],[(8,16),(8,32),(16,32),(32,64)]]


DIMS_STR = [
    "OAM_DIMS_8x8",
    "OAM_DIMS_16x16",
    "OAM_DIMS_32x32",
    "OAM_DIMS_64x64",

    "OAM_DIMS_16x8",
    "OAM_DIMS_32x8",
    "OAM_DIMS_32x16",
    "OAM_DIMS_64x32",

    "OAM_DIMS_8x16",
    "OAM_DIMS_8x32",
    "OAM_DIMS_16x32",
    "OAM_DIMS_32x64",
]

FLIPS = [
    "OAM_NO_FLIP",
    "OAM_X_FLIP",
    "OAM_Y_FLIP",
    "OAM_XY_FLIP"
]

MODES = [
    "OAM_OBJ_MODE_SEMI_TRANSPARENT",
    "OAM_OBJ_MODE_WINDOW"
]


class OAMEntry:
    def __init__(self, attrs: list[int]):
        assert len(attrs) == 3
        attr0, attr1, attr2 = attrs
        self.x = attr1 & 0x1FF
        if self.x >= 0x100:
            self.x -= 0x200
        self.y = attr0 & 0xFF
        if self.y >= 0x80:
            self.y -= 0x100
        self.obj_shape = attr0 >> 14
        self.obj_size = attr1 >> 14
        self.dims = (self.obj_shape << 2) | self.obj_size
        self.flip = (attr1 >> 12) & 3
        self.pal = attr2 >> 12
        self.prio = (attr2 >> 10) & 3
        self.tile = attr2 & 0x3FF
        self.mode = (attr0 >> 10) & 3


    def _single_entry(self) -> str:
        # Get macro parameters
        param_strs = self._get_param_strs()
        ps = ", ".join(param_strs)
        mode = "" if len(param_strs) == 7 else "_MODE"
        return f"OAM_ENTRY{mode}({ps})"


    def _get_param_strs(self) -> str:
        param_strs = [str(self.x), str(self.y), DIMS_STR[self.dims], FLIPS[self.flip], f"0x{self.tile:x}", str(self.pal), str(self.prio)]
        if self.mode > 0:
            param_strs.append(MODES[self.mode - 1])
        return param_strs


def build_gfx(fp: str) -> list[list[int]]:
    image = Image.open(fp)
    out = []
    for y in range(0, image.height, 8):
        for x in range(0, image.width, 8):
            out.append([pixel & 0xF for pixel in image.crop((x, y, x + 8, y + 8)).get_flattened_data()])
    return out


orig_gfx = build_gfx("../common_tiles_3.png")
new_gfx = build_gfx("../common_tiles_optimized.png")


def convert_entry(entry: OAMEntry) -> list[OAMEntry]:
    def radial_16x16(entry: OAMEntry) -> list[OAMEntry]:
        new_entry = deepcopy(entry)
        new_entry.dims = 0
        new_entry2 = deepcopy(new_entry)
        new_entry2.x += 8
        new_entry2.flip = 1
        new_entry3 = deepcopy(new_entry)
        new_entry3.y += 8
        new_entry3.flip = 2
        new_entry4 = deepcopy(new_entry)
        new_entry4.x += 8
        new_entry4.y += 8
        new_entry4.flip = 3
        return [new_entry, new_entry2, new_entry3, new_entry4]

    # Special cases
    # Shooting beam
    if entry.tile in [0x180, 0x182]:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x90
        return [new_entry]

    # sParticleChargingBeamBeginOam_Frame0/1/6/10/16/sParticleChargingBeamChargedOam_Frame1
    if entry.tile in [0x97, 0x95, 0x99, 0x9B]:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x90
        return [new_entry]

    # sParticleChargingBeamBeginOam_Frame2
    if entry.tile in [0x166]:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x90
        return [new_entry]

    # sParticleChargingBeamBeginOam_Frame6/10/16, sParticleChargingBeamChargedOam_Frame1
    if entry.tile in [0x90, 0xb0, 0x91, 0x93]:
        return []

    # Other beam hit
    if entry.tile in [0x1c9, 0x145, 0x149, 0x147]:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x92
        return [new_entry]

    # sParticleHittingSomethingWithNormalBeamOam_Frame3
    if entry.tile == 0x1e9:
        new_entry = deepcopy(entry)
        new_entry.tile = 0xb2
        return [new_entry]

    # sParticleHittingSomethingWithLongBeamOam_Frame3
    if entry.tile == 0x109:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x93
        return [new_entry]

    # Big explosions
    if entry.tile == 0x19a:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x194
        new_entry.flip ^= 2
        return [new_entry]

    if entry.tile == 0x19c:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x198
        new_entry.flip ^= 2
        return [new_entry]

    if entry.tile == 0x19e:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x19c
        new_entry.flip ^= 2
        return [new_entry]

    # Missile explosion
    if entry.tile == 0xd2:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x96
        new_entry.dims = 0
        new_entry2 = deepcopy(new_entry)
        new_entry2.y += 8
        new_entry2.flip ^= 2
        return [new_entry, new_entry2]

    if entry.tile == 0xd3:
        new_entry = deepcopy(entry)
        new_entry.tile = 0xb6
        return radial_16x16(new_entry)

    # tiles that look identical
    if entry.tile == 0x18f:
        return [deepcopy(entry)]

    if entry.tile == 0x1d4:
        new_entry = deepcopy(entry)
        new_entry.tile = 0x150
        return [new_entry]

    # Normal case
    offset_tile = entry.tile - 0x40
    # Only check for the upper-left tile
    if orig_gfx[offset_tile] in new_gfx:
        new_entry = deepcopy(entry)
        new_entry.tile = new_gfx.index(orig_gfx[offset_tile]) + 0x40
        return [new_entry]
    else:
        # No match found, return copy of original
        return [deepcopy(entry)]


def dump_oam_frame(rom: BinaryIO, addr: int) -> list[OAMEntry]:
    entries = []
    rom.seek(addr)
    # Get count
    count_val = _read_16(rom)
    count = count_val & 0xFFF
    # Get each entry
    for _ in range(count):
        attrs = [_read_16(rom) for _ in range(3)]
        entries.extend(convert_entry(OAMEntry(attrs)))
    return entries


def print_oam_frame(frame: list[OAMEntry], name: str) -> None:
    INDENT = " " * 4
    if name is None:
        name = f"sOamFrame_{addr:x}"
    lines = [f"const u16 {name}[OAM_DATA_SIZE({len(frame)})] = {{"]
    lines.append(INDENT + _count_str(len(frame)) + ",")
    # Get each entry
    for i in range(len(frame)):
        es = frame[i]._single_entry()
        if i < len(frame) - 1:
            lines.append(INDENT + es + ",")
        else:
            lines.append(INDENT + es)
    lines.append("};")
    print("\n".join(lines))


def _read_16(rom: BinaryIO) -> int:
    b = rom.read(2)
    return b[0] | (b[1] << 8)


def _count_str(count: int) -> str:
    cs = str(count & 0xFFF)
    if count & (1 << 12):
        cs += " | ARM_CANNON_OAM_ORDER_IN_FRONT"
    elif count & (1 << 13):
        cs += " | ARM_CANNON_OAM_ORDER_BEHIND"
    return cs


if __name__ == "__main__":
    frames_to_dump = []
    labels = extract_labels()
    for (k, v) in labels.items():
        #if k >= 0x08339aa8 and k < 0x0833bd34 and "_Frame" in v:
        if k >= 0x08326ca8 and k < 0x0832ba08 and "_Frame" in v:
        #if k >= 0x0833bd34 and k < 0x0833d794 and "_Frame" in v:
        #if k >= 0x082b25c8 and k < 0x082b2728 and "_Frame" in v:
        #if k >= 0x083126c6 and k < 0x08312928 and "_Frame" in v:
            frames_to_dump.append((k, v))

    with open("mzm_us_baserom.gba", "rb") as f:
        for frame_to_dump in frames_to_dump:
            frame = dump_oam_frame(f, frame_to_dump[0] & 0x7ffffff)
            print_oam_frame(frame, frame_to_dump[1])
            print()

        for frame_to_dump in frames_to_dump:
            frame = dump_oam_frame(f, frame_to_dump[0] & 0x7ffffff)
            print(f"extern const u16 {frame_to_dump[1]}[OAM_DATA_SIZE({len(frame)})];\n")
