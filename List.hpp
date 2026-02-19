// Tu Nombre
// Implementación del ADT List usando arreglo dinámico.

#include <stdexcept>
#include <string>

using namespace std;

class List{
private:
  int *a;
  int size;
  int cap;

  void doubleCap() {
    cap = cap * 2;
    int *tmp = new int[cap];
    for (int i = 0; i < size; i++) tmp[i] = a[i];
    delete [] a;
    a = tmp;
  }

  string toStr(int value) const {
        ostringstream oss;
        oss << value;
        return oss.str();
  }

public:
  // constructor 
  List(): a(new int[4]), size(0), cap(4) {}


  // insert an element to a specific position in the list
  void insert(int val, int pos){
      if(pos < 0 || pos > size)
          throw std::invalid_argument("Invalid position");
  
      if(size == cap) doubleCap();
  
      for(int i = size - 1; i >= pos; i--) a[i+1] = a[i];
      
      a[pos] = val;
      size++;
  }

  // destructor!
  ~List() {
      delete [] a;
  }

  // Copy assignment operator.
  List& operator=(const List &rs) {
    if (this != &rs) {
      // free old memory
      delete[] a;  
      // copy the data members from right side operand
      cap = rs.cap;
      size = rs.size;
      // new array
      a = new int[cap];
      // copy the contents
      for (int i = 0; i < size; i++) {
          a[i] = rs.a[i];
      }
    }
    return *this;
  }

  // Move assignment operator
  List& operator=( List &&rs) {

    if (this->a != nullptr) delete [] a;
    
    a = rs.a;
    size = rs.size;
    cap = rs.cap;
    
    rs.a = nullptr;
    rs.size = 0;
    rs.cap = 0;

    return *this;
  }


  // An overload of the + operator. It concatenates the left side operand
  // with the right side operand and returns the created list.

  List operator+(const List &rSide) const {
    List res; int ctr = 0;
    for (int i = 0; i < size; i++)
      res.insert(a[i], ctr++);
    for (int i = 0; i < rSide.size; i++)
      res.insert(rSide.a[i], ctr++);

    return res;
  }

  // Remove element from a position.
  void remove(int pos) {
    if (pos < 0 || pos >= size) throw std::invalid_argument("Invalid position");

    for (int i = pos; i < size -1; i++) a[i] = a[i+1];
    size--;
  }

  // Overload of the [] operator that gets the value from a position. 
  // Warning: No bounds checking :-(
  int& operator[](int pos) const {
    return a[pos];
  }

  int getSize() const { return size;}

  // Copy constructor
  List (const List &rs) {
    size = rs.size;
    cap = rs.cap;


    // reservamos un nuevo arreglo 
    // y copiamos contenido de rs
    a = new int[cap];
    for(int i = 0; i < size; i++) { 
      a[i] = rs.a[i];
    }
  }

  // Move constructor
  List ( List &&rs) {
    a = rs.a;
    size = rs.size;
    cap = rs.cap;

    rs.a = nullptr;
    rs.size = rs.cap = 0;
  }

  // Appends value to the end of the list
  void append(int val){
    if (size == cap) doubleCap(); 
    a[size++] = val; 
  }

  // Overload of the == operator. Two lists are equal if they
  // represent the same list.
  bool operator==(const List &rSideOp) const {
      if (size != rSideOp.size) return false;
      for (int i = 0; i < size; i++) {
          if (a[i] != rSideOp.a[i]) return false;
      }
      return true;
  }

  // Returns a string containing the elements of the list
  string toString() const {
      string st = "";
      if (size == 0) return st;
      for (int i = 0; i < size - 1; i++) {
          st = st + toStr(a[i]) + " ";
      }
      st = st + toStr(a[size-1]);
      return st;

  }

  void inverse() {
      // Tu la implementas!
  }



};
