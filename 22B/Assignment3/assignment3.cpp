/*  Date - 6th February 2024
    Program - opens an input file containg movies and their informations 
    such as gross earnings, director, date released and runtime.
    User can find a movie and save it to favorites if it exists and an error
    will be displayed if the movie is not found.
    After user choose to exit, all the saved movies will be displayed in 
    a formatted fashion.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;
struct Movie
{
    string title;
    double gross;
    string director;
    string date;
    int runtime;
};

int numberOfLines(ifstream&);
Movie* createDatabase(int&);
void populateMovieFromFile(ifstream&, Movie&);
void displayMovie(const Movie&);
bool caseInsensitiveCmp(string, string);
void findMovie(Movie*, int);
void saveToFile(const Movie&);
bool promptToContinue();
void displayFavorites();

int main()
{
    int count;
    string moviename;          
    Movie* ptr;
    ptr = createDatabase(count);
    findMovie(ptr, count);
    displayFavorites();
    delete[] ptr;
    ptr = nullptr;
}

/*  Accepts an input file stream opbject
    Returns number of lines in the input file as integer
*/
int numberOfLines(ifstream& infile)
{
    int n = 0;
    string temp;
    while(getline(infile, temp))
    {
        n++;
    }
    return n;
}

/*  Accepts an input file stream object and Object movie passed by reference
    Returns nothing
    Reads data from input file and store them in each object
 */
void populateMovieFromFile(ifstream& infile, Movie& films)
{
    string temp;
    getline(infile, films.title, ',');       //stores movie title
    infile.ignore();
    getline(infile, temp, ',');              //stores gross earning as string
    films.gross = stod(temp);
    infile.ignore();
    getline(infile, films.director, ',');   //stores director name
    infile.ignore();
    getline(infile, films.date, ',');       //stores release date
    infile.ignore();
    getline(infile, temp);         //stores runtime in mins as string
    films.runtime = stoi(temp);
}

/*  Accepts an integer which is number of movies
    Returns ptr to array of object Movie.
*/
Movie* createDatabase(int& numMovies)
{
    string filename;
    ifstream infile;
    cout << "Enter name of file: ";
    getline(cin, filename);
    infile.open(filename);
    while(!infile)
    {
        cout << "Enter name of file: ";
        getline(cin, filename);
        infile.open(filename);
    }
    numMovies = numberOfLines(infile);
    infile.clear();
    infile.seekg(0);
    Movie* ptr = new Movie[numMovies];
    for(int i = 0; i < numMovies; i++)
    {
        populateMovieFromFile(infile, ptr[i]);
    }
    return ptr;
}

/*  Accepts an argument of object type Movie
    Display the the data stored in the object 
*/
void displayMovie(const Movie& film)
{
    // cout << endl;
    cout << setw(15) << "Title: " << film.title << endl;
    cout << setw(15) << "Gross Total: " << film.gross << endl;
    cout << setw(15) << "Director: " << film.director << endl;
    cout << setw(15) << "Release Date: " << film.date << endl;
    cout << setw(15) << "Runtime: " << film.runtime << endl;
}


/*  accepts a ptr of Movie object and number of movies to search through
    returns nothing
    uses a for loop to iterate through the array of ptr pointing
    to object type Movie
*/
void findMovie(Movie* ptr, int numMovies)
{
    string movie;                     //movie to search for
    Movie userMovie;
    char c;
    bool found;
    bool prompt = false;
    //cout << "Movies in databse: " << numMovies << endl;//debug for movie count
    do
    {
        cout << "Enter movie title to search for: ";
        getline(cin, movie);
        found = false;
        {   
            for(int i = 0; i < numMovies; i++)
            {
                //string will be compared only if lengths matches
                if((ptr[i].title).length() == movie.length())    
                {
                    found = caseInsensitiveCmp(ptr[i].title, movie);
                    if(found)
                    {
                        userMovie = ptr[i];
                        break;
                    }
                }
            }
            if(found)
            {
                cout << "Movie found: " << userMovie.title << endl;
                displayMovie(userMovie);
                cout << "Do you want to save the above movie? (Y or N): ";
                cin  >> c;
                cin.ignore();
                if(c == 'Y' || c == 'y')
                {
                    saveToFile(userMovie);
                }
                else if(c == 'N' || c == 'n')
                {

                }
            }
            else
            {
                cout << "Movie not found in the database. Try again." << endl;
            }
            prompt = promptToContinue();        //Prompt for continuation
        }
    } while(prompt);
}

/*  Accepts two strings
    Converts both strings to lowercase and compare
    Returns true if both strings are same
*/
bool caseInsensitiveCmp(string a, string b)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(tolower(a[i]) != tolower(b[i]))
        {
            return false;
        }
    }
    return true;
}

/*  Accepts an object of type Movie
    Returns nothing
    Save the object's conents into an outputfile if user wishes to 
*/
void saveToFile(const Movie& saved)
{
    ofstream outfile;
    static bool isOpen = false;
    if(isOpen == false)
    {
        outfile.open("favorites.txt");
        isOpen = true;
    }
    else
    {
        outfile.open("favorites.txt", ios::app);
    }

    outfile << saved.title << ", " << saved.gross << ", " << saved.director 
    << ", " << saved.date << ", " << saved.runtime << endl;

    outfile.close();
}

/*  Returns a bool
    Function prompts if user wants to quit searching movie or not
 */
bool promptToContinue()
{
    char choice;
    bool user_choice;
    cout << "Would you like to exit? (Y/N): ";
    cin  >> choice;
    cin.ignore();                         //clear input buffer for do while loop
    if(choice == 'y' || choice == 'Y')
    {
        user_choice = false;
    }
    else if(choice == 'n' || choice == 'N')
    {
        user_choice = true;
    }

    return user_choice;
}

/*  Opens the favorites.txt file and display all the information saved in
    a formatted layout
*/
void displayFavorites()
{
    ifstream filein;
    int n;
    filein.open("favorites.txt");
    if(!filein)
    {
        cout << "Error opening saved movies list.";
    }
    n = numberOfLines(filein);                //number of lines in favorites.txt
    filein.clear();
    filein.seekg(0);
    Movie favorite[n];
    cout << endl;
    cout << "Your saved movies are: " << endl;
    for(int i = 0; i < n ; i++)
    {
        populateMovieFromFile(filein, favorite[i]);
        displayMovie(favorite[i]);
        cout << endl;
    }
}




//Sample Run//

/*  
Enter name of file: movies.txt
Enter movie title to search for: SkyFALL
Movie found: Skyfall
        Title: Skyfall
  Gross Total: 1.109
     Director: Sam Mendes
 Release Date: 11/9/12
      Runtime: 143
Do you want to save the above movie? (Y or N): Y
Would you like to exit? (Y/N): N
Enter movie title to search for: IroN MAN 3
Movie found: Iron Man 3
        Title: Iron Man 3
  Gross Total: 1.215
     Director: Shane Black
 Release Date: 5/3/13
      Runtime: 130
Do you want to save the above movie? (Y or N): Y
Would you like to exit? (Y/N): N
Enter movie title to search for: NARUTO
Movie not found in the database. Try again.
Would you like to exit? (Y/N): Y

Your saved movies are:
        Title: Skyfall
  Gross Total: 1.109
     Director: Sam Mendes
 Release Date: 11/9/12
      Runtime: 143

        Title: Iron Man 3
  Gross Total: 1.215
     Director: Shane Black
 Release Date: 5/3/13
      Runtime: 130
 */