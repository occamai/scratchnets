/*
 * unittest.c, a unittest for the math functions
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
#include <assert.h>

#include "maths.h"

int main(int argc, char **argv) {

    printf("Starting %s\n", argv[0]);

    /*
     * vec_dot_product
     */
    float a[3] = { 1.0f, 1.0f, 1.0f };
    float b[3] = { 2.0f, 4.0f, 8.0f };
    float dot = vec_dot_product( a, b, 3 );
    printf("Vector dot=%f\n", dot );
	assert( dot==14.0f );

    /*
     * mat_mult_col_vec
     */	
    float mat[3][3] = {  {1.0f, 0.0f, 0.0f }, {0.0f, 1.0f, 0.0f}, { 0.0f, 0.0f, 1.0f } };
    float vec[3] = { 2.0f, 3.0f, 4.0f };
    float result[3] = {0.0f, 0.0f, 0.0f};
    mat_mult_col_vec( (float **)mat, 3, 3, vec, (float *)result );
    vec_print_col_vec(result, 3);
    float compare[3] = { 2.0f, 3.0f, 4.0f };
    assert( vec_equal( result, 3, compare )==1 );

    /*
     * vec_file_write
     */
    int err = vec_file_write("./vec.bin", vec, 3 );
    assert( err==0 );

    /*
     * vec_file_read
     */
    float *rvec = vec_file_read("./vec.bin" );
    assert( rvec!=NULL );
    assert( vec_equal( rvec, 3, compare )==1 );

    printf("Ending %s: All Tests Passed.\n", argv[0]);

    return 0;
}

