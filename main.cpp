#include <iostream>
#include <fstream>
#include "cedict.cpp"
using namespace std;
cedict* parseLine(std::string input);
int main() {
  ifstream myfile;
  myfile.open("small.txt");
  string line;


  std::vector<cedict> parsedList;

  if (myfile.is_open())
  {
      
     while ( getline (myfile,line) )
	   {
        if(line.at(0) != '#') {
  	      cout << line << '\n';
          parseLine(line);
  	    }
     }
     myfile.close();
     }
    else cout << "Unable to open file";
}

cedict* parseLine(std::string input){
  cedict* value = new cedict();
  //std::string
  std::string delimiter = " ";
  value->setTraditional(input.substr(0,input.find(delimiter)));
  input.erase(0, input.find(delimiter) +  .length());
  cout<<"traditional:"<<value->getTraditional()<<endl;
  value->setSimplified(input.substr(0,input.find(delimiter)));
  cout<<"Simplified:"<<value->getSimplified()<<endl;
  input.erase(0, input.find(delimiter) + delimiter.length()+1);

  cout<<"output:"<<input<<endl;
  return value; 
}
