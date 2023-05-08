#include <stdio.h>
#include <string.h>
#include <assert.h>

int eVogal(char c){
	int r=0;
	if(c == 'a' || c =='A' 
			|| c =='e' || c =='E' 
			|| c =='i' || c =='I' 
			|| c =='o' || c =='O' 
			|| c =='u' || c =='U') r=1;
		return r;
}
//1
int contaVogais( char *s){
	int i;
	int r=0;
	for(i=0;s[i]!='\0';i++){
		if(eVogal(s[i])) r++;
	}
	return r;
}

//2
int retiraVogaisRep_arrayauxiliar(char *s){
	char r[strlen(s)];

	int accum=0;
	for(int i=0;s[i]!='\0';i++){
		int j=0;
		while(!eVogal(s[i]) && s[i]!=s[i+1]){
			r[j] = s[i];
			j++;
			i++;
		}
		r[j] = s[i];
		j++;
		while(s[i]==s[i+1] || s[i-1]==s[i]){
			i++;
			accum++;
		}
	}
	int i;
	for(i=0;r[i]!='\0';i++){
		s[i]=r[i];
	}
	s[i] = '\0';

	return accum;
}

int retiraVogaisRep(char *s){
	char *a = s;
	char *b = a + 1;
	int r=0;
	while(*b!='\0'){
		if(!(eVogal(*a) && *a==*b)){
			a++;
			b++;
		}
		else{
			*a = *b;
			a++;
			b++;
			r++;
		}
	}
	return r;

}

//3
int duplicaVogais(char *s){
	char r[strlen(s)*2];
	int i=0, j=0, c=0;
	while(s[i]!='\0'){
		if(eVogal(s[i])){
			r[j] = s[i];
			r[j+1] = s[i];
			j+=2;
			i++;
			c++;
		}
		else{
			r[j]=s[i];
			j++;
			i++;
		}
	}
	return c;
}



int main(){
	char *a = "aaabcdeee";
	assert(6==contaVogais(a));
	duplicaVogais(a);
	printf("%s", a);

	return 0;
}