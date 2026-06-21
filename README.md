# TicTacToe with Minimax AI (C++)

A console-based TicTacToe game where you play as **X** against an unbeatable AI opponent (**O**) powered by the **Minimax algorithm**.

## Project Description

This project is a from-scratch implementation of TicTacToe in C++, built to practice core C++ fundamentals — recursion, backtracking, 2D arrays, and multi-file project structure — alongside a classic AI search algorithm.

Rather than using random or rule-of-thumb logic, the AI opponent fully explores the game tree for every possible move using Minimax, guaranteeing it always plays optimally. Since TicTacToe's game tree is small enough to search completely, the AI is mathematically unbeatable: a human can win only if the AI plays a non-optimal move, which never happens here.

The codebase is split across multiple files to separate concerns:
- Game state display and player input live in `Functions.cpp`/`Functions.h`.
- The AI logic (scoring, recursion, move selection) lives in `minmax.cpp`.
- `main.cpp` ties everything together into a playable game loop.

## How to Play

1. Run the program.
2. The board is numbered 1–9, left to right, top to bottom:
   ```
    1 | 2 | 3
    4 | 5 | 6
    7 | 8 | 9
   ```
3. Enter a number to place your `X` in that cell.
4. The AI (`O`) responds automatically after each of your moves.
5. The game ends in a win, loss, or draw.

Against a perfect Minimax AI, the best a human can ever achieve is a **draw** — the AI will never lose.

## Project Structure

| File | Responsibility |
|---|---|
| `main.cpp` | Game loop: alternates turns, checks for win/draw, prints results |
| `Functions.h` | Function declarations shared across files |
| `Functions.cpp` | Board display, player input handling, win detection |
| `minmax.cpp` | The Minimax AI: move evaluation and best-move search |

## How the Minimax Algorithm Works

Minimax is a decision-making algorithm used in two-player, turn-based games with perfect information (no hidden information, no randomness — like TicTacToe, Chess, or Connect 4).

The core idea: **simulate every possible sequence of future moves**, score each resulting outcome, and assume both players always play optimally — one trying to maximize the score, the other trying to minimize it.

### The two roles

- **Maximizing player (`O`, the AI):** picks the move that leads to the **highest** possible score.
- **Minimizing player (`X`, the human):** is assumed to pick the move that leads to the **lowest** possible score.

This "worst-case assumption" about the opponent is what makes the AI unbeatable — it always plans for the human to play their best possible move, never an unlucky one.

### Scoring a finished board (`evaluate()`)

| Outcome | Score |
|---|---|
| `O` wins | `+10` |
| `X` wins | `-10` |
| Draw / no winner yet | `0` |

### Recursing through the game tree (`minimax()`)

For every empty cell, the algorithm:
1. **Places** a hypothetical move on the board.
2. **Recurses** — calls itself to evaluate the *opponent's* best response to that move.
3. **Undoes** the hypothetical move (backtracking), so the real board is untouched while exploring other branches.
4. **Keeps** the move that gives the best score for whichever player is currently "thinking."

This repeats until a terminal state is reached (a win or a full board), at which point `evaluate()` provides the score that gets propagated back up through every parent call.

A `depth` counter is added/subtracted from the score at each level, so the AI prefers to **win as quickly as possible** and **lose as slowly as possible** when a loss is unavoidable — rather than being indifferent between winning in 1 move or 5 moves.

### Picking the actual move (`findBestMove()`)

`minimax()` only returns a *score*, not a *move*. `findBestMove()` sits one level above it:
1. Tries every empty cell as a hypothetical `O` move.
2. Asks `minimax()` to score the resulting position (assuming the opponent then plays optimally).
3. Undoes the hypothetical move.
4. Remembers whichever cell produced the highest score.
5. Returns that cell — this is the move the AI actually plays.

### Why this guarantees the AI never loses

Because the algorithm exhaustively explores **every** possible continuation of the game (TicTacToe's game tree is small enough to fully search), the AI's evaluation of each move is exact, not a heuristic guess. Combined with the worst-case assumption about the opponent, the AI's chosen move is always provably optimal for the current position.

## Building

```bash
g++ main.cpp Functions.cpp minmax.cpp -o tictactoe
./tictactoe
```

(Or compile via your IDE's build/run button if `main.cpp` includes the other `.cpp` files directly.)
