/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:37:39 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/05 15:07:02 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef char			t_i8;
typedef unsigned char	t_u8;
typedef short			t_i16;
typedef unsigned short	t_u16;
typedef int				t_i32;
typedef unsigned int	t_u32;
typedef long			t_i64;
typedef unsigned long	t_u64;
typedef struct s_int2	t_int2;

struct					s_int2
{
	t_i32				x;
	t_i32				y;
};

#endif
