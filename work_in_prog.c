#include <stdio.h>
#include <stdlib.h>

/* -------------------------------------- CREATES INITIAL MAP FOR SOLVING ----------------------------------------------- */

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

/* --------------------------------------------------- end --------------------------------------------------------------- */



/* ---------------------------------- RECURSIVELY MOVES TETRIMINO UNTIL IT FITS ------------------------------------------ */

char *move_tet_right(char *map, char *tet, int r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[j] != '\0')
	{
		if((map[i + r] == '.' || map[i + r] == tet[j]) && tet[j] != '\n')
			map[i + r] = tet[j];
		if(map[i + r] != '.' && map[i + r] != tet[j] && tet[j] != '\n')
			map = move_tet_right(tet, map, r + 1);
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return(map);

}

/* --------------------------------------------------- end --------------------------------------------------------------- */

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
		if(map[i] == '.')
			map[i] = tet[j];
		if(map[i] != '.' && map[i] != '\n' && tet[j] != '\0' && tet[j] != '\n')
			map = move_tet_right(tet, map, r);
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return(map);
}

/* vvvvv working* vvvv */
char *place_tet(char *tet, char *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[j] != '\0')
	{
		if(tet[j] != '\n')
			map[i] = tet[j];
		while(tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return(map);
}

int main()
{
	char *map;
	char *tet1 = "A\nA\nA\nA";
	char *tet2 = "B\nB\nB\nB\n";
	map = create_map(4);
	map = place_tet(tet1, map);
	printf("%s",map);
}