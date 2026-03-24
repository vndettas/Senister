## Senister
Inspired by vim and vim like code editors, project goal is to bring something new to UX experience on top of the efficient core and vim style coding

## Ideology and features
- Reliable fast core (Piece of table) which supports huge files

- Vim smart cursor
![Дизайн без назви](https://github.com/user-attachments/assets/fe1492ef-8c54-49dd-86ca-44c573f379d6)

- Mouse free experience

- Advanced ui and sound design to improve ux

## Dependencies

- **C++ 20**

- **Qt 6**

- **Cmake 3.27** ++

- Ccache (optional)

## Building

```
git clone https://github.com/vndettas/Senister.git

cd Senister

mkdir build

cmake .

cd build

cmake --build . -j 8
```

## Manual

Currently you can open file only changin path in app.cpp

**Normal Mode**
h, k, j, l - movement
i - switch to insert mode
x - delete single character
ctrl + number - open number file
ctrl + s - save file
**Insert Mode**
esc - switch to normal mode
Press any keyboard key to insert except ctrl, del etc.
