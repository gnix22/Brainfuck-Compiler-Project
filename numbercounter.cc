#include <iostream>
#include <vector>
int main() {
std::vector<unsigned char> tape(30000, 0);
auto ptr = tape.begin();
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while (*ptr) {
++ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
--ptr;
--*ptr;
}
++ptr;
++ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while (*ptr) {
++ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
--ptr;
--*ptr;
}
++ptr;
++ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while (*ptr) {
--ptr;
--ptr;
--ptr;
std::cout << *ptr;
++*ptr;
++ptr;
++ptr;
std::cout << *ptr;
++ptr;
--*ptr;
}
return 0;
}
