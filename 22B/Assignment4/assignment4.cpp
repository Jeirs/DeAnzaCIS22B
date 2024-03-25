/*  Date - 12 Feb 2024
    Program - Vending Machine Simulator selling chips, soda, candy.
    Prompts user to input number of quarters and number of items to buy.
    If user entered enough money and item the user wants to buy is in-stock,
    item will be dispensed. At the end, it will return the amount of change
    if user entered more money than necessary and the time the items
    were purchased.
 */
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
class Snack
{
    private:
        string name;
        double price;
        int stock;
        int sold;
        string* transaction;
        string getCurrentTime()
        {
            time_t t = time(0);
            struct tm ts;
            char buff[10];
            ts = *localtime(&t);
            strftime(buff, sizeof(buff), "%X", &ts);
            return buff;
        }
    public:
        Snack();
        Snack(string snackname, double snackprice, int inventory);
        void setName(string);
        string getName() const;
        void setPrice(double);
        double getPrice() const;
        void setStock(int);
        int getStock() const;
        void setSold(int);
        int getSold() const;
        ~Snack();
        bool buyItem(double& moneyEntered);
};


void displayVendingMachine(const Snack machine[], int items);
int getQuarters();
void userBuyItem(Snack [], int);
bool promptToContinue();

int main()
{
    int const size = 3;
    Snack snacks[size] = 
    { Snack(), Snack("Candy", 1.25, 5), Snack("Soda", 1, 2)};
    snacks[0].setName("Chips");
    snacks[0].setPrice(1.75);
    snacks[0].setStock(3);
    userBuyItem(snacks, size);

}

Snack::Snack()  //Default Constructor
{
    name = "";
    price = 0;
    stock = 0;
    sold = 0;
}

//Overloaded Constructor
Snack::Snack(string snackname, double snackprice, int inventory)
{
    name = snackname;
    price = snackprice;
    stock = inventory;
    sold = 0;
    transaction = new string[stock];
}

Snack::~Snack()
{
    cout << "Closing info for " << name << endl;
    cout << "        " << stock << " in stock" << endl;
    cout << "        " << sold << " sold for a profit of $" 
    << fixed << setprecision(2) << price * sold << endl;
    if(sold > 0 && transaction != nullptr)
    {
        cout << "Transaction occured at: " << endl;
        for(int i = 0; i < sold; i++)
        {
            cout << "        " << transaction[i] << endl;
        }
    }
    delete[] transaction;
    transaction = nullptr;
}

void Snack::setName(string snackname)
{
    name = snackname;
}
string Snack::getName()const
{
    return name;
}

void Snack::setPrice(double snackprice)
{
    price = snackprice;
}
double Snack::getPrice()const
{
    return price;
}

void Snack::setStock(int inventory)
{
    stock = inventory;
    transaction = new string[stock];
}
int Snack::getStock()const
{
    return stock;
}

void Snack::setSold(int deduct)
{
    sold = deduct;
}
int Snack::getSold()const
{
    return sold;
}

/*  Accepts a double of pass-by reference type
    Returns a bool
    Checks whether money entered is enough to buy an item or not
    and display output accordingly
*/
bool Snack::buyItem(double& moneyEntered)
{
    bool result;
    //if item has been bought successfully, return true
    if(moneyEntered >= price && stock!= 0)
    {
        moneyEntered -= price;
        stock--;
        sold++;
        cout << "Item has been dispensed below." << endl;
        transaction[sold-1] = getCurrentTime();
        result = true;
    }
    if(moneyEntered < price)
    {
        cout << "Not enough money." << endl;
        result = false;
    }
    if(stock == 0)
    {
        cout << "Item is sold out" << endl;
        result = false;
    }
    return result;
}

/*  Accepts a constant object array and number of items in array
    Displays items in the array in a formatted fashion
*/
void displayVendingMachine(const Snack machine[], int items)
{
    cout << "Item #" << setw(18) << "Item Name" << setw(11) << "Price"
    << right << setw(20) << "# in-stock" << endl;
    cout << "-------------------------------------------------------" << endl;
    for(int i = 0; i < items; i++)
    {
        cout << left << setw(15) << i+1 << setw(15) << machine[i].getName() 
        << setw(15);
        cout << fixed << setprecision(2) << machine[i].getPrice();
        cout << setw(15) << machine[i].getStock() << endl;
    }
}

/*  Returns an int
    Asks user to input a number greater than 0
*/
int getQuarters()
{
    int inputval = 0;
    do
    {
        cout << "Enter number of quarters: ";
        cin >> inputval;
        if(inputval <= 0)
        {
            cout << "Error. Please enter a valid number." << endl;
            cout << "Enter number of quarters: ";
            cin >> inputval;
        }
    }
    while (inputval <= 0);
    return inputval;
}

/*  Accepts an array of object Snack class, number of items in the array obj
    In a do while loop, prompts user to enter the amount of quarters and
    to make a selection, calls buyItem function to keep track whether 
    an item has been bought successfully or not.
*/
void userBuyItem(Snack machine [], int items)
{
    bool prompt = false;
    do
    {
        displayVendingMachine(machine, items);
        double numquarters = getQuarters();
        double available = numquarters*0.25;
        int userchoice;
        cout << "Amount entered: $" << available << endl;
        do
        {
            cout << "Enter a number between 1 and 3 to make a selection: ";
            cin  >> userchoice;
            if(userchoice <= 0 || userchoice > 3)
            {
                cout << "Please make a valid selection." << endl;
            }
        }while(userchoice <= 0 || userchoice > 3);
        bool buyresult = machine[userchoice-1].buyItem(available);
/*     cout << available << " left to buy items." << endl;
        cout << "Stock: " << machine[userchoice-1].getStock() << endl;
        cout << "Sold: " << machine[userchoice-1].getSold()  << endl; */
        if(available != 0)
        {
            cout << "$" << available << " dispensed below." << endl;
        }
        prompt = promptToContinue();
    }while(prompt);
}


/*  Returns a bool type
    Depending on whether user wishes to continque or quit, it will a return
    a bool value accordingly.
*/
bool promptToContinue()
{
    char choice;
    bool choiceresult;
    cout << "Continue? ( Y / N ): ";
    cin  >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        choiceresult = true;
    }
    else
    {
        choiceresult = false;
    }
    return choiceresult;
}




/*  Sample Run
Item #         Item Name      Price          # in-stock
-------------------------------------------------------
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           2
Enter number of quarters: -1
Error. Please enter a valid number.
Enter number of quarters: 8
Amount entered: $2.00
Enter a number between 1 and 3 to make a selection: 3
Item has been dispensed below.
$1.00 dispensed below.
Continue? ( Y / N ): y
Item #Item Name         Price                # in-stock
-------------------------------------------------------
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           1
Enter number of quarters: 4
Amount entered: $1.00
Enter a number between 1 and 3 to make a selection: 3
Item has been dispensed below.
Continue? ( Y / N ): y
Item #Item Name         Price                # in-stock
-------------------------------------------------------
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           0
Enter number of quarters: 4
Amount entered: $1.00
Enter a number between 1 and 3 to make a selection: 3
Item is sold out
$1.00 dispensed below.
Continue? ( Y / N ): y
Item #Item Name         Price                # in-stock
-------------------------------------------------------
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           0
Enter number of quarters: 10
Amount entered: $2.50
Enter a number between 1 and 3 to make a selection: 1
Item has been dispensed below.
$0.75 dispensed below.
Continue? ( Y / N ): y
Item #Item Name         Price                # in-stock
-------------------------------------------------------
1              Chips          1.75           2
2              Candy          1.25           5
3              Soda           1.00           0
Enter number of quarters: 5
Amount entered: $1.25
Enter a number between 1 and 3 to make a selection: 2
Item has been dispensed below.
Continue? ( Y / N ): y
Item #Item Name         Price                # in-stock
-------------------------------------------------------
1              Chips          1.75           2
2              Candy          1.25           4
3              Soda           1.00           0
Enter number of quarters: 9
Amount entered: $2.25
Enter a number between 1 and 3 to make a selection: 1
Item has been dispensed below.
$0.50 dispensed below.
Continue? ( Y / N ): n
Closing info for Soda
        0 in stock
        2 sold for a profit of $2.00
Transaction occured at:
        08:54:14
        08:54:26
Closing info for Candy
        4 in stock
        1 sold for a profit of $1.25
Transaction occured at:
        08:54:47
Closing info for Chips
        1 in stock
        2 sold for a profit of $3.50
Transaction occured at:
        08:54:39
        08:54:52 */