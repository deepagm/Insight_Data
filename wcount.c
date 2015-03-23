#include "stdio.h"
#include "string.h"
#define N 2000 // Change this in case of big txt file
#define SLACK 64
int main()
{
 FILE *fp1, *fp2;
 char oneword[50];
 int sum=0;
 char c;
 int i,l,p,q;
 int array[N][SLACK] = {0}; // array to store the hash values
 char arrayc[N][SLACK][50]; // array containing hashed words

   fp1 = fopen("test.txt","r");
   fp2 = fopen("../wc_output/my_word_count.txt","w");

   c = fscanf(fp1,"%s",oneword); 
   while (c != EOF){
      l = strlen(oneword);
      if(((oneword[l-1] & 240) == 32)) {oneword[l-1] = '\0';l=l-1;} // To eliminate punctuation marks right after a word
	  sum=0;
          for(i=0;i<l;i++)
          {
            sum+=oneword[i]; // compute sum of individual characters within the word
	  }
          p = sum%N;
          q = p%SLACK;
          array[p][q] +=1;
          strcpy(arrayc[p][q],oneword);	
   c = fscanf(fp1,"%s",oneword);
   }              
   fclose(fp1);
   
  /*write results to a file*/
   for(p=0;p<N;p++)
   {
	for(q=0;q<SLACK;q++)
	{
                 if(array[p][q])
 		 {
                    strcpy(oneword,arrayc[p][q]);
		    fprintf(fp2,"%s  %d \n",oneword,array[p][q]);	
		 }
	}
   }
   fclose(fp2);
 return 1;
}

