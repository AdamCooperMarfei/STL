#include<iostream>
using namespace std;
class INT
{
    friend ostream& operator<<(ostream &os, const INT&i);
    public:
      INT(int i):m_i(i){};
      INT&operator++()
      {
        ++(this->m_i);
        return *this;
      }
    private:
      int m_i;
};