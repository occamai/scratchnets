/*
 * unittest.c, an example program demonstrating how a perceptron works
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
#include "perceptron.h"


int main(int argc, char **argv) {

	printf("Starting %s\n", argv[0]);

	float weights[3] = { 1.0f, 1.0f, 1.0f };
    int ret = 0;
    perceptron *p = NULL;
    float bias = 1.0f;

    /*
     * Create perceptron from const weights and bias
     */
    ret = perceptron_init_from_weights( &p, 3, bias, weights );
    assert ( ret == 0 );

    float output = 0.0f;
    ret = perceptron_forward( p, weights, &output );
    assert ( ret == 0 );
    assert ( output == 4.0f );

    /*
     * Create perceptron from random weights and bias
     */
    float ranweights[3];
    vec_random(ranweights,3, 0.0f, 0.1f);
    float ranbias = (float)float_random(0.0f, 0.1f);
    ret = perceptron_init_from_weights( &p, 3, ranbias, ranweights );
    assert ( ret == 0 );

    // randomize training set
    float trainvecs[10][3];
    for (int i=0;i<10;i++) {
        vec_random( trainvecs[i], 3, 0.0f, 1.0f );
    
        ret = perceptron_forward( p, trainvecs[i], &output );
        assert( ret==0 );
        printf("output=%f\n", output);
    }
 
	printf("All Tests Passed: Ending %s\n", argv[0]);
    return 0;
}

