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

//9
int mystrcmp(char s1[], char s2[]){
	int r=0;
	for(int i=0; (s1[i] != '\0' || s2[i] != '\0') && r==0; i++){
		if(s1[i] < s2[i]) r = -1;
		if(s1[i] > s2[i]) r = 1;
	}
	return r;
}

//10
char *mystrstr (char s1[], char s2[]){
	char *r = NULL;//só não é NULL se encontrarmos então 
	//começamos em NULL
	for(int i=0; s1[i] != '\0' && r==NULL;i++){
		if(s1[i]== s2[0]){
			for(int j=0; s2[j] != '\0'; j++){
				if(s2[j]==s1[i+j]) r = &(s1[i]);
				else r = NULL;
			}
		}
	}
	return r;
}

//11

void mystrrev(char s[]){
	int i;
	for(i=0;s[i]!='\0';i++)
		;
	i--;
	int j;
	for(j=0;j<i;j++){
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i--;
	}

}
//12
void mystrnoV(char s[]){
	int i, j;
	for(i=0;s[i]!='\0';i++){
		if(s[i] == 'a' || s[i] =='A' 
			|| s[i] =='e' || s[i] =='E' 
			|| s[i] =='i' || s[i] =='I' 
			|| s[i] =='o' || s[i] =='O' 
			|| s[i] =='u' || s[i] =='U'){
			for(j=i;s[j]!='\0';j++){
				s[j]=s[j+1];
			}
			s[j]='\0';
		}
		
	}
}
//13
void truncW(char t[], int n){
	int j=0;
	for(int i=0;t[i]!='\0';i++){
		j++;
		if(t[i]==' '){
			int h=i;
			for(int r=i-j+n;r<h;r++){
				if(t[h]!='\0'){
					t[r]=t[h];
					h++;
				}
			}
			j=0;
			i++;
		}
	}
	

}

int main(){
	char a[]="0a 1b23e4iii 5u6789";
	truncW(a, 3);
	printf("%s", a);
	
	return 0;
}