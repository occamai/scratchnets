/*
 * vector.c, definition of functions implementing vector math
 * 
 * Copyright (C) 2020 C. George Williams
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>

float vec_dot_product(float *a, float *b, int sz) {

	float sum = 0.0f;
	for (unsigned int i=0;i<sz;i++) {
		sum += (a[i]*b[i]);
	}
	return sum;	
	
}

void vec_print_col_vec(float *vec, int sz) {
	for (unsigned int i=0;i<sz;i++) {
		printf("%d:\t%f\n", i, vec[i]);
	}
}

unsigned int vec_equal(float *vec, int sz, float *compare)
{
	for (unsigned int i=0;i<sz;i++) {
		if ( vec[i] != compare[i] ) return 0;
	}
	return 1;
}
