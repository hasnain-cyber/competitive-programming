#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class Entity {
    // suppose we have two class variables of different data types.
   private:
    string name;
    int age;

    // and we have different constructors for different types of valeues passed.
   public:
    explicit Entity(string name1) : name(name1), age(-1){};
    explicit Entity(int age1) : name("Unknown"), age(age1){};
};

// suppose we have a function to print the values in entity.
void print_entity(Entity entity) {
    // printing
}

int32_t main() {
    // now if i directly try to assign values to the constructors of the entity class, then it will lead to an error since this
    // is actually an array of chars, either I will have to cast it to entity or converting it to a string first, so, to keep uniformity
    // in the codebase, and to avoid such implicit conversions, we declare the constructors to be explicit while creating the object
    // of class.

    // Entity e1 = "Hasnain";
    // Entity e2 = 21;

    Entity e1 = Entity("Hasnain");
    Entity e2 = Entity(21);
}