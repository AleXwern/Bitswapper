# Bitswapper
Small utility tool I made to mess with image bits. I had some images that were in RABG format and wanted to shift them to RGBA. <br>
Also compiled SDL2 in command line on Windows. Easier then I initially thought.

**Linux/UNIX**<br>
Makefile is not prepared for SDL2 and half of the Assembly code breaks because function parameter handling but you need Make, GCC, NASM and SDL2. In order: compiling, C, Assembly and graphical interface.

**Win64**<br>
You need Make, GCC from MinGW, NASM and SDL2 and then it should compile from command prompt with make command

**Usage**<br>
Executable is bitswapper(.exe) and for now it looks for LD.bmp from repo root. The image needs to be at least 256x256 because I'm lazy and just memcopying the image to screen and smaller images break.<br>

| Key        | Function                                                                                  |
| ---------- | :---------------------------------------------------------------------------------------: |
| Left       | Rotates all bytes left by 1: RGBA -> GBAR                                                 |
| Right      | Rotates all bytes right by 1: RGBA -> ARGB                                                |
| Up/Down    | Shifts bytes around from last<->first: RGBA -> ABGR                                       |
| E          | Exports the current image to out.bmp                                                      |
