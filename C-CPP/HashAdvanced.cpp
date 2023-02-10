//Main references are taken from: http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-2.html#pgfId-982677
//Credit to:
//1) Rhio Sutoyo, for pproviding great explanation on how hashing works (https://www.youtube.com/watch?v=Tp0nma5LIZY)
//2) Felix Jingga, for providing an example of good string hash function


//Check on "Birthday Paradox" (https://en.wikipedia.org/wiki/Birthday_problem)
//- Suppose there are 365 slots in the hash table: M=365
//- The probability that there will be a collision when inserting N keys are:
//	 > For N = 10, probN, M(collision) = 12%
//	 > For N = 20, probN, M(collision) = 41%
//	 > For N = 30, probN, M(collision) = 71%
//	 > For N = 40, probN, M(collision) = 89%
//	 > For N = 50, probN, M(collision) = 97%
//	 > For N = 60, probN, M(collision) = 99+%
//- Conclusion: It is important in advance to decide
//	 1) size of the hash table
//	 2) hash function
//	 3) collision resolution strategy in advance


//1) Hash Tables Size
//	 - Depends on choice of hash function, and collision resolution strategy
//	 - Should be allocates to acomodate more than the maximum value of the data/keys (1.3x is OK)
//	 - Should be a prime number
//	 - Reference: https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function

//2) Hash Function
//   - Shoulld be fast to compute
//   - Distribute keys as uniformly as possible in the hash table, to avoid collisions as much as possible
//   - Consistent with the equality testing function
//   - Base number should be strictly greater than the number of different values of an individual element can be
//   - For example, because there are 26 alphabets (not counting upper and lower), the base should be > 26
//   - hashCode() method of String class in Java use 31 as base number ()
//   - Reference: Data Structures and Algorithms in Java by Goodrich and Tamassia Section 10.2, page 413

//FUN FACT:
//If you take over 50,000 English words (formed as the union of the word lists provided in two variants of Unix),
//using the constants 31, 33, 37, 39, and 41 will produce less than 7 collisions in each case.

//3) Collision Resolution
//   - Linear Probing
//   - Chaining  

//Simple String Hash Function
//1) Adds up the integer values of the chars
//2) Mod to the size of the hash tables
//
//(+) Simple to compute
//(-) Doesn’t work very well in practice
//
//- Suppose the keys are strings of 8 ASCII capital letters and spaces	
//- There are 27^8 possible keys;
//- However, ASCII codes for these characters are in the range 65-95, and so the sums of 8 char values will be in the range 520 - 760
//- In a large hash table size (M>1000), keys will only cramped on specific section of the hash table
//- In a small hash table size (M<100), it might be OK


#include <stdio.h>
#include <string.h>

//Choosing 97 because of prime number and greater than number of data to be stored
int hashTables[97];

//const char* parameter to ensure that no modification can be performed inside the function
int hash(const char *str) {
	
	//Calculate length of the string for number of iteration
	int len = strlen(str);
	
	//Check on above explanation
	int base = 31;
	
	//Size of our hashtables
	int MODPRIME = 97;
	
	//Variable to sum all characters
	int ret = 0;


	//Loop through all characters in the string
	for(int i=0; i<len; i++) {
		ret = (ret * base) + (str[i] - 'a' + 1);
		ret = ret % MODPRIME;
	}
	
	//Modulo to the size of the hash tables
	return (ret * base) % MODPRIME;
}


int main(){
	
	char data[][100] = {
		"define",
		"float",
		"exp",
		"char",
		"atan",
		"ceil",
		"acos",
		"floor",
		"mean",
		"average",
		"dust",
		"cover",
		"operator",
		"algorithm"
	};
	
	int dataCount = sizeof(data) / sizeof(data[0]);
	
	for(int i=0 ; i<dataCount ; i++){
		printf("String \"%s\" saved in index %d\n", data[i], hash(data[i]));
	}
	
	return 0;
}