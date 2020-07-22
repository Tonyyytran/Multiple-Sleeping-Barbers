//
// Created by Tony Tran on 5/8/2020.
//

#ifndef MULTIPLESLEEPINGBARBERS_SHOP_ORG_H
#define MULTIPLESLEEPINGBARBERS_SHOP_ORG_H

#include <pthread.h>
#include <queue>
#include <iostream>
#include <map>

using namespace std;

#define DEFAULT_CHAIRS 3
#define DEFAULT_BARBERS 1

class Shop_org {
public:
    Shop_org( int nBarbers, int nChairs );
    Shop_org( int nChairs );
    Shop_org( );

    int visitShop( int idCustomer );   // return true only when a cluster got a service
    void leaveShop( int idCustomer, int idBarber );
    void helloCustomer( int idBarber );
    void byeCustomer( int idBarber );
    int nDropsOff;              // the number of customers dropped off

private:
    int maxWaiting, maxService;              // the max number of threads that can wait
    bool money_paid;
    queue<int> availableBarbers;
    queue<int> waiting_chairs;  // includes the customer ids of all waiting threads

    pthread_mutex_t mutex;
//    pthread_cond_t  cond_customers_waiting;
//    pthread_cond_t  cond_customer_served;
//    pthread_cond_t  cond_barber_paid;
//    pthread_cond_t  cond_barber_sleeping;
//    pthread_cond_t  *cond_barber_sleeping;

    struct Barber {
        pthread_cond_t  cond_barber_paid;
        pthread_cond_t  cond_barber_sleeping;
        int idBarber;
        int myCustomer = -1;
    };

    struct Customer {
        int idCustomer;
        bool inService = false;
        pthread_cond_t  cond_customers_waiting;
        pthread_cond_t  cond_customer_served;
        int barber = -1;
    };
    Barber *barbers; //array of barber objects
    map<int, Customer> customers; //map for customer objects
    Barber* getBarber(int barberId);
    string int2string( int i );
    void print( int person, string message );
};

#endif //MULTIPLESLEEPINGBARBERS_SHOP_ORG_H
