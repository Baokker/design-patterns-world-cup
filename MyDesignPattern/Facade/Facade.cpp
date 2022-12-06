#include "Facade.h"


vector<HotelInfo*> Hotel::hotelList;

void Hospital::AccountingDetection()
{
    cout << "�������ڽ��к�����" << endl;
};

HotelInfo::HotelInfo(string h, string l) :
    hotelName(h), location(l) {}

// ���ö���ģʽ�����ľƵ�
void Hotel::CheckIn()
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
void Hotel::Sampling()
{
    cout << "�ѽ��к������������������ҽԺ���м��" << endl;
}


void Transportation::GetVehicle()
{
    cout << "�Ѿ�������һ��ר��Ϊ���Ƿ���" << endl;
}

void Training::TrainingLocation()
{
    cout << "������ר����ѵ����" << endl;
}

void Facade::Detection()
{
    _hotel->Sampling();
    _hospital->AccountingDetection();
}

void Facade::AppointTraining()
{
    _training->TrainingLocation();
    _transportation->GetVehicle();
}

void Facade::CheckIn()
{
    _transportation->GetVehicle();
    _hotel->CheckIn();
}

void TestFacade()
{
    srand((unsigned)time(0));
    Facade _facade;

    for (int i = 1; i < 6; i++)
    {
        cout << "�� " << i << " ���˶�Ա������������ס��" << endl;;
        _facade.CheckIn();
        _facade.Detection();
        _facade.AppointTraining();
        cout << endl;
    }
}