#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


int get_random_number(){
	int random = 1+ (rand() % 3);
	return random;
}

int main(){
	for (int i; i < 100; i++)
	{

		printf("%d ", get_random_number());
	}
	
}
