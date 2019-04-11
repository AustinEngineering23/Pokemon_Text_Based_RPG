# Pokemon_Text_Based_RPG
A text based recreation of the popular Pokemon Red Version. Done in C++

The pokemonMain.cpp file contains the core functionality of the game, this is where the trainer object will move through the space object. 
It has the following functions:
sdf
sdf
sdf

Introduce the player to the game, prompt for a name,
starts up the game, creates the player, pokemon, and space objects
allows the player to move through spaces, which can trigger events
allows access to a menu where the player can select different actions
hosts the battle system
accounts for win/loss conditions and also sets up the game timer

The objects and their functions are as follows:

Caterpie: A Pokemon class that inherits from Monster

Charmander: ''             ''                ''

Geodude:    ''             ''                ''

menu: A class that outputs choices to the user, and validates user input. Ensuring a user must make a choice from the list

Monster: The parent class to all Pokemon objects

Onix: Another Pokemon class.

PalletTown: A Location class that inherits from the Space class. The player may interact with Professor Oak here

PewterCity: A Location class that inherits from the Space class. The player may challenge the gym leader Brock here. They may also heal.

Pidgey: Another Pokemon class.

Route: A Location class that inherits from the Space class. The Route objects have a chance for random encounters when a player enters them.

Space: This is the parent class to all other Location classes. The player object will move through each space to complete the game.

Trainer: This is the player's object. It has functions for many of the game's mechanics. Including healing the trainer's pokemon, moving between spaces, using items, and gaining items.

ViridianForest: A Location class that is similar to the Route classes.
