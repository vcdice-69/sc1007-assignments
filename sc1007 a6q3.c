#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int current_capacity = 0;
int max_value = 0;

int max(int a, int b){
    if (a < b) return b;
    else return a;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    // dp[i][j] = maximum value achievable with the first i items and capacity j
    int dp[n+1][C+1];
    
    // Initialize the base case: dp[0][j] = 0 and dp[i][0] = 0
    for (int j = 0; j <= C; j++)
        dp[0][j] = 0;
    
    // Iterate over items
    for (int i = 1; i <= n; i++) {
        // Iterate over capacities
        for (int j = 0; j <= C; j++) {
            if (s[i] > j) {
                // If the current item doesn't fit, take the value from the previous row
                dp[i][j] = dp[i-1][j];
            } else {
                // Otherwise, take the maximum of including the item or excluding it
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-s[i]] + v[i]);
            }
        }
    }
    
    // The result is stored in dp[n][C]
    return dp[n][C];
}

 
int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));
    
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);
        
    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    
    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));
        
}
