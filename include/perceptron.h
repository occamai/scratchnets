#ifndef __SCRATCHNETS_PERCEPTRON__
#define __SCRATCHNETS_PERCEPTRON__

/*
 * perceptron.h, declarations for functions demonstrating how a perceptron works
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

typedef struct {
    int     n_weights;
    float   bias;
    float   *weights;
} perceptron; 

int perceptron_version();

perceptron* perceptron_init();

//int perceptron_init_from_weights( unsigned long **_p, int n_weights, float bias, float *weights );
int perceptron_init_from_weights( perceptron **p, int n_weights, float bias, float *weights );

int perceptron_forward( perceptron *p, float *input, float *output );

int perceptron_destroy( perceptron* p );


void Foo(unsigned char** ppMem, int* pSize, unsigned long **l);

#endif /* __SCRATCHNETS_PERCEPTRON__ */
