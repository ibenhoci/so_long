# So_long

This project is an implementation of a simple maze game in 2D using the 42 school's graphic library: minilibx

## Description
- The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
	
- The W, A, S, and D keys must be used to move the main character.
	
- The player should be able to move in these 4 directions: up, down, left, right.
		
- At every move, the current number of movements must be displayed in the shell.
	
- The game provides a 2D view of an old retro game style maze.
		
- Although the game has a set theme, you can create the world you want by simply changing the textures, they just need to have a .xpm42 format.

## Requirements

- Basic requirements:
	--- This project relies on the minilibx graphics library, it will need to be installed in order to run the program.
	--- Input file with .ber extension, this file will contain a closed map.

- Input requirements:
	--- The map must be composed of only the following characters: 0 for empty space, 1 for wall, P for the player's starting position, C for available collectibles on the map and E for exit. Every character is mandatory for a logical and complete map except for collectibles.
	--- The map must be surrounded by walls and must not contain spaces inside the wall.
	--- Map example:
		```
			111111111
			1P010C001
			10C0000E1
			111111111
		```
## Usage

- Clone the repository:
	```
		git clone https://github.com/ibenhoci/so_long
	```
- Build the project:
	```
		make
	```
	Running make for the first time will also download the minilibx library which is necesary for rendering the graphics of the project
- Run the project:
	```
		./so_long map.ber
	```
- Last step: Enjoy!