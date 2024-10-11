## Fraction Class Programm
### Dominique Hawkins
### Description: 
		This assignment begins an initial design for our KnuckleBones game.
    	It will contain a template of what could be implemented into the actual game.
    	No real code is needed.
### Files
|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   |    N/A   | N/A |
### Instructions
- This Program does not require any non standard libraries

- **Dice Class**: 
     - Data: `sides`, `current_value`
     - Actions: `roll()`, `get_value()`, `reroll()`, `weighted_roll`
     - Relationships: Dice will be used by the Player to roll during the game.
     - Dice **is a** Die
   
   - **Player Class**:
     - Data: `fname`, `lname`, `userid`, `score`, `dice_set`, `player_stats`, `emote`, `achievements`, `level`
     - Actions: `roll_dice()`, `get_score()`, `update_score()`, `get_emote()`, `save_progress()`
   
   - **Game Class**:
     - Data: `players`, `rules`, `current_round`, `tokens`, `high_score`, `leaderboards`
     - Actions: `start_game()`, `end_game()`, `get_winner()`, `reset_game()`, `game_mode()`, `display_leaderboard()`
     - Relationships: The Game class controls the players and their actions.

   - **Knucklebones Class**:
     - Data: `board`, `knucklebones_specific_rules`, `badge`, `coins`, `teams`
     - Actions: `start_round()`, `end_round()`, `calculate_winner()`, `get_badge()`, `get_teams`
     - Relationships: Inherits from Game, as Knucklebones **is a** game with specific rules and conditions.
     - Knucklebones **has a** dice && **has a** player
     
#### roll_dice(): Roll the dice for the player.
#### get_score(): Retrieve the current score.
#### update_score(points): Update the player’s score after each roll.

### Relationships:

#### A Player HAS-A Dice (composition).
#### A Player IS-A participant in the game.

   

### Necessary
- winner
- score
- first name
- last name
- userid
- high score
### Possible
- teams
- team stats
- streak
- levels
- leaderboard
- coins
### Wishful
- chat
- messaging
- player stats
