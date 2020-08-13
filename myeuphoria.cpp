
// myeuphoria.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myobject.h"


int main()
{
	myobject st("Hi world!\n");
	object ob1 = { 0,0 }, ob2 = { 0,0 };
	myobject a, b, c, d;
	myobject * _a, *_b, *_c, *_d;
	char * ptr;
	char str[] = "ABC";

	// 1:
	printf("sizeof(SIZE_T) is: %d\n", sizeof(SIZE_T));
	// 2:
	printf("st.length() = %llu\n", (unsigned long long)st.length());
	// 3:
	printf("SEQ(st, -1) is: %lli\n", SEQ(st, -1).i64());
	// 4:
	a = 4LL;
	b = 4.5;
	c = "123";
	a.print();
	printf(", a is: atom==%d, integer==%d\n", a.is_atom(), a.is_integer());
	b.print();
	printf(", b is: atom==%d, integer==%d\n", b.is_atom(), b.is_integer());
	c.print();
	printf(", c is: atom==%d, integer==%d\n", c.is_atom(), c.is_integer());
	// 5:
	// To be completed.

/*
	a = str.copy_object();
	delete_object(a); // frees everything except for the top-level pointer

	str = "HI\n";

	str.print();
	puts("\n");
	*/
	/*
	str = "Hi\n";

	str = a;

	ptr = str.to_string();
	printf("%s\n", ptr);

	free(ptr);
	//myobject::free_myobjects();

	str = a;
	*/

	//str.delete_myobject();
	/*
	delete[] a.seq;
	*/
	puts("Hi world.\n");
	getc(stdin);
	return 0;
}

