/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:44:45 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/15 18:26:02 by bod              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	char	**map;
	int		size;
	int		i;

	i = 4;
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (ac == 2)
	{
		if ((size = input(av[1])))
		{
			map = create_map(size);
                printf("Debug2\n");
		    lst = parse(av[1]);
		    while (lst)
			{
				solve(lst, map, size);
				lst = lst->next;
			}
			print_map(map, size);
		}
		else
			ft_putstr("Error");
	}
	return (0);
}
