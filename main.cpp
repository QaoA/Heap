#include <iostream>
using namespace std;

struct Test
{
    int i;
    char j;
}SLTest;

int main() {
   cout << GetOffset<Test,i>();
    return 0;
}