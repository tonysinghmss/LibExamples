#include <iostream> //cout, cin, cerr
#include <string>
#include <vector>
#include <sstream>//for stringstream
#include <fstream>
int main(int argc, char* argv[]){
    //Check if the argument count is less than 2.
    //If not show an error.
    if(argc < 2){
        cerr << "Usage: " << argv[0] << " Name_Of_File or a sentence " << endl;
        return 1;
    }
    
    vector<string> urlLists;
    string line;
    stringstream ss;
    //TODO: See that argument passed is a file
    ifstream infile(argv[1]);
    while(getline(infile,line)){
      ss << line << endl;
    }

    string fullString = ss.str();
    //Apply the find_urls method
    urlLists = find_urls(fullString);
    vector<string>::const_iterator iter = urlLists.begin();
    // invariant: We have created rotation vectors for each line in list.
    while(iter != urlLists.end()){
	cout << *iter << endl;
        ++iter;
    }
    
}
