# Fillit

Tetris blocks are made to be fit together. The Fillit program abides.

### Contents

1. [What is Fillit?](#what-is-fillit)
2. [What are tetriminos?](#what-are-tetriminos)
3. [How does Fillit work?](#how-does-fillit-work)
4. [How do I use it?](#how-do-i-use-it)
5. [Contributions](#contributions)

### What is Fillit?

Fillit is a [42 School][1] group project that takes some number of [tetriminos](#what-are-tetriminos) and fits them together in the smallest possible square area. I go over the important details of the project below, but if you'd like to see the full specifications you can view the full [project subject][3].

The learning objective of Fillit was for us to gain experience searching for the optimal solution among a huge set of possibilities. It also introduced 42 students to working on programming challenges collaboratively, since it was a group project. My partner for Fillit was [Claudia Davila][2], and our individual contributions are detailed in the contributions section.

### What are tetriminos?

Tetriminos are essentially tetris blocks. When taken as input for this project, the blocks were represented by hashtags `#` positioned on a 4x4 grid. 

For example, the following would represent a tetrimino in the form of a straight vertical line:

	..#.
	..#.
	..#.
	..#.

And the following would represent a different tetris block shape:

	....
	.##.
	..##
	....

The positioning of the hashtags within the 4x4 square did not matter, so long as they formed one of the 19 valid tetris shapes. However, since the same shape could be represented in multiple positions as input, it made the project more challenging.

### How does Fillit work?

As described earlier, the goal of Fillit is to place a variable number of tetriminos (max of 26) into the smallest possible square area. To do so, I implemented a recursive backtracking algorithm. 

One important detail to note is that the program had to prioritize the solution that arranged blocks in their upper-left most positions.

The basic steps for how fillit works are as follows:

```

I. Read from the input file, check for errors and store the tetrimino data in a 2-D array

II. Find minimum area needed to fit all tetriminos and create initial map for solution.

III. Fill the map with tetriminos
	A. Place first piece in the top-left corner. 
	B. Attempt to place next piece in the first viable spot, and continue this pattern until 
	   a solution is reached or a piece doesn’t fit (in the case of the latter, move to step C)
	C. When a piece doesn't fit, move the PREVIOUS piece right to the next viable spot. Then repeat B.
	D. Continue pattern above until a solution is reached, or until the first piece has been moved 
	   to the end of the map and no solution has been reached. 	
	E. If first piece has exhausted all possible positions, and a solution cannot be reached; 
	   increment the map size and go back to step A.

```

My main contribution to the project was the solving algorithm and the helper functions that it requires. The actual code implementation of the algorithm resides in the file [fillitmain.c](https://github.com/beasleyz/42_Fillit/blob/master/fillitmain.c) within the function named **fillit**. The other functions called in this algorithm can be found in the file [place_tet.c](https://github.com/beasleyz/42_Fillit/blob/master/place_tet.c).

### How do I use it?

Alright so now that you know how it works, let's test it out.

You'll first need to clone the repository and cd into the directory:

	git clone https://github.com/beasleyz/42_Fillit.git Fillit
	cd Fillit

Then, you simply need to call `make` and an executable called fillit will be created.
From here, you can run `fillit` with one of the test files I've included named `smalltest` and `bigtest` in the directory `testfiles`:

	make
	./fillit testfiles/smalltest

For the **smalltest** file, your output should look like this:

	..A..
	AAAB.
	CBBB.
	CC...
	.C...

The **bigtest** file contains 21 tetriminos and should produce:

	AAABBBCCCD
	EAFFB.CDDD
	E.FFGGHHH.
	EE.GGKHII.
	JJJLLKK.II
	.NJLLPKMMM
	NNOOOP..MQ
	NTRROPPQQQ
	.T.RRS...U
	.TT.SSSUUU

Alternatively, if you'd like to go a little deeper and do some experimenting you can! I've added some tools that will help you to easily create your own test files with any number of tetriminos (no more than 26 of course). Then you can run `./fillit` with the file you've created.

To do so simply input the following commands:

	make -C create_tetros_file/
	./create_tetros_file/a.out "the number of tetriminos you want"
	./fillit tetriminos_file

Enjoy!

### Contributions

Fillit was a group project that I worked on with [Claudio Davila][2]. Basically, we approached the project by dividing the work into two parts: 

* reading the input (which included error checking and storing the data necessary) 
* and the solving algorithm that would find the smallest square grid and place the tetriminos.

Claudia wrote the code necessary to read and store the input, and I wrote the code for the solving algorithm. Though we each wrote our own code, we shared our ideas with each other throughout the project and provided feedback to each other. 

This was my first (relatively) large-scale collaborative coding project, at least the first where it was necessary to divide up the work. It was also my first experience working at times remotely on a project; we used github to share code while apart. 

**Note:** For any developers working on a large collaborative project for the first time, I highly recommend the approach outlined above. Discussing ideas before diving into code and keeping open lines of communication throughout will save you time at the end trying to tweak your code to make it "fit" together. It could even potentially save you from having to essentially start over.

It was a [beautiful moment][4] to join our code together and witness it pass all the tests on the first try :smiley:

[1]: https://www.42.us.org/ 
[2]: https://www.linkedin.com/in/claudia-davila-rios-09801b35
[3]: https://github.com/beasleyz/42_Fillit/blob/master/fillit.en.pdf
[4]: http://www.reactiongifs.com/r/wfa.gif