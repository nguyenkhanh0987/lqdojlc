#include <bits/stdc++.h>
#include <algorithm>

using namespace std ;

typedef long long ll ;
const ll MAXn = 307 ;
const ll MAXv = 1e6 + 7 ; 

ll a [ MAXn ] [ MAXn ] , dp [ MAXn ] [ MAXn ] [ MAXn ] , d [ MAXn ] [ MAXn ] , n , m , res ;
bool is_prime [ MAXv ] ; 

void eratosthenes ( ) {

    is_prime [ 0 ] = 1 ;
    is_prime [ 1 ] = 1 ; 

    for ( int i = 2 ; i <= sqrt ( MAXv ) ; i ++ ) {
        if ( is_prime [ i ] == 0 ) {
            for ( int j = i * i ; j <= MAXv - 5 ; j += i ) {
                is_prime [ j ] = 1 ;
            }
        } 
    }

}

main ( )  {
    
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    cout.tie ( NULL ) ;

    cin >> n >> m ;

    eratosthenes ( ) ;

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = 0 ; j < m ; j ++ ) {
            cin >> a [ i ] [ j ] ;
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = i + 1 ; j < n ; j ++ ) {
            for ( int x = m - 1 ; x >= 0 ; x -- ) {
                dp [ i ] [ j ] [ x ] += dp [ i ] [ j ] [ x + 1 ] ;
                if ( is_prime [ a [ i ] [ x ] ] == 0 && is_prime [ a [ j ] [ x ] ] == 0 ) {
                    dp [ i ] [ j ] [ x ] ++ ;
                }
            }
        }
    }

    for ( int i = 0 ; i < n ; i ++ ) {
        for ( int j = m - 1 ; j >= 0 ; j -- ) {
            d [ i ] [ j ] += d [ i ] [ j + 1 ] + ( ( ( is_prime [ a [ i ] [ j ] ] & 1 ) + 1 ) % 2 ) ;
        }
    }

    for ( int i = 0 ; i < n - 1 ; i ++ ) {
        for ( int x = 0 ; x < m - 1 ; x ++ ) {
            for ( int j = i + 1 ; j < n ; j ++ ) {
                ll check = is_prime [ a [ i ] [ x ] ] + is_prime [ a [ j ] [ x ] ] ;
                if ( check < 2 ) {
                    if ( check == 1 ) {
                        res += dp [ i ] [ j ] [ x + 1 ] ;
                    }
                    else {
                        res += d [ i ] [ x + 1 ] + d [ j ] [ x + 1 ] - dp [ i ] [ j ] [ x + 1 ] ;
                    }
                } 
            }
        }
    }

    cout << res ;

}