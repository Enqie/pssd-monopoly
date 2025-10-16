# **Linux compatibility only. Developed and tested on Ubuntu WSL.**
## Installing, compiling and running
Clone repository with `--recursive` flag (or `git submodule update --init` after cloning) to ensure imgui is included.

Requires libglfw3 which can be installed by running `sudo apt-get install libglfw3 libglfw3-dev`

To compile the project, run `make` in the terminal.

To run the game, run `./monopoly.out` in the terminal.

# Monopoly Rules
## Rules
### Initial set up
This Monopoly game runs with modified rules for 2-4 players (chosen when game is run). 
Each player starts with $1500 on the GO space.

### During the game
The players take turns, starting with the lowest numbered player.
Each turn, the player rolls the dice and moves to the space stated by their dice roll clockwise around the board.
Landing on the space, the player may take relevant actions depending on the space type, as stated below

### End of game
The first player who goes bankrupt will retire from the game. 

If the game has exactly 2 players, the remaining player wins the game.

For games with more than 2 players, the game ends when a second player goes bankrupt. The remaining player with the highest cash on hand wins the game.

### Bankruptcy
A player is declared bankrupt if they have no more money. After a player is bankrupt, their owned Sites are considered unowned and can be bought by remaining players if they land on the Site.

## Spaces
### Passing Go
Whenever a player lands or passes Go (with the exception of when the player goes to jail), they get $200.

### Buying Site
If a player lands on an unowned Site, they have the choice to buy it. There are three types of Sites - Properties, Utilities and Railroads. If the player chooses to buy the Site, they pay the stated amount and now own the Site. If the player does not choose to buy the site, their turn ends. The player who owns of any Site collects rent from any other player who lands on that Site. Owners of the Site do not pay rent.

### Landing on owned Properties
Landing on a property you own gives you the option to buy a house or hotel on it. Buying a house or hotel increases the rent for any other player who lands on the property. The owner of a Property can buy one house whenever they land on their Property, after which  and can buy up to three houses and one hotel a single property. If you land on a property you do not own, you must pay rent to the owner of the property.

### Landing on owned Utilities
The rent paid when landing on an owned Utility depends on the player's dice roll. If the owner has only one of the Utilities, the rent will be four times the dice roll. If, however, both Utilities are owned by the same player, the rent paid is ten times the amount of the dice roll.

### Landing on Railroads
The rent paid when landing on a Railroad depends on the amount of Railroads owned by the owner. Starting at $25, the rent doubles for each additional owned Railroad.

### Landing on Tax, Chance or Community Chest spaces
Landing on any of these spaces requires the player to pay the relevant amount of money.

### Free Parking
If a player lands on this space, they simply rest here until their next turn. There is no penalty for landing on  this space.

### Jail and Go To Jail
A player will be sent to Jail if they land on the "Go To Jail" space. If a player is sent to jail, they do not collect $200 when passing Go.

If a player is in jail, 
- they may choose to pay $50 bail to immediately get out of jail and continue their next turn, or
- they may choose to try and roll for a double to get out of jail for free. Note this option is only available for three turns after which the player must pay bail to get out of jail.

If a player has not been sent to jail but lands on the Jail space, they are considered "just visiting", incur no penalty and can move ahead as usual on their next turn.