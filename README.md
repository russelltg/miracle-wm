# Mir Compositor Technical Challenge by Matthew Kosarek

## Goal
My goal was to make an i3-like tiling window manager within the Mir ecosystem. To that end, I programmed the following features:
- A tiling window manager with support for horizontal and vertical placement
- A keyboard-based window selection mechanic
- A application-qutting mechanic

## Demo
You can watch `demo.mkv` to see it in action.


## Prerequisites
I used the `mir-builder.ova` virtual machine with `VirtualBox` for all of my testing. Please copy this project folder (or setup a shared folder) into the VirtualBox.

On that machine, I did the following:
```sh
sudo apt update && sudo apt upgrade
sudo apt install xinit
sudo apt install xwayland
sudo reboot now
startx
```

Please also install `xfce4-terminal`, as it is the terminal that I used for testing and it is hardcoded within the program:
```sh
sudo apt install xfce4-terminal
```


## Buiding
```sh
mkdir build
cd build
cmake ..
make
```

## Running
After building:
```sh
cd build
./bin/compositor
```

## Controls
In this section, "META" refers to the Windows key (or whatever else you might have it bound to!).

| Keybind | Effect |
|--------------|-----|
| META + ENTER | Open xfce-4 terminal |
| META + v | Split the selected terminal vertically |
| META + h | Split the selected terminal horizontally |
| META + SHIFT + q | Delete the selected application |
| META + LEFT | Move left in the Tile Grid |
| META + RIGHT | Move right in the Tile Grid |
| CTRL + SHIFT + BACKSPACE | Exit the compositor |

## Future work
If I had more time to complete the assignment, I would prioritize the following features in this order:
1. When a user closes an application, the whole grid should resize accordingly
2. Resizing individual `TileNode`s
3. Moving `TileNode`s within the grid
4. Improved performance, specifically with grid searches
5. Unit testing all of these things, which I have left out of this assignment

## References
- https://mir-server.io/doc/index.html
- https://mir-server.io/docs/developing-a-wayland-compositor-using-mir
- https://mir-server.io/doc/introducing_the_miral_api.html
- https://github.com/AlanGriffiths/egmde