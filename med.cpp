#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;

int main ()
{
  map<int,int>med; // map that contains the wordcount as keys // helps to keep the inputs sorted
  char c;
  int k=0, count=0,d=0;
  ifstream infile; // to read input 
  ofstream outfile; //to write the output 
  std::map<int,int>::iterator  it;
  float v1,v2,val; 

    infile.open("test.txt");
    outfile.open("../wc_output/my_median_results.txt");

    if (!infile)
     {
        cout<<"Error reading file!";
        return 0;
     }
    if (!outfile)
     {
        cout<<"Error opening file to write!";
        return 0;
     }
     infile.get(c); // read character by character
      
      while(!infile.eof())
      {
	if(c == ' ') count++; // if found a space increment the wordcount;
        if(c=='\n') // for eand of each line save the words counted in the map
        {
           it = med.begin();
           med[count+1] = k; 
           count=0;d=0;
           while(d < k/2) // need a pointer to traverse to the middle rows of the map
           {
               it++;
               d++;
            }
           if((k%2 == 0) || !k) // if number of lines till now is even
            {
               val = (--it)->first; 
                          
            }
           else                // if number of rows is odd
            {
              v1 = it->first;
              v2 = (--it)->first;
              val = (v1+v2)/2;
	    }
           k++;
           outfile<<val;
           outfile<<endl;
        }
       infile.get(c);
       }
  
  infile.close();
  outfile.close();
  return 0;
}
