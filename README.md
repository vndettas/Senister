## Senister
Inspired by vim and vim like code editors, project goal is to bring something new to UX experience on top of the efficient core and vim style coding

## Ideology and features
- Reliable fast core (Piece of table) which supports huge files (Read more about it below)

- Vim smart cursor
![demo](https://github.com/user-attachments/assets/d0aa1c67-21db-47bc-9d3f-dad223a5ac18)

- Mouse free experience

- Advanced ui and sound design to improve ux

## Dependencies

- **C++ 20**

- **Qt 6**

- **Cmake 3.27** ++

- Gtest (installed by building system from github repo)

- Ccache (optional)

## Building

```
git clone https://github.com/vndettas/Senister.git

cd Senister

mkdir build

cd build

cmake ..

cmake --build . -j 8
```

## Testing


Core is parially covered with tests
```
cd build
cmake --build . --target gtest
./PieceTableTest
```

## Manual

Currently you can open file only changing path in app.cpp

**Normal Mode**  
<kbd>h</kbd>, <kbd>k</kbd>, <kbd>j</kbd>, <kbd>l</kbd> - movement  
<kbd>i</kbd> - switch to insert mode  
<kbd>x</kbd> - delete single character  
<kbd>ctrl</kbd> + <kbd>number</kbd> - open number file  (Assuming file is already opened and appeared in file tab)
<kbd>ctrl</kbd> + <kbd>s</kbd> - save file  


**Insert Mode**  
<kbd>esc</kbd> - switch to normal mode  
Press any keyboard key to insert except <kbd>ctrl</kbd>, <kbd>del</kbd> etc  


## Statistics


<!--START_SECTION:waka-->

```txt
From: 18 March 2026 - To: 25 March 2026

Total Time: 12 hrs 32 mins

C++         9 hrs 52 mins         ░░░░░░░░░░░░░░░░░░░▒█████   78.32 %
YAML        38 mins               ░▓███████████████████████   05.11 %
CMake       35 mins               ░████████████████████████   04.64 %
Markdown    30 mins               ░████████████████████████   04.00 %
JSON        27 mins               ░████████████████████████   03.64 %
```

<!--END_SECTION:waka-->
