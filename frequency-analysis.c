#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv){

	if(argc>2 || argc==2 && strcmp(argv[1],"-o")){
		puts("Usage:");
		printf("  %s\n",argv[0]);
		printf("  %s -o   Display letters ordered according to frequency\n",argv[0]);
		puts("");
		return 0;
	}

	int frequence[26]={0},size=0;
	double percentage[26]={0},d;
	char c,typechar;

	printf("[*]Text to analyse : ");

	while((c=getchar())!='\n')
		if(c>=65&&c<=90||c>=97&&c<=122){
			typechar=(c<=90)?65:97;
			c-=typechar;
			frequence[c]++;
			size++;
		}

	system("clear");

	puts("");
	puts("  LETTERS                25\%         50\%                     100\%");
	puts("");



	for(int i=0;i<26;i++) percentage[i]=(double)(frequence[i]*100)/size;

	if(argc==2){
		
		int ordered;
		char alpha[26];
		for(int i=0;i<26;i++) alpha[i]=65+i;

		for(int j=25;j!=0;j--){

			ordered=1;

			for(int i=0;i<j;i++){
				if(percentage[i]<percentage[i+1]){
					ordered=0;

					d=percentage[i];
					percentage[i]=percentage[i+1];
					percentage[i+1]=d;

					c=alpha[i];
					alpha[i]=alpha[i+1];
					alpha[i+1]=c;
				}
			}
			if (ordered==1) break;
		}

		for(int i=0;i<26;i++){
		
			printf("(%c %7.2f\%) |",alpha[i],percentage[i]);
			for(int j=2;j<percentage[i];j+=2) printf("▆");
			puts("");
		
		}

	}else{

		for(int i=0;i<26;i++){
		
			printf("(%c %7.2f\%) |",65+i,percentage[i]);
			for(int j=2;j<percentage[i];j+=2) printf("▆");
			puts("");
		}
	} 
	

	puts("");

	return 0;
}