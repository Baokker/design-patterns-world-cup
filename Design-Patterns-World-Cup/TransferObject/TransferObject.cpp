#include "TransferObject.h"
#include<iomanip>



//������е��˶�Ա
void outputAll(AudienceBO audienceObject)
{
	vector<AudienceVO> audienceList = audienceObject.getAllAudience();
	cout << endl;
	//cout << setw(50) << setfill(' ') << "------------------------------" << endl;
	cout << endl;
	cout << "������Ϣ��" << endl;
	cout << setiosflags(ios::left);
	for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
		cout << setw(35) << setfill(' ') << iter->getCountry() << iter->getAudienceNum() << endl;
	}
	//cout << setw(50) << setfill('-') << "------------------------------" << endl;
	cout << endl;
}



void testTransferObject() {
    AudienceBO audienceObject;

	//���������Ϣ
	audienceObject.addAudience(AudienceVO("�й�", 100860));
	audienceObject.addAudience(AudienceVO("����͢", 66176));
	audienceObject.addAudience(AudienceVO("������", 7677));
	audienceObject.addAudience(AudienceVO("����", 88486));
	audienceObject.addAudience(AudienceVO("������", 164513));
	audienceObject.addAudience(AudienceVO("�¹�", 41634));
	audienceObject.addAudience(AudienceVO("����", 343146));

	cout << "���ȫ��������Ϣ��" << endl;
	outputAll(audienceObject);

	cout << endl << "���Ĳ��ֹ�����Ϣ��" << endl;
	audienceObject.updateAudience(AudienceVO("����", 666666));
	audienceObject.updateAudience(AudienceVO("�й�", 6163453));
	audienceObject.updateAudience(AudienceVO("����", 77777));

	cout << endl << "ɾ�����ֹ�����Ϣ��" << endl;
	audienceObject.deleteAudience(audienceObject.getAudience("������"));
	audienceObject.deleteAudience(audienceObject.getAudience("�¹�"));
	audienceObject.deleteAudience(audienceObject.getAudience("����"));

	cout << "�ٴ����ȫ��������Ϣ��" << endl;
	outputAll(audienceObject);
}