#include <iostream>
#include <cstdio>
using namespace std ;

int prev[100007] , n , next[100007] ;

#define fi stdin
#define fo stdout

main()
{
    fscanf(fi,"%d",&n) ;
    int last = 0 ;
    int ok   = 1 ;
    for( int i=1;i<=n;i++) prev[i] = i - 1 ;
    for( int i=1;i<=n;i++) next[i] = i + 1 ;
    for( int i=1;i<=n;i++) {
        int val ;
        fscanf(fi,"%d",&val) ;
        if ( val != prev[last] && val < last  ) { ok = 0 ; break ; }
        next[ prev[val] ] = next[val] ;
        prev[ next[val] ] = prev[val] ;
        last = val ;
    }  
    if ( ok ) fprintf(fo,"NO" ) ;
    else fprintf(fo,"YES") ;      
}    
