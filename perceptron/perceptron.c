/*
 * perceptron.c, an example program demonstrating how a perceptron works
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

	float a[3] = { 1.0f, 1.0f, 1.0f };
	float b[3] = { 2.0f, 4.0f, 8.0f };

	float sum = vector_dot( a, b, 3 );

	printf("Vector dot=%f\n", sum );

	printf("Ending %s\n", argv[0]);

    	return 0;
}

