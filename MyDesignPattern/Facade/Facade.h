#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

//Hospital
class Hospital
{
public:
    Hospital() {};
    ~Hospital() {};
    void accountingDetection();
};

struct HotelInfo {
    string hotelName;
    string location;
    HotelInfo(string h, string l);
};

//Hotel, multion is adopted
class Hotel
{
private:
    const int hotelNum = 4;//4 hotels to choose from
    static vector<HotelInfo*> hotelList;

public:
    Hotel() {};
    ~Hotel() {};
    void checkIn();
    void sampling();
};


//Transportation
class Transportation
{
public:
    Transportation() {};
    ~Transportation() {};
    void getVehicle();
};

//Training
class Training
{
public:
    Training() {};
    ~Training() {};
    void trainingLocation();
};

//Facade
class Facade
{
public:
    ~Facade() {};
    //nucleic acid test
    void detection();
    //Appointment training
    void appointTraining();
    //Handle settlement
    void checkIn();
private:
    Hospital* hospital;
    Hotel* hotel;
    Transportation* transportation;
    Training* training;
};


void testFacade();
