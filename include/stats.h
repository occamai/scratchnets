#ifndef __SCRATCHNETS_STATS__
#define __SCRATCHNETS_STATS__

/*
 * stats.h, declarations for some basic stats functions
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
 * distribution constants
 */

/*TODO: Change to enum*/
#define STATS_UNIFORM_DISTRIBUTION 0
#define STATS_NORMAL_DISTRIBUTION 1

/*
 * random variable
 */

typedef struct 
{
  int distribution;
} RandomVariable;

RandomVariable rv_make(int type);

int rv_sample( RandomVariable rv );

#endif /* __SCRATCHNETS_STATS__ */
