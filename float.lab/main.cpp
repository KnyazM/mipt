#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cassert>

using namespace std;

unsigned long long fact( unsigned n )
{
unsigned long long res = 1;
for (unsigned i = 1; i <= n; i++)
res = res * i;

return res;
}

float bayley( unsigned long long n )
{
float pi = 0;
for (unsigned long long i = 0; i < n; i++)
pi += (
4 / (8 * (float)i + 1)
-2 / (8 * (float)i + 4)
-1 / (8 * (float)i + 5)
-1 / (8 * (float)i + 6)
) / powf(16, i);

return pi;
}

float bellard( unsigned long long n )
{
float pi_x_64 = 0;
for (unsigned long long i = 0; i < n; i++)
{
pi_x_64 += powf(-1, i) *
(
- 32 / (4 * (float)i + 1)
- 1 / (4 * (float)i + 3)
+ 256 / (10 * (float)i + 1)
- 64 / (10 * (float)i + 3)
- 4 / (10 * (float)i + 5)
- 4 / (10 * (float)i + 7)
+ 1 / (10 * (float)i + 9)
) / pow(2, 10*i);
}
return pi_x_64 / 64;
}

float chud( unsigned long long n )
{
float anti_pi;
for (unsigned long long  i = 0; i < n; i++)
anti_pi += pow(-1, i) * (float)fact(6*i) * (13591409 + 545140134 * i)
/ ( (float)fact(3 * i) * powf((float)fact(i), 3) * powf(640320, 3.0 * i + 3.0/2));
anti_pi *= 12;
return 1 / anti_pi;
}

int main( )
{

ofstream fout;
fout.open ("lab4.csv");

fout << "Bayley\n";

for (unsigned long long i = 0; i < 20; i++){
fout << setprecision(25) << fixed;
fout << bayley(i) << endl;
}

fout << "Bellard\n";

for (unsigned long long i = 0; i < 20; i++){
fout << setprecision(25) << fixed;
fout << bellard(i) << endl;
}

fout << "Chudnovskiy\n";

for (unsigned long long i = 0; i < 30 ; i++){
fout << setprecision(10) << fixed;
fout << chud(i) << endl;
}

  fout.close();

  return 0;
}

