# WordsCheat

This software is used to cheat in multi-player game called "Words". Challenge in the game is to find all words in 4x4 board of letters.

On startup it loads dictionary into memory and waits for user to provide a board. Once the board is provided, program proceeds to search through the dictionary for appropriate words and prints them out.

### BUILDING:

This software uses Cmake. It is used to generate platform dependent build system. In order to compile WordsCheat, follow instructions:

1. Generate makefile by typing:

`cmake .`

2. Run the makefile by typing:

`make WordsCheat`

### RUNNING:

Once you have compiled the software. Run it from the console interface by typing `./WordsCheat [word list]`.

Example:

`./WordsCheat Wordlists/croatian-wordlist.txt`

### USAGE:

Lets assume board looks like this:

```
    A B C D
    A B C D
    A B C D
    A B C D
```

Users inputs: `ABCDABCDABCDABCD`

[Program prints out all words present on board]
