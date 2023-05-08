#include <stdio.h>
#include <assert.h>
//1
//a
/*
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12
*/
//b
/*
13
*/
//2
void swapM(int *x, int *y){
	int tmp;
	tmp=*x;
	*x=*y;
	*y=tmp;

}

int main(){
	int x = 3, y = 5;
	assert("5 3" == swapM (&x, &y));

	
	return 0;
}