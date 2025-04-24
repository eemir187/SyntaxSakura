# 🃏 SyntaxSakura – A Terminal-Based Card Game

**SyntaxSakura** is a two-player strategy card game played entirely in the terminal. The game involves choosing and placing cards into ordered rows based on specific rules and constraints. The player with the highest score at the end wins.

The game is inspired by *Ohanami* but features a custom rule set and mechanics tailored for a streamlined command-line experience.

---

## 🎮 Gameplay Summary

- Each player is dealt 10 unique cards from a config file.
- Players take turns choosing 2 cards to keep from their hand.
- Remaining cards are passed to the opponent after each round.
- In the action phase, players place cards into up to 3 ascending rows or discard them.
- Rows can only be extended at the front or back.
- Once all cards have been placed or discarded, points are awarded.
- Each card’s color defines its point value.
- The player with the most points at the end wins.

---

## 🛠️ Build Instructions

The game can be compiled and run using the provided `Makefile`.

### 🔧 To compile the game binary:

```bash
make bin        # Compiles the binary into 'assignment'
./assignment configs/config_01.txt    # Runs the game with a given config file
make test       # Runs all public test cases
make reset      # Resets all config files to their original state
make clean      # Removes all compiled binaries and object files
