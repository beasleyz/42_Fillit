/* ---------------------- 


I. Read from one and only one file given as argument. If there is not exactly 1 argument, display program usage.
	A. Ensure correct format
		a. If tetrimino is not four lines long, exit program with error message.
		b. If tetrimino is not four characters on each line, exit program with error message.
		c. If there is a character that is not '#' or '\n' or '.' then exit program with error message.
		d. Each block must be touching another block on at least one side. 
		e. If there is more than ONE newline in a row, exit program with error.
		d. If there are more than 26 tetriminos in a file, exit with error.
	B. The order of the tetriminos must be retained
		a. Change the '#' to the letter that corresponds with order. (ie. the first tetrimino would change '#' to 'A')
	C. Store the tetrimino in some way?

II. Create map for solution.
	A. Start at minimum size which is 2x2. Initialize values to '.'
		a. malloc size for string and initialize to '.' ---- ((width + 1) * width + 1)
		b. str[(width + 1) * width] = '/0'

III. Fill Map
	A. Place first piece in the top-left corner. If it doesn't fit -> increment map size.
	B. Attempt to place next piece in the first viable spot, moving it over to the right until it fits. If it doesn't fit go to step C.
	C. When a piece doesn't fit, move the PREVIOUS piece right to the next viable spot. Then repeat B.
	D. If the pieces do not fit together within the map, increase the map size by one unit and repeat process.


