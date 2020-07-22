#include <iostream>    // cout
#include <sys/time.h> // gettimeofday
#include <unistd.h>
#include "Shop_org.h"

using namespace std;

void *barber( void * );
void *customer( void * );
pthread_mutex_t mutex;

class ThreadParam {
public:
    ThreadParam( Shop_org *shop, int id, int serviceTime ) : shop( shop ), id( id ), serviceTime( serviceTime ) { };
    Shop_org *shop;               // a pointer to the Shop object
    int id;                   // a thread identifier
    int serviceTime;          // service time for 1000 usecs customers spawn randomly between 1000 usec from the last
};

int main( int argc, char *argv[] ) {

    int nBarbers = atoi( argv[1]);
    int nChairs = atoi( argv[2] );
    int nCustomers = atoi( argv[3] );
    int serviceTime = atoi( argv[4] );

    pthread_t barber_thread[nBarbers];
    pthread_t customer_threads[nCustomers];
    Shop_org shop( nBarbers, nChairs );

    for ( int i = 0; i < nBarbers; i++){
        ThreadParam *paramBarber = new ThreadParam( &shop, i, serviceTime );
        pthread_create( &barber_thread[i], NULL, barber, (void*)paramBarber );
    }

    for ( int i = 0; i < nCustomers; i++ ) {
        usleep( rand( ) % 1000 );
        ThreadParam *paramCustomer = new ThreadParam( &shop, i, serviceTime );
        pthread_create( &customer_threads[i], NULL, customer, paramCustomer );
    }

    for ( int i = 0; i < nCustomers; i++ ) {
        pthread_join(customer_threads[i], NULL);
    }
    for ( int i = 0; i < nBarbers; i++ ) {
        pthread_cancel(barber_thread[i]);
    }
    usleep(  1000 );
    cout << "# customers who didn't receive a service = " << shop.nDropsOff<< endl;
    return 0;
}

void *barber( void *arg ) {

    ThreadParam &paramBarber = *(ThreadParam *)arg;
    Shop_org &shop = *(paramBarber.shop);
    int idBarber = paramBarber.id;
    int serviceTime = paramBarber.serviceTime;
    delete &paramBarber;

    while( true ) {
        shop.helloCustomer( idBarber );
        usleep( serviceTime );
        shop.byeCustomer( idBarber );
    }
}

void *customer( void *arg ) {

    ThreadParam &paramCustomer = *(ThreadParam *)arg;
    Shop_org &shop = *(paramCustomer.shop);
    int idCustomer = paramCustomer.id;
    delete &paramCustomer;

    int doneBy = shop.visitShop(idCustomer);
    if ( doneBy != -1 )
        shop.leaveShop( idCustomer, doneBy );
    return NULL;
}
