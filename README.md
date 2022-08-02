# olc-game-of-life
 Implementation John Conway's Game of Life in the olcPixelGameEngine.

![olc-pixel-game-engine](https://media.giphy.com/media/sdDDM08AQe9fypTN5P/giphy-downsized-large.gif)

## Controls

| Button | Action |
| ----------- | ----------- |
| Escape | Quit |
| Left click | Draw |
| Right click | Erase |
| Backspace | Clear |
| Enter | Simulate start/stop |
| Space | Simulate step |
| P | Play |
| O | Reverse |
| - | Decrease speed |
| = | Increase speed |
| Left arrow | Step back |
| Right arrow | Step forward |
| Ctrl + Left arrow | Jump to front |
| Ctrl + Right arrow | Jump to end |

## Building

Building is based on Moros1138's [pge-template-project](https://github.com/Moros1138/pge-template-project) CMake files

### Arch Linux

Install the required packages with the following command

`sudo pacman -Sy base-devel cmake git libpng mesa`

Generate project makefiles with CMake

`cmake .`

And build the project

`make`

### Windows

Install a C++ compiler like [MinGW](https://sourceforge.net/projects/mingw/)

Generate project makefiles with CMake

`cmake . -G "MinGW Makefiles"`

And build the project

`mingw32-make`
