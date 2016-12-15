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


----------------------- */

#include <stdio.h>
#include <stdlib.h>


// int width;

// width = 2;

char *create_map(int width)
{
	char *map;
	int strlen;
	int current;
	int i;

	i = 0;
	current = width;
	strlen = (width + 1) * width;
	map = (char*)malloc(sizeof(char) * (strlen + 1));
	if (!map)
		return NULL;
	while (i < strlen)
	{
		if(i == width || i == (current + width + 1))
		{
			map[i] = '\n';
			current = i;
		}
		else
			map[i] = '.';
		i++;
	}
	map[strlen] = '\0';
	return(map);
}

char *move_tet_right(char *map, char *tet, int r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[j] != '\0' && map[i + r] != '\0') // while the tetrimino still has unplaced blocks && the position that we are attemping to place a block in exists
	{
		if((map[i + r] == '.' || map[i + r] == tet[j]) && tet[j] != '\n') // if space is vacant, place current block of the tetrimino
			map[i + r] = tet[j];
		else if(map[i + r] != '.' && map[i + r] != tet[j] && tet[j] != '\n' && tet[j] != '\0' && map[i + r] != '\0') // if any of the space is occupied when trying to place tetrimino, move to next space
		{
			map = move_tet_right(map, tet, r + 1);
		}
		while(tet[j] == '\n' && map[i] != '\n' && map[i] != '\0')
			i++;
		i++;
		j++;
	}
	// if(tet[0] == 'E')
	// 	printf("%c\n", map[r]);
	if(map[r] == '\0')
	{
		printf("%c\n", 'o');
		return(0);
	}
	return(map);

}

char *place_tet(char *tet, char *map)
{
	int i;
	int j;
	int r;

	r = 1;
	i = 0;
	j = 0;
	while (tet[j] != '\0') 
	{
		if(tet[j] != '\n' && (map[i] == '.' || map[i] == tet[j]))
			map[i] = tet[j];
		else if(map[i + r] != '\0' && tet[j] && tet[j] != '\n' && map[i] != '.' && map[i] != tet[j]) // If the space isn't vacant
		{
			map = move_tet_right(map, tet, r);
			printf("%s\n", map);
			return(map);
		}
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	if(map[i] == '\0' && tet[j] != '\0')
		return NULL;
	return(map);
}

// int check_if_vacant(char *tet, char *map)
// {
// 	int t_width;

// 	t_width = 0;
// 	while(tet[i] != '\0')
// 	{
// 		if(tet[i] == c)
// 			t_width++;
// 		if
// 	}
// }

int fillit(char **tet, char *map)
{
	char **tet;
	int i = 0;
	int j = 0;

	while (*tet)
	{
		if(check_if_vacant(tet[i], map, j) == 1) // check if there is a vacant slot. If so, place the tetrimino here.
		{
			place_tet(tet[i], map, j);  // place tetrimino on solution map, and continue with next tetrimino.
			i++;
		}
		if(i = num_of_tets)
			return(map);
	}

}
