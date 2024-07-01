#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *prev_solutions;


int top_down_dp(int n)
{
    if (n <= 2) return n;
    
    // Check if prev_solutions is initialized
    if (prev_solutions == NULL) {
        prev_solutions = (int *)malloc(sizeof(int) * (n + 1)); // Allocate memory for n+1 elements
        for (int i = 0; i <= n; i++)
            prev_solutions[i] = -1; // Initialize all elements to -1
    }

    // Check if the value for n has been calculated before
    if (prev_solutions[n] == -1) {
        // Recursively calculate F(n-1), F(n-2), and F(n-3)
        int fn_minus_1 = top_down_dp(n - 1);
        int fn_minus_2 = top_down_dp(n - 2);
        int fn_minus_3 = top_down_dp(n - 3);
        
        // Store the calculated value for n
        prev_solutions[n] = fn_minus_1 + 2 * fn_minus_2 - 3 * fn_minus_3;
    }

    return prev_solutions[n];
}


 
int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    

    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));
        
}
