#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int index_of(char *tet, char *map) 
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(tet[i] == '.')
		i++;
	while(map[j] != '\0')
	{
		if (map[j] == tet[i] && tet[i] != '\n')
			return(j - i);
		j++;
	}
	return(0);
}

int check_valid(char *tet, char* map, int r)
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	if(map[r] != '.' && map[r] != '\0')
		return(0);
	while(map[i + r] != '\0' && tet[j] != '\0')
	{
		if(map[i + r] == '\n' && tet[j] != '\n')
			return(0);
		while (tet[j] == '\n' && map[i] != '\n')
			i++;
		if(map[i + r] == '.' && tet[j] != '.' && tet[j] != '\n')
			count++;
		if(count == 4)
			return(1);
		j++;
		i++;
	}
	if(map[i + r] == '\0')
		return(2);
	return(0);
}

char *remove_tet(char *tet, char *map)  // WORKING
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(tet[i] == '.')
		i++;
	while(map[j] != '\0')
	{
		if (map[j] == tet[i])
			map[j] = '.';
		j++;
	}
	return(map);
}

char *place_tet(char *tet, char *map, int r)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tet[j] != '\0')  // char *tet1 = "B\nB\nB\nB";  "....\n....\n....\n....\n\0" i = 0
	{
		if(tet[j] != '\n' && (map[i + r] == '.' || map[i + r] == tet[j]))
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
	while (tet[i] && check_valid(tet[i], map, j) != 2 && j <= size * (size + 1))
	{
		if(check_valid(tet[i], map, j) == 1) // check if there is a vacant slot. If so, place the tetrimino here.
		{
			map = place_tet(tet[i], map, j);  // place tetrimino on solution map, and continue with next tetrimino.
			j = 0;
			i++;
			if (i == 4) // figure out total number of tets, and if tets placed is the same, you have arrived.
				return(map);
		}
		if (check_valid(tet[i], map, j) == 0) // WORKS
			j++;
	}
	printf("%s\n", map);
	if (check_valid(tet[i], map, j) == 2 && i != 0 ) 
	{
		r = index_of(tet[i - 1], map);
		map = fillit(tet, remove_tet(tet[i - 1], map), r + 1, i - 1, size);
	}
	if (tet[i] && check_valid(tet[i], map, j) == 2  && i == 0) // WORKS ----- increases map size after checking all possible solutions.
	{
		free(map);
		map = fillit(tet, create_map(size + 1), 0, 0, size + 1); 
	}
	return(map);
}


int main(int argc, char **argv)
{
	char *map;
	char *tet1 = "AAA\nA..";
	char *tet2 = "B\nB\nB\nB";
	char *tet4 = ".DD\nDD.";
	char *tet3 = "E\nE\nE\nE";

	char **tet = (char**)malloc(sizeof(char*) * 5);
	tet[0] = tet1;
	tet[1] = tet2;
	tet[2] = tet3;
	tet[3] = tet4;
	tet[4] = NULL;


	map = fillit(tet, create_map(3), 0, 0, 3);
	printf("%s\n", map);
	// loop through each tetrimino to place it in the map.
		// if a tetrimino fits, continue to next tetrimino
		// if a tetrimino doesn't fit in any of the spaces, go back to the last tetrimino and move it over to next valid space. 
		// then return to next tetrimino and try to place it again. Repeat until it fits (then move to next or return map if valid solution) or all spaces for previous tetrimino are exhausted.
		// If all valid spaces are exhausted and current tetrimino still doesn't fit. Move back another tetrimino and repeat process.
		// If all possibilities of the first tetrimino are exhausted, increase the size of the map and start again from beginning.
	
	return 0;
}