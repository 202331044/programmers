#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// int get_num(vector<int>& array1, vector<int>& array2)
// {
//     int div_term = array1[0];
    
//     for(int i = 0; i < array1.size(); ++i)
//         div_term = gcd(div_term, array1[i]);
    
//     for(div_term; div_term >= 2; --div_term)
//     {
//         bool isValid1 = true;
        
//         for(int i = 0; i < array1.size(); ++i)
//         {
//             if(array1[i] % div_term != 0)
//             {
//                 isValid1 = false;
//                 break;
//             }
//         }
        
//         if(isValid1) 
//         {
//             bool isValid2 = true;
//             for(int j = 0; j < array2.size(); ++j)
//             {
//                 if(array2[j] % div_term == 0)
//                 {
//                     isValid2 = false;
//                     break;
//                 }
//             }
            
//             if(isValid2) return div_term;
//         }
//     }
    
//     return 0;
// }

int get_div(vector<int>& array1, vector<int>& array2)
{
    int div_term = array1[0];
    
    for(int x: array1)
        div_term = gcd(div_term, x);
    
    for(int x: array2)
        if(x % div_term == 0) return 0;
    
    return div_term;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    //int answer = max(get_num(arrayA, arrayB), get_num(arrayB, arrayA));
    
    int answer = max(get_div(arrayA, arrayB), get_div(arrayB, arrayA));
    return answer;
}
