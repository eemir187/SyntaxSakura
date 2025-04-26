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
make bin                 # Compiles the binary into 'assignment'
make run                 # Runs the game with a given config file
make reset               # Resets all config files to their original state
make clean               # Removes all compiled binaries and object files
```

## Examples

The following example output was created using [config file 1](configs/config_01.txt).



<details>
<summary><strong>Example Output</strong></summary>

<br>

<div style="background:#f6f8fa;border-radius:6px;padding:16px;border:1px solid #d0d7de;overflow:auto">

<pre>
Welcome to SyntaxSakura (2 players are playing)!

-------------------
CARD CHOOSING PHASE
-------------------

Player 1:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 67_r 81_g 89_r 119_w
  chosen cards:

Please choose a first card to keep:
P1 > 89
Please choose a second card to keep:
P1 > 67

Player 2:
  hand cards: 5_r 29_r 30_g 33_g 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards:

Please choose a first card to keep:
P2 > 29
Please choose a second card to keep:
P2 > 5

Card choosing phase is over - passing remaining hand cards to the next player!

------------
ACTION PHASE
------------

Player 1:
  hand cards: 30_g 33_g 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards: 67_r 89_r

What do you want to do?
P1 > place 1 89

Player 1:
  hand cards: 30_g 33_g 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards: 67_r
  row_1: 89_r

What do you want to do?
P1 > place 1 67

Player 1:
  hand cards: 30_g 33_g 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards:
  row_1: 67_r 89_r


Player 2:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards: 5_r 29_r

What do you want to do?
P2 > help

Available commands:

- help
  Display this help message.

- place <row number> <card number>
  Append a card to the chosen row or if the chosen row does not exist create it.

- discard <card number>
  Discard a card from the chosen cards.

- quit
  Terminate the program.


Player 2:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards: 5_r 29_r

What do you want to do?
P2 > discard 5

Player 2:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards: 29_r

What do you want to do?
P2 > place 2 29

Player 2:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards:
  row_2: 29_r


Action phase is over - starting next game round!

-------------------
CARD CHOOSING PHASE
-------------------

Player 1:
  hand cards: 30_g 33_g 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards:
  row_1: 67_r 89_r

Please choose a first card to keep:
P1 > 30
Please choose a second card to keep:
P1 > 33

Player 2:
  hand cards: 14_w 28_w 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards:
  row_2: 29_r

Please choose a first card to keep:
P2 > 14
Please choose a second card to keep:
P2 > 28

Card choosing phase is over - passing remaining hand cards to the next player!

------------
ACTION PHASE
------------

Player 1:
  hand cards: 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards: 30_g 33_g
  row_1: 67_r 89_r

What do you want to do?
P1 > place 1 33

Player 1:
  hand cards: 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards: 30_g
  row_1: 33_g 67_r 89_r

What do you want to do?
P1 > place 1 30

Player 1:
  hand cards: 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r


Player 2:
  hand cards: 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards: 14_w 28_w
  row_2: 29_r

What do you want to do?
P2 > place 1 28

Player 2:
  hand cards: 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards: 14_w
  row_1: 28_w
  row_2: 29_r

What do you want to do?
P2 > place 1 14

Player 2:
  hand cards: 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards:
  row_1: 14_w 28_w
  row_2: 29_r


Action phase is over - starting next game round!

-------------------
CARD CHOOSING PHASE
-------------------

Player 1:
  hand cards: 38_b 48_g 56_w 57_g 81_g 119_w
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r

Please choose a first card to keep:
P1 > 38
Please choose a second card to keep:
P1 > 57

Player 2:
  hand cards: 37_r 44_b 60_g 61_r 110_b 115_r
  chosen cards:
  row_1: 14_w 28_w
  row_2: 29_r

Please choose a first card to keep:
P2 > 44
Please choose a second card to keep:
P2 > 110

Card choosing phase is over - passing remaining hand cards to the next player!

------------
ACTION PHASE
------------

Player 1:
  hand cards: 37_r 60_g 61_r 115_r
  chosen cards: 38_b 57_g
  row_1: 30_g 33_g 67_r 89_r

What do you want to do?
P1 > place 2 38

Player 1:
  hand cards: 37_r 60_g 61_r 115_r
  chosen cards: 57_g
  row_1: 30_g 33_g 67_r 89_r
  row_2: 38_b

What do you want to do?
P1 > place 2 57

Player 1:
  hand cards: 37_r 60_g 61_r 115_r
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r
  row_2: 38_b 57_g


Player 2:
  hand cards: 48_g 56_w 81_g 119_w
  chosen cards: 44_b 110_b
  row_1: 14_w 28_w
  row_2: 29_r

What do you want to do?
P2 > discard 45
Please enter the number of a card in your chosen cards!
P2 > discard 44

Player 2:
  hand cards: 48_g 56_w 81_g 119_w
  chosen cards: 110_b
  row_1: 14_w 28_w
  row_2: 29_r

What do you want to do?
P2 > place 1 110

Player 2:
  hand cards: 48_g 56_w 81_g 119_w
  chosen cards:
  row_1: 14_w 28_w 110_b
  row_2: 29_r


Action phase is over - starting next game round!

-------------------
CARD CHOOSING PHASE
-------------------

Player 1:
  hand cards: 37_r 60_g 61_r 115_r
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r
  row_2: 38_b 57_g

Please choose a first card to keep:
P1 > 61
Please choose a second card to keep:
P1 > 115

Player 2:
  hand cards: 48_g 56_w 81_g 119_w
  chosen cards:
  row_1: 14_w 28_w 110_b
  row_2: 29_r

Please choose a first card to keep:
P2 > place 1 15
Please enter the number of a card in your hand cards!
P2 > 48
Please choose a second card to keep:
P2 > 81

Card choosing phase is over - passing remaining hand cards to the next player!

------------
ACTION PHASE
------------

Player 1:
  hand cards: 56_w 119_w
  chosen cards: 61_r 115_r
  row_1: 30_g 33_g 67_r 89_r
  row_2: 38_b 57_g

What do you want to do?
P1 > place 1 115

Player 1:
  hand cards: 56_w 119_w
  chosen cards: 61_r
  row_1: 30_g 33_g 67_r 89_r 115_r
  row_2: 38_b 57_g

What do you want to do?
P1 > place 2 61

Player 1:
  hand cards: 56_w 119_w
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r 115_r
  row_2: 38_b 57_g 61_r


Player 2:
  hand cards: 37_r 60_g
  chosen cards: 48_g 81_g
  row_1: 14_w 28_w 110_b
  row_2: 29_r

What do you want to do?
P2 > place 1 48
This card cannot extend the chosen row!
P2 > place 2 48

Player 2:
  hand cards: 37_r 60_g
  chosen cards: 81_g
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g

What do you want to do?
P2 > place 2 81

Player 2:
  hand cards: 37_r 60_g
  chosen cards:
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g 81_g


Action phase is over - starting next game round!

-------------------
CARD CHOOSING PHASE
-------------------

Player 1:
  hand cards: 56_w 119_w
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r 115_r
  row_2: 38_b 57_g 61_r

Please choose a first card to keep:
P1 > 56
Please choose a second card to keep:
P1 > 119

Player 2:
  hand cards: 37_r 60_g
  chosen cards:
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g 81_g

Please choose a first card to keep:
P2 > 37
Please choose a second card to keep:
P2 > 60

Card choosing phase is over - passing remaining hand cards to the next player!

------------
ACTION PHASE
------------

Player 1:
  hand cards:
  chosen cards: 56_w 119_w
  row_1: 30_g 33_g 67_r 89_r 115_r
  row_2: 38_b 57_g 61_r

What do you want to do?
P1 > place 1 119

Player 1:
  hand cards:
  chosen cards: 56_w
  row_1: 30_g 33_g 67_r 89_r 115_r 119_w
  row_2: 38_b 57_g 61_r

What do you want to do?
P1 > place 3 56 

Player 1:
  hand cards:
  chosen cards:
  row_1: 30_g 33_g 67_r 89_r 115_r 119_w
  row_2: 38_b 57_g 61_r
  row_3: 56_w


Player 2:
  hand cards:
  chosen cards: 37_r 60_g
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g 81_g

What do you want to do?
P2 > place 3 37

Player 2:
  hand cards:
  chosen cards: 60_g
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g 81_g
  row_3: 37_r

What do you want to do?
P2 > discard 60

Player 2:
  hand cards:
  chosen cards:
  row_1: 14_w 28_w 110_b
  row_2: 29_r 48_g 81_g
  row_3: 37_r


Action phase is over - starting next game round!


Player 1: 114 points
Player 2: 62 points

Congratulations! Player 1 wins the game!

</pre>
</div>

</details>



<br>


After executing the program the config file should look like this:


<details>
<summary><strong>Example File after Documenting the Results</strong></summary>

<br>

<div style="background:#f6f8fa;border-radius:6px;padding:16px;border:1px solid #d0d7de;overflow:auto">

<pre>
ESP
2
57_g
37_r
28_w
29_r
89_r
44_b
14_w
115_r
119_w
60_g
67_r
61_r
48_g
5_r
81_g
110_b
56_w
33_g
38_b
30_g

Player 1: 114 points
Player 2: 62 points

Congratulations! Player 1 wins the game!

</pre>
</div>

</details>
