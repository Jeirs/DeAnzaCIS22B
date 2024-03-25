/*  Date - 14 March 2024
    Program - A templated Linkedlist which can store any type of data including
    objects. Example program stores "Composer" object in the linkedlist and 
    gives user access to remove, search or display the stored object in the 
 */

#include "Node.h"
#include "LinkedList.h"
#include "composers.h"
#include <fstream>
int main()

{
/*     LinkedList<int> test;
    test.append(2);
    test.append(3);
    test.append(5);
    test.printList();
    test.prepend(1);
    test.printList();
    test.removeFront();
    test.printList();   //works fine removefront()
    test.insert(200);
    test.printList();
    test.insert(4);
    test.printList();
    test.remove(200);
    test.printList();   //works fine remove tail
    cout << boolalpha;
    cout << test.find(4) << endl;
    cout << test.find(300) << endl;  //works fine , find function

    cout << test.getfirst() << endl;
    cout << test.getlast()  << endl; //works fine with digits

    LinkedList<string> names;
    names.append("Lee");
    names.append("Mayloe");
    names.printList();

    names.insert("Amber");
    names.insert("Brunhilde");

    names.printList();
    cout << names.getfirst() << endl;
    cout << names.getlast() << endl; */

    LinkedList<Composer> composer_list;
    ifstream filein;
    filein.open("composers.txt");
    if(!filein)
    {
        cout << "Error opening file" << endl;
    }
    string name, death;
    while(getline(filein, name, ','))
    {
        getline(filein,death);
        Composer artist(name, death);
        composer_list.insert(artist);
    }
    //composer_list.printList();
    //read file works ok
    bool prompt = false;
    char input;
    string searchname;
    while(!prompt)
    {
        
        cout << "Enter 's' to search, 'r' to remove, 'd' to display, or"
             << " 'e' to exit: ";
        cin >> input;
        cin.ignore();
        switch(tolower(input))
        {
            case 'd':
                composer_list.printList();
                break;
            case 's':
                cout << "Enter a composer's name to search for: ";
                getline(cin, searchname);
                if(composer_list.find(searchname))
                {
                    cout << searchname << " was found in the list." << endl;
                    cout << endl;
                }
                else
                {
                    cout << searchname << " was not found in the list." << endl;
                    cout << endl;
                }
                break;
            case 'e':
                prompt = true;
                break;
            case 'r':
                cout << "Enter a composer's name to remove: ";
                getline(cin, searchname);
                if(composer_list.find(searchname))
                {   
                    composer_list.remove(searchname);
                    cout << searchname << " was removed successfully." << endl;
                }
                else
                {
                    cout << searchname << " was not in the list and not removed"
                    << endl;
                }
                break;
            default:
                cout << "Enter 's' to search, 'r' to remove, 'd' to display, or"
                << " 'e' to exit: ";
                break;
        }
    }
    filein.close();
}

//SAMPLE RUN//

/* Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Claude Debussy
Claude Debussy was found in the list.

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s
Enter a composer's name to search for: Hans Zimmer
Hans Zimmer was not found in the list.

Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r
Enter a composer's name to remove: Henry Purcell
Henry Purcell was removed successfully.
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d
Claudio Monteverdi - 1643
Antonio Vivaldi - 1741
Johann Sebastian Bach - 1750
George Frideric Handel - 1759
Wolfgang Amadeus Mozart - 1791
Joseph Haydn - 1809
Ludwig van Beethoven - 1827
Franz Schubert - 1828
Felix Mendelssohn - 1847
Frederic Chopin - 1849
Robert Schumann - 1856
Hector Berlioz - 1869
Richard Wagner - 1883
Franz Liszt - 1886
Pyotr Ilyich Tchaikovsky - 1893
Johannes Brahms - 1897
Giuseppe Verdi - 1901
Antonin Dvorak - 1904
Edvard Grieg - 1907
Gustav Mahler - 1911
Claude Debussy - 1918
Camille Saint-Saens - 1921
Giacomo Puccini - 1924
George Gershwin - 1937
Maurice Ravel - 1937
Sergei Rachmaninoff - 1943
Bela Bartok - 1945
Arnold Schoenberg - 1951
Sergei Prokofiev - 1953
Igor Stravinsky - 1971
Dmitri Shostakovich - 1975
Leonard Bernstein - 1990
Aaron Copland - 1990
Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e */
