/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhivert <bhivert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 13:46:20 by bhivert           #+#    #+#             */
/*   Updated: 2016/06/15 19:43:47 by bhivert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	fdf_z_lower_zero(t_color zero, t_color min, double fact_z)
{
	t_color		ret;

	ret = new_color_rgb(zero.rgb[E_RED] \
				- (fact_z * (min.rgb[E_RED] - zero.rgb[E_RED]) / 100), \
			zero.rgb[E_GREEN] \
				- (fact_z * (min.rgb[E_GREEN] - zero.rgb[E_GREEN]) / 100), \
			zero.rgb[E_BLUE] \
				- (fact_z * (min.rgb[E_BLUE] - zero.rgb[E_BLUE]) / 100));
	return (ret);
}

static t_color	fdf_z_upper_zero(t_color zero, t_color max, double fact_z)
{
	t_color		ret;

	ret = new_color_rgb(zero.rgb[E_RED] \
				+ (fact_z * (max.rgb[E_RED] - zero.rgb[E_RED]) / 100), \
			zero.rgb[E_GREEN] \
				+ (fact_z * (max.rgb[E_GREEN] - zero.rgb[E_GREEN]) / 100), \
			zero.rgb[E_BLUE] \
				+ (fact_z * (max.rgb[E_BLUE] - zero.rgb[E_BLUE]) / 100));
	return (ret);
}

t_color			set_color(t_env *e, double z)
{
	t_color		max;
	t_color		min;
	t_color		zero;
	t_color		ret;
	double		fact_z;

//	max = new_color_hex(0xE67E30);
//	min = new_color_hex(0x003BFF);
	max = new_color_hex(0x663300);
	min = new_color_hex(0x0066FF);
	zero = new_color_hex(0x006600);
	fact_z = z * 100 / e->max_value;
	if (z == 0)
		return (zero);
	else if (z < 0)
	{
		ret = fdf_z_lower_zero(zero, min, fact_z);
	}
	else
		ret = fdf_z_upper_zero(zero, max, fact_z);
	return (ret);
}
