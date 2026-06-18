🎮 Hangman Game — C Language
 A console-based word guessing game built in C.

📖 Introduction
The Hangman Game is a simple word guessing game developed using the C programming language. The player guesses a hidden word by entering 
one letter at a time,with limited chances — each incorrect guess draws another part of the hangman figure.

📍This project demonstrates core C concepts: 
  1.loops
  2.arrays
  3.strings
  4.functions
  5.conditional statements

🎯 Objectives

🟢 Develop a simple Hangman game using C programming
🟢 Understand the use of arrays and strings
🟢 Implement conditional logic and loops
🟢 Improve problem-solving and logical thinking skills
🟢 Learn function usage in C

⚙️ How It Works

1.A random word is selected from a list using rand() and srand(time(0))
2.The player gets 6 chances to guess the word
3.The word is displayed as underscores (_) initially
4.Player enters one letter at a time
5.Correct guess → letter is revealed in the word
6.Wrong guess → chances decrease and the ASCII hangman figure updates
7.Game ends when the word is fully guessed or chances run out
8.Score updates (+10 per win), and the player can choose to play again

Working Principle

- A separate array (guessedword) tracks correctly guessed letters
- Each input is validated: single character, not already guessed, and checked against the secret word
- The hangman figure is drawn using a switch statement based on remaining chances
- strcmp() compares the guessed word with the secret word to detect a win
- The loop continues until the word is guessed or chances reach zero
- Score is maintained across multiple rounds
  
🧗 Challenges Faced

> Handling string comparison using strcmp()
> Managing repeated/duplicate letter guesses
> Debugging logic for correct vs. incorrect guesses
> Displaying the proper hangman ASCII structure
> Understanding random number generation

✅ Conclusion
This project helped in understanding the practical application of C programming concepts such as arrays, strings, functions, loops,
and conditional statements.Building the Hangman Game improved logical thinking, problem-solving ability, and coding skills — along with
handling user input, implementing game logic, and debugging effectively.

⭐ Star this repo if you found it useful!



