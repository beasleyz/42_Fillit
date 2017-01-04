
#include <stdio.h>
#include <stdlib.h>

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
		printf("i = %d\n", i );
		printf("j = %d\n", j);
		if(tet[j] != '\n' && (map[i + r] == '.' || map[i + r] == tet[j]))
			map[i + r] = tet[j];
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return(map);
}

// int check_valid(char *tet, char* map, int r) // doesn't work for vertical lines
// {
// 	int i;
// 	int count;  // char *tet1 = "B\nB\nB\nB";  "....\n....\n....\n....\n\0" i = 0
// 	int j;

// 	i = 0;
// 	j = 0;
// 	count = 0;
// 	if(map[r] != '.')
// 		return(0);
// 	while(map[i + r] != '\0' && tet[j] != '\0')
// 	{
// 		if(map[i + r] == '\n' && tet[j] != '\n')
// 			return(0);
// 		while (tet[j] == '\n' && map[i] != '\n')
// 			i++;
// 		if(map[i + r] == '.' && tet[j] != '.' && tet[j] != '\n')
// 			count++;
// 		if(count == 4)
// 			return(1);
// 		j++;
// 		i++;
// 	}
// 	return(0);
// }

int check_valid(char *tet, char* map, int r)  /// doesn't work for vertical line tets
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	printf("char = %c\n", map[i + r]);
	if(map[r] != '.' && map[r] != '\0')
		return(0);
	while(map[i + r] != '\0' && tet[j] != '\0')
	{
		printf("char = %c\n", map[i + r]);
		if(map[i + r] == '\n' && tet[j] != '\n')
			return(0);
		while (tet[j] == '\n' && map[i] != '\n') // to make this work for vertical lines change to map[i] != '\n'
			i++;
		if(map[i + r] == '.' && tet[j] != '.' && tet[j] != '\n')
			count++;
		if(count == 4)
			return(1);
		j++;
		i++;   // char *tet1 = "AAA\nA..";
	}
	if(map[i + r] == '\0') // not tested
		return(2);
	return(0);
}

int main()
{
	char *map;
	char *tet1 = "AAA\nA..";
	char *tet2 = "B\nB\nB\nB";
	char *tet3 = "C.\nCC\n.C";
	char *tet4 = "DD.\n.DD";
	char *tet5 = "E\nE\nE\nE";
	map = create_map(4);
	map = place_tet(tet1, map, 5);
	printf("valid = %d\n", check_valid(tet4, map, 20));
	printf("%s\n", map);
	printf("%d", index_of(tet2, map));
}








// char *move_to_right(char *tet, char *map, int r) // make this replace place_tet function and start with r = 0.
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (tet[j] != '\0' && map[i + r] != '\0') // while the tetrimino still has unplaced blocks && the position that we are attemping to place a block in exists
// 	{
// 		if((map[i + r] == '.' || map[i + r] == tet[j]) && tet[j] != '\n') // if space is vacant, place current block of the tetrimino
// 			map[i + r] = tet[j]; // maybe replace with a check for viability?
// 		else if(map[i + r] != '.' && map[i + r] != tet[j] && tet[j] != '\n' && tet[j] != '\0' && map[i + r] != '\0' && tet[j] != '.') // if any of the space is occupied when trying to place tetrimino, move to next space
// 		{
// 			map = move_to_right(map, tet, r + 1);
// 		}
// 		while(tet[j] == '\n' && map[i + r] != '\n' && map[i] != '\0')
// 			i++;
// 		i++;
// 		j++;
// 	}
// 	return(map);
// }
