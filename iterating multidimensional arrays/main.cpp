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