#ifndef __SCRATCHNETS_MATHS__
#define __SCRATCHNETS_MATHS__

/*
 * maths.h, declarations for some basic math functions
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


/*
 * vector math functions
 */

float           vec_dot_product(float *a, float *b, int sz);
void            vec_print_col_vec(float *vec, int sz);
unsigned int    vec_equal(float *vec, int sz, float *compare);

int             vec_file_write (char *path, float *vec, unsigned int num );
float           *vec_file_read(char *path);

float           float_random(float min, float max);
int             vec_random(float *vec, int sz, float min, float max);

/*
 * matrix math functions
 */

void            mat_mult_col_vec(float **mat, int rows, int columns, float *vec, float *result);

#endif /* __SCRATCHNETS_MATHS__ */
