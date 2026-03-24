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
From: 17 March 2026 - To: 24 March 2026

Total Time: 9 hrs 48 mins

C++         8 hrs 40 mins         ░░░░░░░░░░░░░░░░░░░░░░███   88.40 %
CMake       34 mins               ░▓███████████████████████   05.82 %
YAML        21 mins               ░████████████████████████   03.65 %
C           12 mins               ▒████████████████████████   02.06 %
gitignore   0 secs                █████████████████████████   00.05 %
```

<!--END_SECTION:waka-->
