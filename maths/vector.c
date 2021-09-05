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
#include <stdlib.h>
#include <string.h>

float
vec_dot_product
(float *a, float *b, int sz) 
{

	float sum = 0.0f;
	for (unsigned int i=0;i<sz;i++) {
		sum += (a[i]*b[i]);
	}
	return sum;	
	
}

void
vec_print_col_vec
(float *vec, int sz) 
{
	for (unsigned int i=0;i<sz;i++) {
		printf("%d:\t%f\n", i, vec[i]);
	}
}

unsigned int
vec_equal
(float *vec, int sz, float *compare)
{
	for (unsigned int i=0;i<sz;i++) {
		if ( vec[i] != compare[i] ) return 0;
	}
	return 1;
}

int
vec_file_write
(char *path, float *vec, unsigned int num )
{
    FILE *fp = fopen( (const char *)path, "wb+" );
    if (fp==NULL) {
        printf("ERROR: Could not write file.\n");
        return -1;
    }
  
    float *wvec = vec; 
    for (int i=0;i<num;i++) {
        size_t bwritten = fwrite( wvec, sizeof(float), 1, fp );
        if (bwritten!=1) {
            printf("ERROR: Expected to write 1 element but got %ld\n", bwritten );
            return -1;
        }
        wvec += 1;
    }
    
    int err = fflush(fp);
    if (err!=0) {
        printf("WARNING: Unexpected error flushing file (%d).\n", err);
    }
  
    err = fclose(fp);
    if (err!=0) {
        printf("WARNING: Unexpected error closing file (%d).\n", err);
    }
 
    return 0;
}

float *         // a malloc pointer is returned
vec_file_read
(char *path)
{
    FILE *fp = fopen( (const char *)path, "rb" );
    if (fp==NULL) {
        printf("ERROR: Could not open file.\n");
        return NULL;
    }
   
    int err = fseek(fp, 0, SEEK_END); // seek to end of file
    if (err!=0) {
        printf("ERROR: Could not seek to end of file.\n");
        return NULL;
    }

    int size = ftell(fp); // get current file pointer to get the size

    // check is evenly divisible by float size
    if ( ( size % sizeof(float) )!=0 ) {
        printf("ERROR: file size (%d) is not evenly divisible by %ld.\n", size, sizeof(float));
        
        err = fclose(fp);
        if (err!=0) {
            printf("WARNING: Unexpected error closing file (%d).\n", err);
        }
        
        return NULL;
    }

    err = fseek(fp, 0, SEEK_SET); // seek back to beginning of file
    if (err!=0) {
        printf("ERROR: Could not seek to beginning of file.\n");
        return NULL;
    }

    // allocate memory for the vector
    float *nvec = (float *)malloc( size );
    if (nvec==NULL) {
        printf("ERROR: Could not allocate memory of size %d bytes.\n", size);
        
        err = fclose(fp);
        if (err!=0) {
            printf("WARNING: Unexpected error closing file (%d).\n", err);
        }
        
        return NULL;
    }
 
    // read a float at a time until EOF
    float *wvec = nvec;
    while (1) {
        float fval;
        size_t bread = fread( (void *)&fval, sizeof(float), 1, fp );
        if (bread==0) {
            // We are assuming we've reached end of file.
            break;
        }
        else if (bread!=1) {
            printf("ERROR: Expected to read 1 element but got %ld.\n", bread);
            err = fclose(fp);
            if (err!=0) {
                printf("WARNING: Unexpected error closing file (%d).\n", err);
            }
            return NULL;
        }
        printf("Got float %f\n", fval );

        void *bcpy = memcpy( (void *)wvec, (const void *)&fval, (size_t)sizeof(float));
        if (bcpy!=wvec) {
            printf("ERROR: Memcpy failed.\n");
            err = fclose(fp);
            if (err!=0) {
                printf("WARNING: Unexpected error closing file (%d).\n", err);
            }
            return NULL;
        }

        wvec += 1;
    }
    
    err = fclose(fp);
    if (err!=0) {
        printf("WARNING: Unexpected error closing file (%d).\n", err);
    }

    return nvec;
}



