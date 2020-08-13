
#pragma once

/*
Built-in Euphoria v4.0 functions to translate into C++

atom -- done
integer -- done
object -- done
sequence -- done

length -- done
repeat -- done

compare -- done
equal -- done

and_bits -- done
not_bits -- done
or_bits -- done
xor_bits -- done

append -- done
prepend -- done

find -- done
match

floor -- done
remainder -- done

head
tail
insert
remove
replace
splice

mem_copy
mem_set

subscripting -- done

print() -- done

*/

//#define PLATFORM_64

#ifdef PLATFORM_64

// For 64-bit programming:
#define SIZE_T unsigned long long
//#define LENGTH(S) (((S).length64<<3)>>3)
#define LENGTH(S) ((S).length64 & 0x1FFFFFFFFFFFFFFFull)

#else

// For 32-bit programming:
#define SIZE_T unsigned int
#define LENGTH(S) ((S).length)

#endif // PLATFORM_64

#define MAKE_EMPTY_SEQ() data = { 0,0 }


// way of using an index:
//#define INDEX_OF_SEQ(S,I) (S)[((I)>0)?(I)-1:(I)+(S).length()]
#define SEQ(S,I) (S)[((I)>0)?(I)-1:(I)+(S).length()]

// c = (a>b) ? 25 : 45;

#define IS_ATOM(S) ((S).is_atom==1)
#define IS_INTEGER(S) ((S).is_integer==1)
#define IS_SEQUENCE(S) ((S).is_atom==0)
//#define IS_COPY(S) ((S).is_it_a_copy==1)

typedef struct struct1 {
	union {
		long long i64;
		void * ptr;
		double dbl;
		class myobject * myob; // only used for debugging
	};
	union {
		unsigned long long length64;
		unsigned int length;
		struct {
			unsigned long long _reserved : 61;
			unsigned long long is_it_a_copy : 1;
			unsigned long long is_integer : 1;
			unsigned long long is_atom : 1;
		};
	};
	//void * up; // notice: pointer to parent branch of node
} *pobject, object;


static void del_object(object& data);
void delete_object(object& data);

class myobject
{
private:
	object data;
public:
	void myobject::del_myobject();
	void myobject::delete_myobject();
	myobject();
	myobject(double);
	myobject(long long);
	myobject(const object&); // object passed by reference (pointer)

	myobject(object * ob, SIZE_T length); // objects passed by reference (pointer)
	myobject(myobject * myob, SIZE_T length);

	myobject(const char * str, SIZE_T length);
	myobject(const char * str);
	myobject(const long long *, SIZE_T);
	myobject(const double *, SIZE_T);
	myobject(myobject&, SIZE_T); // repeat(), for sequence creation
	myobject(myobject&, myobject&); // concat two sequences into a new sequence
	~myobject();
	myobject& myobject::operator= (myobject&);
	myobject& myobject::operator= (long long);
	myobject& myobject::operator= (double);
	myobject& myobject::operator= (const char *);
	myobject& myobject::operator= (const object&); // object passed by reference (pointer)

	myobject& myobject::operator[] (SIZE_T); // NOTICE: seq indexes start at 1, offsets start at 0, a[0] is the first element
	myobject& myobject::operator += (const myobject&);
	myobject& myobject::operator -= (const myobject&);
	myobject& myobject::operator *= (const myobject&);
	myobject& myobject::operator /= (const myobject&);

	myobject& myobject::operator %= (const myobject&);
	myobject& myobject::operator ^= (const myobject&);
	myobject& myobject::operator &= (const myobject&);
	myobject& myobject::operator |= (const myobject&);

	myobject& myobject::operator <<= (const myobject&);
	myobject& myobject::operator >>= (const myobject&);

	myobject myobject::operator + (const myobject&);
	myobject myobject::operator - (const myobject&);
	myobject myobject::operator * (const myobject&);
	myobject myobject::operator / (const myobject&);

	myobject myobject::operator % (const myobject&);
	myobject myobject::operator ^ (const myobject&);
	myobject myobject::operator & (const myobject&);
	myobject myobject::operator | (const myobject&);

	myobject myobject::operator << (const myobject&);
	myobject myobject::operator >> (const myobject&);

	SIZE_T const myobject::length();

	long long const myobject::i64();
	double const myobject::dbl();

	// NOTICE: seq indexes start at 1, offsets start at 0, a[0] is the first element
	// subscripting, starts at 1, example subscript = a.slice(1,-1);
	myobject myobject::slice(long long, long long);

	bool const myobject::is_atom();
	bool const myobject::is_dbl();
	bool const myobject::is_integer();
	bool const myobject::is_seq();

	// Todo: try to make these faster:
	myobject& myobject::append(myobject&);
	myobject& myobject::prepend(myobject&);

	myobject& myobject::floor_self();

	myobject& myobject::to_int(); // long long value
	myobject& myobject::to_float(); // double value
	char * myobject::to_string(); // converts it into a NULL-terminated character string

	myobject& myobject::to_bit(unsigned long long bits);

	object myobject::dup_object(); // returns a copy of an object

	void myobject::print();

	unsigned long long myobject::find(myobject&);
};

// related functions:

myobject repeat(myobject& ob, SIZE_T n);

long long compare(myobject&, myobject&);
bool equal(myobject&, myobject&);

bool operator< (myobject&, myobject&);
bool operator> (myobject&, myobject&);
bool operator== (myobject&, myobject&);
bool operator!= (myobject&, myobject&);
bool operator<= (myobject&, myobject&);
bool operator>= (myobject&, myobject&);

myobject operator-(const myobject& ob); // negate() function
myobject operator~(const myobject& ob); //myobject not_bits(myobject a);

myobject and_bits(myobject& a, myobject& b);
myobject or_bits(myobject& a, myobject& b);
myobject xor_bits(myobject& a, myobject& b);
myobject not_bits(myobject& a);

myobject remainder(myobject& num, myobject& den);
myobject floor(myobject& a);

