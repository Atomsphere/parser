#include <fstream>
#include <iostream>
#include <experimental/filesystem>
using namespace std;
namespace fs = experimental::filesystem;




int main(int argc,char *argv[])
{
	string temp;
    ifstream ifile;
    ofstream train("train.txt");
    string temp1;
    string isbn;
    bool isbnfound;

    for(auto& dir: fs::directory_iterator("epub")){
    	//cout << dir << " ";
    	for(auto& epub: fs::directory_iterator(dir)){

   			if(epub.path().filename() == "content.opf"){
   				ifile.open(epub.path());
   				isbnfound = false;
   				while(ifile >> temp){
   					if(temp == "<meta")
   						break;
   					if(temp == "<dc:identifier"){
   						ifile >> temp;
   						//cout << "i made it!";
   						if(temp.substr(12,4) == "ISBN"){
   							isbnfound = true;
   							train << temp.substr(18,13) << endl;
   							break;
    						}
    					}
    				}
    				ifile.close();
    				
    			}
    		}

    }
        
    train.close();
    return 0;

}