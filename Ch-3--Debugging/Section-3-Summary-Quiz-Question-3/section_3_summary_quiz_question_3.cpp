#include <iostream>

/* Call Stack Looks like this at // HERE point
 *
 * d()
 * b()
 * a()
 * main()
 * 
 * Results: Correct!
 */

void d()
{ // HERE
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}