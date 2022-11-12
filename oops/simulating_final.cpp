#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// class Final to be made final
class Final;

class MakeFinal {
   private:
    MakeFinal() {
        cout << "constructor of MakeFinal class." << endl;
    }

    friend class Final;
};

class Final : virtual MakeFinal {
   public:
    Final() {
        cout << "constuctor of Final class." << endl;
    }
};

class Derived : public Final {
};

int main() {
}