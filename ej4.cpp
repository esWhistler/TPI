#include <iostream>
#include <vector>
using std::vector;

////////////////////////////////////////////////////////////////////////

// 			El algoritmo del ej4 es el de la funcion sort_

////////////////////////////////////////////////////////////////////////



void swap(int *m, int *n)
{ // podriamos tambien usar la que viene con std::
   int temp = *m;
   *m = *n; 
   *n = temp;
}


void sort_(vector<int>& s)
{
   //Es un sort tuneado para que haga lo que queremos. 
   //Ordena de menor a mayor un array ignorando la posicion de los 0's
   int n = s.size();
   for(int i = 0; i < n - 1; i++)
   {
      int min_pos = i;
      for(int j = i + 1; j < n; j++)
         if(s[j] < s[min_pos] && s[j] != 0)
            min_pos = j;
      
      swap(&s[min_pos], &s[i]);
   }
}

void solve(vector<int>& s)
{
   sort_(s);

   std::cout << "\nAhora sorteado sin el 0:\n";
   for(auto &x : s)
      std::cout << x << " ";
   std::cout << '\n';
 }


int main()
{
   vector<int> test = {10, 0, 7, 6 ,5, 4, 3, 0, 2, 1 };
   for(auto &y : test)
      std::cout << y << " ";
   solve(test);
   
   return 0;
}
