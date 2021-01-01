/*
 * perceptron.c, definition of functions implementing the perceptron
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
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "maths.h"
#include "perceptron.h"

static int _perceptron_validate(perceptron *p);

void Foo(unsigned char** ppMem, int* pSize, unsigned long** l)
{
	printf("long %lu\n", (unsigned long)l);
    char i;
    *pSize = 4;
    *ppMem = malloc(*pSize);
    for(i = 0; i < *pSize; i++)
        (*ppMem)[i] = i;
}

int perceptron_version() {
    return 1;
}

perceptron* perceptron_init() {
    perceptron *p = (perceptron *)malloc(sizeof(perceptron));
    if ( p == NULL ) {
        return NULL;
    }
	return p;
}

//int perceptron_init_from_weights(  unsigned long **_p, int n_weights, float bias, float *weights ) {
int perceptron_init_from_weights(  perceptron **p, int n_weights, float bias, float *weights ) {

#ifdef SCRATCHNETS_DEBUG_LEVEL
	printf("long %lu\n", (unsigned long)p);
#endif

	//perceptron **p = (perceptron **)_p;
    if (p==NULL) {
		printf("passed null object ptr\n");
        return 1;
    }

    if (weights==NULL) {
		printf("null weights passed\n");
        return 1;
    }

    if (n_weights<=0) {
		printf("invalid weight count\n");
        return 1;
    } 

#ifdef SCRATCHNETS_DEBUG_LEVEL
	printf("weights %d - ", n_weights);
	for (int i=0;i<n_weights;i++) {
		printf(" %f", weights[i]);
	}
	printf("\n");
#endif
    *p = (perceptron *)malloc(sizeof(perceptron));
    if ( p == NULL ) {
        return 1;
    }

    (*p)->weights = malloc(sizeof(float)*n_weights);
    if ( (*p)->weights == NULL ) {
        free( p );
        p = NULL;
        return 1;
    }

#ifdef SCRATCHNETS_DEBUG_LEVEL
	printf("bias=%f\n", bias);
#endif
    memcpy( (void *)( (*p)->weights ), (void *)weights, sizeof(float)*n_weights );
    (*p)->n_weights = n_weights;
    (*p)->bias = bias;

    return 0; 
}

int perceptron_forward( perceptron *p, float *input, float *output ) {

    if ( _perceptron_validate(p) != 0 ) {
        return 1;
    }
   
    *output = vec_dot_product( p->weights, input, p->n_weights );
    *output += p->bias;
    return 0; 

}

int perceptron_hardlim( perceptron* p, float *decision_boundary ) {

    if ( _perceptron_validate(p) != 0 ) {
        return 1;
    }

    if ( decision_boundary == NULL ) {
        return 1;
    }

    return 0;
}


int perceptron_destroy( perceptron* p ) {

    if ( _perceptron_validate(p) != 0 ) {
        return 1;
    }

    free(p->weights);
    p->weights=NULL;
    free(p);
    p=NULL;

    return 0;
}

static int _perceptron_validate(perceptron *p) {
    
    if (p==NULL) {
        return 1;
    }

    if (p->weights==NULL) {
        return 1;
    }
    
    if (p->n_weights<=0) {
        return 1;
    }

    return 0;
}

