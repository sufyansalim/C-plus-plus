#include <iostream>

using std::cout;
using std::endl;

/*For Struct defualt access specifier is public
For class defualt access specifier is private*/

// Structs are user-defined data types!
// They act as blueprints to create objects
struct Wallet {
  // Structs have access specifiers that say who is allowed to access which
  // data/functions
  // Private says this can only be accessed by members/friends of this struct
  // (more on friends later)
  // The default access specifier for structs is public
 private:
  // Structs can have fields (data members)
  int dollars;
  int cents;

  // They can also have methods (functions associated with the struct)
 public:
  // We can have methods for printing
  void print();

  // 'setters' and 'getters' are common when we have private members we want to
  // manipulate
  void set_dollars(int d) { dollars = d; }
  void set_cents(int c) { cents = c; }
  int get_dollars() { return dollars; }
  int get_cents() { return cents; }
};

// Methods are often implemented outside the struct (and in different files)
// We do this to avoid redefinition errors when we are including files
void Wallet::print() {
  cout << "Value of wallet = $" << dollars << "." << cents << endl;
}

int main() {
  // We can create a new instance of a struct (an object) like any other variable
  Wallet sufs_wallet;

  // We can't access the fields 'dollars' and 'cents' directly (they're
  // private)! We can use 'setters' to set them and 'getters' to get them
  sufs_wallet.set_dollars(10);
  sufs_wallet.set_cents(37);

  // We can not directly access the data fields because they are private
  // int tmp_dollars = sufs_wallet.dollars; // FAILS!
  // int tmp_cents = sufs_wallet.cents; //  FAILS!

  // We can print out our custom string just by calling the method
  // This will use the values in our object
  sufs_wallet.print();

  return 0;
}