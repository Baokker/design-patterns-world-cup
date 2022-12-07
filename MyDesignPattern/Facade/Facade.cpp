#include "Facade.h"


vector<HotelInfo*> Hotel::hotelList;

void Hospital::accountingDetection()
{
    cout << "�������ڽ��к�����" << endl;
};

HotelInfo::HotelInfo(string h, string l) :
    hotelName(h), location(l) {}

// ���ö���ģʽ�����ľƵ�
void Hotel::checkIn()
{
    if (hotelList.size() == 0) {
        hotelList.push_back(new HotelInfo("���ֺ�̩", "������Χһ��·"));
        hotelList.push_back(new HotelInfo("��������", "������Χ����·"));
        hotelList.push_back(new HotelInfo("����ˮ��", "������Χ����·"));
        hotelList.push_back(new HotelInfo("��ɽ����", "������Χ�⽼  "));
    }
    int randNum = rand() % 4;
    HotelInfo* info = hotelList[randNum];
    //HotelInfo* info = new HotelInfo("Great Hotel", "Heping Street");
    cout << "�ɹ���ס" << info->hotelName << "�Ƶ꣬�Ƶ�λ��" << info->location << endl;
}
void Hotel::sampling()
{
    cout << "�ѽ��к������������������ҽԺ���м��" << endl;
}


void Transportation::getVehicle()
{
    cout << "�Ѿ�������һ��ר��Ϊ���Ƿ���" << endl;
}

void Training::trainingLocation()
{
    cout << "������ר����ѵ����" << endl;
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
        cout << "�� " << i << " ���˶�Ա������������ס��" << endl;;
        _facade.checkIn();
        _facade.detection();
        _facade.appointTraining();
        cout << endl;
    }
}