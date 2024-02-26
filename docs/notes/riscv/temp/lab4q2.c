#include <stdio.h>
#include <string.h>

extern char * dest_str;

void concat(char *, char *);
	char *string1 = "Hello";
	char *string2 = "IIT Madras !!!";

int main() {
	printf("%p %p", string1, string2);
	concat(string1, string2);
	printf("concated string: %s, length = %d", dest_str, strnlen(dest_str, 0x80));
}


