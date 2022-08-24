#include <bits/stdc++.h>
#include <algorithm>
#define int long long

using namespace std ; 

typedef long long ll ;
const int MAXn = 1e3+6 ;

ll dp [ 12 ] [ 2 ] [ 55 ] [ 55 ] ; int a , b ;
bool is_prime [ MAXn ] ;

void eratosthenes ( ) {
    is_prime [ 0 ] = 1 ;
    is_prime [ 1 ] = 1 ;
    
    for ( int i = 2 ; i <= sqrt ( MAXn ) ; i ++ ) {
        if ( is_prime [ i ] == false ) {
            for ( int j = i * i ; j <= MAXn ; j += i ) {
                is_prime [ j ] = true ; 
            }
        }
    }
}

string tostring ( int n ) {
    string convert_string ;
    while ( n ) {
        convert_string += ( n % 10 ) + '0' ;
        n /= 10 ;
    }
    return convert_string ;
}

ll calc ( string str , int idx , bool smaller , int sumeven , int sumodd ){
    
    if ( idx == -1 ) {
        if ( sumeven > sumodd ) { return is_prime [ sumeven - sumodd ] == 0 ; }
        else { return 0 ; } 
    }
    if ( dp [ idx ] [ smaller ] [ sumeven ] [ sumodd ] != -1LL ) {
        return dp [ idx ] [ smaller ] [ sumeven ] [ sumodd ] ;
    }
    int limit = smaller ? str [ idx ] - '0' : 9 ; ll sol = 0LL ;
    for ( int i = 0 ; i <= limit ; i ++ ) {
        if ( idx % 2 == 0 ){
            if ( i == limit && smaller == 1 ) {
                sol += calc ( str , idx - 1 , 1 , sumeven , sumodd + i ) ;
            }
            else {
                sol += calc ( str , idx - 1 , 0 , sumeven , sumodd + i ) ;
            }
        }
        else {
            if ( i == limit && smaller == 1 ) {
                sol += calc ( str , idx - 1 , 1 , sumeven + i , sumodd ) ;
            }
            else {
                sol += calc ( str , idx - 1 , 0 , sumeven + i , sumodd ) ;
            }
        }
    }
    dp [ idx ] [ smaller ] [ sumeven ] [ sumodd ] = sol ;
    
    return sol ;

} 

ll solve ( int n ) {
    if ( n < 0 ) return 0 ;
    string str = tostring ( n ) ;
    memset ( dp , -1 , sizeof ( dp ) ) ;
    return calc ( str , str.size ( ) - 1 , 1 , 0 , 0 ) ;
} 

main ( ) { 

    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    cout.tie ( NULL ) ;
    
    // freopen ( "Digit.inp" , "r" , stdin ) ;
    // freopen ( "Digit.out" , "w" , stdout ) ;
    
    eratosthenes ( ) ;
    ll t ; cin >> t ; 
    while ( t -- ) {
        cin >> a >> b ;
        ll res = solve ( b ) - solve ( a ) ;
        cout << res << '\n' ;
    } 
    
}