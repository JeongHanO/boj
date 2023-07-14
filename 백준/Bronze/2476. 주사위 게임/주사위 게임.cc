#include <stdio.h>
 
 
 
int main() {
 
    int x, y, z, prize[1000], max = 0, n, i, sum = 0, big = 0;
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (x == y && x == z && y == z)   
            prize[i] = 10000 + x * 1000;
        else if (x == y || x == z)
            prize[i] = 1000 + x * 100;
        else if (y == z)
            prize[i] = 1000 + z * 100;    
        else {
            if (x > y && x > z)
                max = x;
            else if (y > x && y > z)
                max = y;
            else if (z > x && z > y)
                max = z;                  
            prize[i] = max * 100;
        }
        if (prize[i] > big)
            big = prize[i];
    }
    printf("%d", big);
}
