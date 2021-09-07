/*
 * matrix.c, definition of functions implementing matrix math
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

void mat_mult_col_vec(float mat[3][3], int rows, int columns, float *vec, float *result) {

	for (int i=0;i<rows;i++) {
		result[i] = 0.0f;
		for ( int j=0;j<columns;j++) {
			//printf("%d %d\n", i, j);
			//printf("val=%f\n",mat[i][j] );
			result[i] += mat[i][j]*vec[j];
		}
	}
}
