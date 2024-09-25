#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void mainFunction(){
    // Input and output file paths
    string input_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-I/Inputs.txt";
    string output_file = "C:/Users/LENOVO/Documents/MyReactJourney/DSA/Meta Hacker Cup Question/CheeseBurgers-I/Outputs.txt";

    
    ifstream inFile(input_file);
    ofstream outFile(output_file);
    
    int T = 0;
    int A = 0, B = 0, C = 0;
    int buns = 0, patties = 0;
    vector<string> results;
    
    if (!inFile.is_open()){
        cout << "File not opens!!";
    }
    inFile >> T;
    
    for (int i=1 ; i < T+1 ; i++){
        inFile >> A >> B >> C;
        
        buns = ( A + B ) * 2;
        patties = A + ( B * 2 );
        
        if ( buns >= C + 1 and patties >= C ){
            results.push_back("Case #"+to_string(i) + ": " + "YES");
        }
        else{
            results.push_back("Case #"+to_string(i) + ": " + "NO");
        }
    }
    
    if outFile.is_open(){
        for (const auto &curr: results){
            outFile << curr << endl;
        }
    }
    else{
        cout << "OutPut file not found" << endl;
    }
}

int main(){
    mainFunction():
    return 0;
}
