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


#include "maths.h"
#include "perceptron.h"


int main(int argc, char **argv) {

	printf("Starting %s\n", argv[0]);

	float weights[3] = { 1.0f, 1.0f, 1.0f };
    int ret = 0;
    perceptron *p = NULL;
    float output = 0.0f;
    float bias = 1.0f;

    //ret = perceptron_init_from_weights( (unsigned long **)&p, 3, bias, weights );
    ret = perceptron_init_from_weights( &p, 3, bias, weights );
    if ( ret != 0 ) {
        printf("Could not init perceptron.\n");
        return -1;
    }

    ret = perceptron_forward( p, weights, &output );
    if ( ret !=0 ) {
        printf("Perceptron forward failed.\n");
        return -1;
    }
    if ( output != 4.0f ) {
        printf("Perceptron forward failed - %f\n", output );
        return -1;
    }
    
	printf("Ending %s\n", argv[0]);
    return 0;
}

