# PPM Image Viewer in Pure C

A simple PPM (P6) image viewer written in pure C using SDL2.

This project reads raw binary pixel data from a `.ppm` image and renders it manually pixel-by-pixel onto an SDL surface.

The goal of this project was to learn:

- Low-level image formats
- Binary file handling in C
- Pixel rendering
- SDL2 surfaces
- Memory layout in graphics programming

---

## Features

- Reads binary P6 PPM images
- Manual RGB pixel parsing
- Pixel-by-pixel software rendering
- SDL2 window rendering
- Pure C implementation

---

## Screenshot

![Alt Spidy Image](./ss.png)

---

## How It Works

PPM P6 images store pixels in this format:

```text
R G B R G B R G B ...
```

The program:

1. Reads the PPM header
2. Extracts image width and height
3. Reads raw RGB bytes
4. Maps RGB values to SDL colors
5. Draws every pixel manually

Pixels are rendered row-by-row:

```c
for (int y = 0; y < height; y++)
{
    for (int x = 0; x < width; x++)
```

This matches the actual memory layout of PPM image data.

---

## Build

### Linux

Install SDL2:

Ubuntu/Debian:

```bash
sudo apt install libsdl2-dev
```

Arch Linux:

```bash
sudo pacman -S sdl2
```

Compile:

```bash
gcc main.c -o viewer `sdl2-config --cflags --libs`
```

---

## Usage

```bash
cat image.ppm | ./viewer
```

---

## Example

```bash
cat doom.ppm | ./viewer
```

---

## Future Improvements

- Direct framebuffer access instead of SDL_FillRect
- PNG/JPEG support
- Keyboard controls
- Image scaling
- Hardware accelerated rendering
- Custom software renderer

---

## License

MIT
