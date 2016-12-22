#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int check_valid(char *tet, char* map, int r)
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	// if(strcmp(tet, "AAA\nA..") == 0)
	// 	printf("%s\n", "break" );
	if(map[r] != '.')
		return(0);
	count++;
	while(map[i + r] != '\0' && tet[j] != '\0')
	{
		if(map[i + r] == '\n' && tet[j] != '\n')
			return(0);
		while (tet[j] == '\n' && map[i + r] != '\n')
			i++;
		if(map[i + r] == '.' && tet[j] != '.' && tet[j] != '\n')
			count++;
		if(count == 4)
			return(1);
		j++;
		i++;
	}
	if(map[i + r] == '\0') // not tested
		return(2);
	return(0);
}


// char *move_tet_right(char *map, char *tet, int r)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (tet[j] != '\0' && map[i + r] != '\0') // while the tetrimino still has unplaced blocks && the position that we are attemping to place a block in exists
// 	{
// 		if((map[i + r] == '.' || map[i + r] == tet[j]) && tet[j] != '\n') // if space is vacant, place current block of the tetrimino
// 			map[i + r] = tet[j];
// 		else if(map[i + r] != '.' && map[i + r] != tet[j] && tet[j] != '\n' && tet[j] != '\0' && map[i + r] != '\0') // if any of the space is occupied when trying to place tetrimino, move to next space
// 		{
// 			map = move_tet_right(map, tet, r + 1);
// 		}
// 		while(tet[j] == '\n' && map[i] != '\n' && map[i] != '\0')
// 			i++;
// 		i++;
// 		j++;
// 	}
// 	// if(tet[0] == 'E')
// 	// 	printf("%c\n", map[r]);
// 	if(map[r] == '\0')
// 	{
// 		printf("%c\n", 'o');
// 		return(0);
// 	}
// 	return(map);

// }

char *place_tet(char *tet, char *map, int r)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tet[j] != '\0')
	{
		if(map[i + r] == tet[j] && tet[j] != '\n')
		{
			i++;
			j++;
		}
		if(tet[j] != '\n' && map[i + r] == '.')
			map[i + r] = tet[j];
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return(map);
}

char *fillit(char **tet, char *map, int j, int i, int size)
{
	int r;
	
	r = j;
	while (tet[i] && j < size * size + 1)
	{
		printf("valid = %d\n", check_valid(tet[i], map, j));
		if(check_valid(tet[i], map, j) == 1) // check if there is a vacant slot. If so, place the tetrimino here.
		{
			place_tet(tet[i], map, j);  // place tetrimino on solution map, and continue with next tetrimino.
			r = j; // if a tet is placed, save the index of first position.
			i++;
		}
		if (check_valid(tet[i], map, j) == 0) // NOT TESTED
			j++;
		 // if (check_valid(tet[i], map, j) == 2 && i != 0)  // NOT TESTED
			// map = fillit(tet, map, r + 1, i - 1, size); // if a tet doesn't fit anywhere on the map, go back to previous tet (i - 1) and try to place in next valid spot (r + 1);
		

		 // if (check_valid(tet[i], map, j) == 2 && i == 0) // if you are on the first tettrimino and it doesn't fit, increase the map size.
			// printf("%s\n", "test");// fillit(tet, create_map(size + 1), 0, 0); // NOT TESTED

			
		if(i == 3) // figure out total number of tets and if tets placed is the same you have arrived.
			return(map);
	}
	printf("j = %d\n", j);
	printf("s = %d\n", size);
	if(j == size * size + 1)
		fillit(tet, create_map(size + 1), 0, 0, size + 1); // NOT TESTED
	return(map);
}


int main(int argc, char **argv)
{
	char *map;
	char *tet1 = "AAA\nA..";
	char *tet2 = "B\nB\nB\nB";
	char *tet3 = "C.\nCC\n.C";
	char *tet4 = "DD\n.D\n.D";

	char **tet = (char**)malloc(sizeof(char*) * 4);
	tet[0] = tet1;
	tet[1] = tet2;
	tet[2] = tet4;
	tet[3] = NULL;


	// if (argc != 2)
	// {
	// 	printf("%s\n", "error");
	// 	return (0);
	// }
	map = create_map(4);
	printf("%d\n",check_valid(tet[0], map, 0));
	// read from file. if not valid, return.
	// return char **tet with each pointer in array being a tetrimino.
	map = fillit(tet, create_map(5), 0, 0, 5);
	printf("%s\n", map);
	// loop through each tetrimino to place it in the map.
		// if a tetrimino fits, continue to next tetrimino
		// if a tetrimino doesn't fit in any of the spaces, go back to the last tetrimino and move it over to next valid space. 
		// then return to next tetrimino and try to place it again. Repeat until it fits (then move to next or return map if valid solution) or all spaces for previous tetrimino are exhausted.
		// If all valid spaces are exhausted and current tetrimino still doesn't fit. Move back another tetrimino and repeat process.
		// If all possibilities of the first tetrimino are exhausted, increase the size of the map and start again from beginning.
	
	return 0;
}

