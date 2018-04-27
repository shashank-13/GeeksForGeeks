#include<bits/stdc++.h>
using namespace std;
int main()
{
  char *a = "hello";
  char *b = "world";
  char *c[3] = {a, b, 0};
  printf("%c%c%c%c", c[0][1], c[1][0], *c[0], *b);
}
