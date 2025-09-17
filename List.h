#include <stdexcept>
#include <string>

using namespace std;

class List{
private:
  int *a;
  int size;
  int cap;

  void expand() {
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
  List(): a(new int[4]), size(0), cap(4) {}
  void insert(int val, int pos){
  
      if(pos < 0 || pos > size)
          throw std::invalid_argument("Invalid position");
  
      if(size == cap) expand();
  
      for(int i = size - 1; i >= pos; i--) a[i+1] = a[i];
      
      a[pos] = val;
      size++;
  }
  ~List() {
    if (a != nullptr)
      delete [] a;
  }

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



  List operator+(const List &rSide) const {
    List res; int ctr = 0;
    for (int i = 0; i < size; i++)
      res.insert(a[i], ctr++);
    for (int i = 0; i < rSide.size; i++)
      res.insert(rSide.a[i], ctr++);

    return res;
  }

  void remove(int pos) {
    if (pos < 0 || pos >= size) throw std::invalid_argument("Invalid position");

    for (int i = pos; i < size -1; i++) a[i] = a[i+1];
    size--;
  }

  int& operator[](int pos) const {
    return a[pos];
  }

  int getSize() const { return size;}

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

  List ( List &&rs) {
    a = rs.a;
    size = rs.size;
    cap = rs.cap;

    rs.a = nullptr;
    rs.size = rs.cap = 0;
  }

  void append(int val){
    if (size == cap) expand(); 
    a[size++] = val; 
  }

  bool operator==(const List &rSideOp) const {
      if (size != rSideOp.size) return false;
      for (int i = 0; i < size; i++) {
          if (a[i] != rSideOp.a[i]) return false;
      }
      return true;
  }

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
      // implementa!!
  }

};
