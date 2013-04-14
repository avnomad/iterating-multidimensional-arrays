//	Copyright (C) 2009, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of iterating multidimensional arrays.
 *
 *	iterating multidimensional arrays is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	iterating multidimensional arrays is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with iterating multidimensional arrays.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::clog;
using std::left;

#include <CPU clock.h>

typedef unsigned int uint;

int main()
{
	const uint N = 600;
	const uint M = 600;
	const uint K = 600;
	const uint P = N*M*K;
	const uint C = M*K;

	uint *table = new uint[N*M*K];
	uint i,j,k;
	uint *p,*q,*r,*ps,*qs,*rs;
	uint c ;
	double t;

	t = CPUclock::currentTime();
	cout << CPUclock::currentTime() - t << CPUclock::getUnit() << endl;

	/* test 1 */
	t = CPUclock::currentTime();
	c = 0;
	for(i = 0 ; i < N ; ++i)
		for(j = 0 ; j < M ; ++j)
			for(k = 0 ; k < K ; ++k)
				*(table + (M*i+j)*K + k) = c++;
	cout << CPUclock::currentTime() - t << CPUclock::getUnit() << endl;

	/* test 2 */
	t = CPUclock::currentTime();
	c = 0;
	ps = table + P;
	for(p = table ; p < ps ; )
	{
		q = p;
		p += C;
		for( ; q < p ; )
		{
			r = q;
			q += K;
			for( ; r < q ; ++r)
				*r = c++;
		} // end for
	} // end for
	cout << CPUclock::currentTime() - t << CPUclock::getUnit() << endl;

	/* test 3 */
	t = CPUclock::currentTime();
	c = 0;
	for(i = 0 ; i < P ; ++i)
		*(table + i) = c++;
	cout << CPUclock::currentTime() - t << CPUclock::getUnit() << endl;

	/* test 4 */
	t = CPUclock::currentTime();
	c = 0;
	ps = table + P;
	for(p = table ; p < ps ; ++p)
		*p = c++;
	cout << CPUclock::currentTime() - t << CPUclock::getUnit() << endl;



	delete[] table;
	system("PAUSE");
	return 0;
} // end function main
