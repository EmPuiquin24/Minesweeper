# Minesweeper
A simple and cool Minesweeper game written in C++.

Feel free to contribute to this repository.

_This program was created as part of Programming II course. You can read the original description of the proyect in the PDF file._

## Build 
You can use your own way to compile the program. These instructions work for Linux distributions and use the CMakeLists.txt. 

1. Clone this repo
```sh
git clone https://github.com/EmPuiquin24/Minesweeper.git
```
2. Navigate into the repo folder. Build the executable with the following commands
```sh
mkdir build
cd build
cmake ..
make
```
3. If you did the previous instructions, you are already into the /build directory. Now, run the Minesweeper's game with the command 
```sh
./Minesweeper
```

## Gameplay
The gameplay is pretty simple. These are the instructions and restricctions of this Minesweeper game:

1. To select a cell, you must type the row and column. For example, the input '4 5' represents 4th row and 5th column.
2. Once you select a cell, you can choose to reveal It or place/remove a flag on It.
3. Flags can be placed and removed at any time. (Flags may be used to mark specific cells that are suspected to contain a mine.)
4. Once a cell is revelead, the number on a cell without a mine indicates the number of mines adjacent.
5. You automatically lose if you reveal a cell with a mine.

## Authors
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/EmPuiquin24">
        <img src="https://github.com/EmPuiquin24.png" width="100px;" style="border-radius: 50%;" alt="EmPuiquin24"/>
        <br />
        <sub><b>Author Name</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/CJimenez-C">
        <img src="https://github.com/CJimenez-C.png" width="100px;" style="border-radius: 50%;" alt="CJimenez-C"/>
        <br />
        <sub><b>Author Name</b></sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/andrxeaa">
        <img src="https://github.com/andrxeaa.png" width="100px;" style="border-radius: 50%;" alt="andrxeaa"/>
        <br />
        <sub><b>Author Name</b></sub>
      </a>
    </td>
  </tr>
</table>
