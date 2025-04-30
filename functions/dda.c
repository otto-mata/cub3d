typedef struct {
	float x;
	float y;
} Coords;

int digital_differencial(Coords *map, Coords *dist, Coords *os, Coords *ds)
{
	int	dir;

	dir = 2;
	while (1)
	{
		if (dist->x < dist->y)
		{
			dist->x += ds->x;
			map->x += os->x;
			dir = 0;
		}
		else
		{
			dist->y += ds->y;
			map->y += os->y;
			dir = 1;
		}
		if (map_value_at(map) == '1')
			break ;
	}
	return (dir);
}
