/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/15 18:21:42 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Check si on peut poser la piece
*/
static int	can_place(char **map, t_tri *minos, int i, int j, int size)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (i + minos->pos[k].x < 0 || i + minos->pos[k].x >= size)
			return (0);
		if (j + minos->pos[k].y < 0 || j + minos->pos[k].y >= size)
			return (0);
		if (map[j + minos->pos[k].y][i + minos->pos[k].x] != '.')
			return (0);
		k++;
	}
	return (1);
}

void		place_t(t_tri *lst, char **map, int i, int j)
{
	map[j][i] = lst->c;
	map[j + lst->pos[1].y][i + lst->pos[1].x] = lst->c;	
	map[j + lst->pos[2].y][i + lst->pos[2].x] = lst->c;	
	map[j + lst->pos[3].y][i + lst->pos[3].x] = lst->c;	
}

static void		remove_t(t_tri *lst, char **map, int i, int j)
{
   map[j][i] = '.';
   map[j + lst->pos[1].y][i + lst->pos[1].x] = '.';	
   map[j + lst->pos[2].y][i + lst->pos[2].x] = '.';	
   map[j + lst->pos[3].y][i + lst->pos[3].x] = '.';
}

/*
 * BACKTRACK HERE
 */


int    solve(t_tri *minos, char **map, int size)
{
	char 	**new_map;
    int i;
    int j;

    i = 0;
    new_map = (char **)malloc(sizeof(char *) *(size + 1));
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            new_map[i][j] = map[i][j];
            j++;
        }
        i++;
    }
    if (backtrack(minos, new_map, size) == 0)
    {
	    delete_map(map);
		new_map = create_map(size + 1);
    }
	return (0);
}

int		backtrack(t_tri *minos, char **map, int size)
{
	int i;
	int j;
	t_tri *start;

	j = 0;
	start = minos;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (can_place(map, minos, i, j, size))
			{
                place_t(minos, map, i, j);
                remove_t(minos, map, i, j);		// <--- NEW;
				printf("REMOVE: %c", minos->c);		// <--- NEW test;
			}
			i++;
		}
		j++;
	}
	return (0);
}
