#include<stdio.h> 
int main(){
int solution(int number) {
	int sum = 0; 
	for (int i = 0; i < number; i++) {
	    if(i%3 == 0 || i%5 == 0)
	       sum += i;
	}

	// code here
    return sum;
}

printf("result %d",solution(10));
}
