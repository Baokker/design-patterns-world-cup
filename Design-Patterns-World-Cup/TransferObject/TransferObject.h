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
    //列表是当作一个数据库
    vector<AudienceVO> audienceList;
public:
    AudienceBO() {
    }

    //增加一个国家的记录
    void addAudience(AudienceVO audience)
    {
        audienceList.push_back(audience);
    }

    //删除某一个国家的记录
    void deleteAudience(AudienceVO audience) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == audience.getCountry()) {
                cout << "已删除" << iter->getCountry() << "的观众信息" << endl;
                audienceList.erase(iter);
                break;
            }
        }
    }

    //获取所有国家的观众信息
    vector<AudienceVO> getAllAudience() {
        return audienceList;
    }

    //获取某一个国家的观众信息
    AudienceVO getAudience(string country) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == country) {
                return *iter;
            }
        }
        return AudienceVO(NULL, -1);
    }

    //更改某国家的观众信息
    void updateAudience(AudienceVO audience) {
        for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
            if (iter->getCountry() == audience.getCountry()) {
                cout << audience.getCountry() << "的观众数量由" << iter->getAudienceNum() << "变为" << audience.getAudienceNum() << endl;
                iter->setAudienceNum(audience.getAudienceNum());
                break;
            }
        }
    }

};

void testTransferObject();