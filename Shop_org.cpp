//
// Created by Tony Tran on 5/8/2020.
//
#include <iostream> // cout
#include <sstream>  // stringstream
#include <string>   // string
#include "Shop_org.h"

//void Shop_org::init( ) {
//    pthread_mutex_init( &mutex, NULL );
//    pthread_cond_init( &cond_customers_waiting, NULL );
//    pthread_cond_init( &cond_customer_served, NULL );
//    pthread_cond_init( &cond_barber_paid, NULL );
//    //pthread_cond_init( &cond_barber_sleeping, NULL );
//    cond_barber_sleeping = new pthread_cond_t[maxService];
//}
Shop_org::Shop_org( int nBarbers, int nChairs ) // initialize a Shop object with nBarbers and nChairs
{
    this -> maxService = nBarbers;
    this -> maxWaiting = nChairs;

    pthread_mutex_init(&mutex, NULL);

    barbers = new Barber[nBarbers];
    for (int i = 0; i < nBarbers; i++)
    {
        barbers[i].idBarber = i;
        pthread_cond_init(&barbers[i].cond_barber_sleeping, NULL);
        pthread_cond_init(&barbers[i].cond_barber_paid, NULL);
    }
}

Shop_org::Shop_org( ) // initialize a Shop object with 1 barber and 3 chairs
{
    this -> maxService = DEFAULT_BARBERS;
    this -> maxWaiting = DEFAULT_CHAIRS;

    pthread_mutex_init(&mutex, NULL);

    barbers = new Barber[maxService];
    for (int i = 0; i < maxService; i++)
    {
        barbers[i].idBarber = i;
        pthread_cond_init(&barbers[i].cond_barber_sleeping, NULL);
    }
}

Shop_org::Shop_org( int nChairs) // initialize with the defaults 1 barber and multiple chairs like the original sleeping barber
{
    this -> maxService = DEFAULT_BARBERS;
    this -> maxWaiting = nChairs;

    pthread_mutex_init(&mutex, NULL);

    barbers = new Barber[maxService];
    for (int i = 0; i < maxService; i++)
    {
        barbers[i].idBarber = i;
        pthread_cond_init(&barbers[i].cond_barber_sleeping, NULL);
    }
}

string Shop_org::int2string( int i ) {
    stringstream out;
    out << i;
    return out.str( );
}

void Shop_org::print( int person, string message ) {
    if(person >= 0){
        cout << "customer["  << person << "]: " << message << endl;
    }
    else{
        cout << "barber  ["  << -person << "]: " << message << endl;
    }
}

int Shop_org::visitShop( int idCustomer ) {
    pthread_mutex_lock( &mutex );   // lock
    if ((waiting_chairs.size( ) == maxWaiting) && availableBarbers.empty()) {  // waiting chairs are all occupied
        print( idCustomer + 1,"leaves the shop because of no available waiting chairs.");
        ++nDropsOff;
        pthread_mutex_unlock( &mutex );
        return -1;                 // leave the shop
    }
    customers[idCustomer] = Customer();
    customers[idCustomer].idCustomer = idCustomer;
    pthread_cond_init(&customers[idCustomer].cond_customers_waiting, NULL);
    pthread_cond_init(&customers[idCustomer].cond_customer_served, NULL);
    int doneBy;

    if ( availableBarbers.empty() ) {    // if all barbers are busy and there are waiting chairs available
        waiting_chairs.push( idCustomer );    // have a waiting chair
        print( idCustomer + 1, "takes a waiting chair. # waiting seats available = " + int2string( maxWaiting - waiting_chairs.size( ) ) );
        //cout << "                                               ****** wait customer waiting" << endl; // ***********
        while( customers[idCustomer].barber == -1){
            pthread_cond_wait(&customers[idCustomer].cond_customers_waiting, &mutex);
        }
        doneBy = customers[idCustomer].barber;
    }
    else{   // there are available barbers
        doneBy = availableBarbers.front();
        availableBarbers.pop();
        customers[idCustomer].barber = doneBy;
        getBarber(doneBy) -> myCustomer = idCustomer;
    }
    // there are service chairs available
    print( idCustomer + 1, "moves to the service chair[" + int2string(doneBy + 1) + "] # waiting seats available = " + int2string(maxWaiting - waiting_chairs.size( ) ) );
    //service_chair = idCustomer;             // have the service chair
    customers[idCustomer].inService = true;
    // wake up the barber just in case if he is sleeping
    //cout << "                                               ****** signal sleeping barber" << endl; // ***************
    pthread_cond_signal( &getBarber(doneBy)->cond_barber_sleeping );// [availableBarbers.front()] );
    pthread_mutex_unlock( &mutex ); // unlock
    return doneBy;
}

void Shop_org::leaveShop( int idCustomer , int idBarber ) {
    pthread_mutex_lock( &mutex );   // lock
    print( idCustomer + 1, "wait for the hair-cut to be done" );
    //cout << "                                                   ****** wait customer served" << endl; // ************
    while ( customers[idCustomer].barber != -1 ) {                           // while being served
        pthread_cond_wait(&customers[idCustomer].cond_customer_served, &mutex);  // just sit.
    }
    money_paid = true;
    print( idCustomer + 1, "says good-bye to the barber." );
    //cout << "                                               ****** signal barber paid" << endl; // ******************
    pthread_cond_signal( &getBarber(idBarber) -> cond_barber_paid );
    pthread_mutex_unlock( &mutex ); // unlock
}

void Shop_org::helloCustomer( int idBarber ) {
    pthread_mutex_lock( &mutex );   // lock
    if ( getBarber(idBarber) -> myCustomer == -1 ) { // no customers
        print( -(idBarber + 1), "sleeps because of no customers." );
        availableBarbers.push(idBarber);
        //cout << "                                           ****** wait sleeping barber" << endl; // ************
        while(getBarber(idBarber) -> myCustomer == -1) {
            pthread_cond_wait( &(getBarber(idBarber) -> cond_barber_sleeping), &mutex); //[id], &mutex ); // then, let's sleep
        }
    }
    //cout << "                                                   ****** wait sleeping barber" << endl; //*********
    while(customers[getBarber(idBarber)->myCustomer].inService != true){
        pthread_cond_wait(&(getBarber(idBarber) -> cond_barber_sleeping), &mutex);
    }
    print( -(idBarber + 1), "starts a hair-cut service for " + int2string( getBarber(idBarber) -> myCustomer + 1 ) );
    //availableBarbers.pop();
    pthread_mutex_unlock( &mutex );  // unlock
}

void Shop_org::byeCustomer( int idBarber ) {
    pthread_mutex_lock( &mutex );    // lock
    customers[getBarber(idBarber)->myCustomer].inService = false;
    print( -(idBarber + 1), "says he's done with a hair-cut service for " + int2string( getBarber(idBarber)->myCustomer + 1 ) );
    // reset conditions
    money_paid = false;
    customers[getBarber(idBarber) -> myCustomer].barber = -1;
    //cout << "                                                           ******* signal customer served" << endl;
    pthread_cond_signal( &customers[getBarber(idBarber) -> myCustomer].cond_customer_served );   // tell the customer "done"
    //cout << "                                                           ******* Wait barber paid" << endl;
    while ( money_paid == false ) {
        pthread_cond_wait(&(getBarber(idBarber) -> cond_barber_paid), &mutex);
    }
    getBarber(idBarber) -> myCustomer = -1;
    print( -(idBarber + 1), "calls in another customer" );
    if( !waiting_chairs.empty() ){
        int customerId = waiting_chairs.front();
        waiting_chairs.pop();
        getBarber(idBarber) -> myCustomer = customerId;
        customers[customerId].barber = idBarber;
        //cout << "                                               ******* signal customer waiting" << endl; // ***********
        pthread_cond_signal(&customers[customerId].cond_customers_waiting);
    }
    pthread_mutex_unlock( &mutex );  // unlock
}

Shop_org::Barber* Shop_org::getBarber(int idBarber)
{
    for (int i = 0; i< maxService; i++)
    {
        if (barbers[i].idBarber == idBarber)
        {
            return &barbers[i];
        }
    }
    return NULL;
}