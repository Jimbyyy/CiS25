#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// Give them following string, writ a function to parse this into a movie structure.
//“24 s2,2014”

struct Movie {
    string title;
    int releaseDate;
};

Movie stringToMovie(string data){
    
    stringstream stream;
    string title;
    int releaseDate;

    stream >> data;
    title = stream.str();

    stream >> data;
    releaseDate = stoi(data);

    Movie movie{title, releaseDate};
    return movie;

}

int main(){

    string data = "24 s2,2014";
    Movie movie = stringToMovie(data);

    cout << movie.title << movie.releaseDate << endl;
    
    return 0;
}