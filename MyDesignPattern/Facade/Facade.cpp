#include "Facade.h"


vector<HotelInfo*> Hotel::hotelList;

void Hospital::accountingDetection()
{
    cout << "样本正在进行核酸检测" << endl;
};

HotelInfo::HotelInfo(string h, string l) :
    hotelName(h), location(l) {}

// 采用多例模式创建的酒店
void Hotel::checkIn()
{
    if (hotelList.size() == 0) {
        hotelList.push_back(new HotelInfo("格林豪泰", "场地外围一环路"));
        hotelList.push_back(new HotelInfo("七天连锁", "场地外围三环路"));
        hotelList.push_back(new HotelInfo("橘子水晶", "场地外围二环路"));
        hotelList.push_back(new HotelInfo("燕山国际", "场地外围外郊  "));
    }
    int randNum = rand() % 4;
    HotelInfo* info = hotelList[randNum];
    //HotelInfo* info = new HotelInfo("Great Hotel", "Heping Street");
    cout << "成功入住" << info->hotelName << "酒店，酒店位于" << info->location << endl;
}
void Hotel::sampling()
{
    cout << "已进行核酸采样，样本将送往医院进行检测" << endl;
}


void Transportation::getVehicle()
{
    cout << "已经安排了一辆专车为他们服务" << endl;
}

void Training::trainingLocation()
{
    cout << "安排了专属培训场地" << endl;
}

void Facade::detection()
{
    hotel->sampling();
    hospital->accountingDetection();
}

void Facade::appointTraining()
{
    training->trainingLocation();
    transportation->getVehicle();
}

void Facade::checkIn()
{
    transportation->getVehicle();
    hotel->checkIn();
}

void testFacade()
{
    srand((unsigned)time(0));
    Facade _facade;

    for (int i = 1; i < 6; i++)
    {
        cout << "第 " << i << " 批运动员们来到比赛居住地" << endl;;
        _facade.checkIn();
        _facade.detection();
        _facade.appointTraining();
        cout << endl;
    }
}