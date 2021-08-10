# BasicMinesweeper
`BasicMinesweeper` is a basic ASCII implementation of the classic Minesweeper game created solely using C++. This project was solely made out of self interest in the game as well as desire for additional C++ practice. Please note that this is in *no way* a perfect implementation of Minesweeper.

## Gameplay
Instead of the traditional style of tapping on each square, the board is created by a grid based on three difficulties available: easy, medium, and hard.

</br>

1. Easy - 10 x 10 Board with 10 Mines
2. Medium - 16 x 16 Board with 40 Mines
3. Hard - 30 x 16 Board with 99 Mines

<a/></br>
You'll be able to access each tile based on the xy-coordinates of the board, in which you'll either **reveal** or **flag** a tile.

</br>
Eventually, when you've revealed all the tiles that aren't bombs, you'll have successfully won the game! However, if you manage to uncover a mine, you'll immediately lose the game!

## Controls
To select tiles to interact with, you'll use the terminal to type in your controls. They all follow the format of:

    <x> <y> <R/F>
        
First is your x-coordinate, then your y-coordinate, and lastly `R` or `F` to indicate whether you want to reveal or flag a tile. Note that each part of your input should be separated by a space!

Here are some examples:
1. Revealing the tile at (5, 2)
    - `5 2 R`
2. Revealing the tile at (10, 10)
    - `10 10 R`
3. Flagging the tile at (4, 15)
    - `4, 15, F`
4. Unflagging the tile at (6, 5), in the case it is already flagged
    - `6, 5, F`

## Revealing Tiles
All tiles begin as a simple `-`. But as you reveal tiles, they'll either become a blank space signaling that there are no nearby mines, `1-8` signaling the number of mines surrounding the tile, or `X` signaling you've hit a mine!

Note that you won't be able to reveal flagged tiles, and (obviously) previously revealed tiles.

## Flagging Tiles
When you flag a tile, their tile will change into a `F` such that you cannot reveal the tile! Flagging mines is a great way to track which tiles you suspect are mines to avoid accidentally revealing it!

In the case you accidentally flag a tile or change your mind, you can unflag it the same way you flagged it!

## Invalid Inputs
There are certain error checks implemented within the code to ensure your inputs all work.
1. Invalid difficulty
2. Invalid x or y coordinate
3. Invalid mode, in the case you didn't choose to reveal(R) or flag(F) a tile
4. Invalid revealing, such that you try to reveal a tile that is already revealed or flagged
5. Invalid flagging, such that you try to flag a tile that is revealed
6. Invalid choice to start a new game or quit

## Running The Game
The only files you actually need to run the game are: `Minesweeper.h`, `Minesweeper.cpp`, `Board.cpp`, `main.cpp`. Using a terminal with a C++ environment, you can compile the game using:

    g++ -o Game main.cpp Minesweeper.cpp Board.cpp
    
Then run the game using:

    ./Game
    
Note you'll only have to compile the game once, then you can keep running the game by using `./Game`!

## Final Remarks
Though it is a simple implementation, it was really enjoyable to make and I hope you'll enjoy just trying it out. By no means do I expect anyone to try this out fully and play it all the time. But, it helped me put some extra practice into C++ and taught me a few things about planning ahead before coding. Please let me know if you do find some bugs or problems that I can work to fix! Thanks!
