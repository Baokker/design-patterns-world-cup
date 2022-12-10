#include<iostream>
#include<string>
#include<vector>
using namespace std;

class AudienceVO {
private:

    string country;
    int audienceNum;

public:

    AudienceVO(string country, int audienceNum) {
        this->country = country;
        this->audienceNum = audienceNum;
    }

    string getCountry() {
        return country;
    }

    void setcountry(string country) {
        this->country = country;
    }

    int getAudienceNum() {
        return audienceNum;
    }

    void setAudienceNum(int audienceNum) {
        this->audienceNum = audienceNum;
    }

};

class AudienceBO {
private:
    //�б��ǵ���һ�����ݿ�
    vector<AudienceVO> audienceList;
public:
    AudienceBO() {
    }

    //����һ�����ҵļ�¼
    void addAudience(AudienceVO audience)
    {
        audienceList.push_back(audience);
    }

    //ɾ��ĳһ�����ҵļ�¼
    void deleteAudience(AudienceVO audience) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == audience.getCountry()) {
                cout << "��ɾ��" << iter->getCountry() << "�Ĺ�����Ϣ" << endl;
                audienceList.erase(iter);
                break;
            }
        }
    }

    //��ȡ���й��ҵĹ�����Ϣ
    vector<AudienceVO> getAllAudience() {
        return audienceList;
    }

    //��ȡĳһ�����ҵĹ�����Ϣ
    AudienceVO getAudience(string country) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == country) {
                return *iter;
            }
        }
        return AudienceVO(NULL, -1);
    }

    //����ĳ���ҵĹ�����Ϣ
    void updateAudience(AudienceVO audience) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == audience.getCountry()) {
                cout << audience.getCountry() << "�Ĺ���������" << iter->getAudienceNum() << "��Ϊ" << audience.getAudienceNum() << endl;
                iter->setAudienceNum(audience.getAudienceNum());
                break;
            }
        }
    }

};

void testTransferObject();