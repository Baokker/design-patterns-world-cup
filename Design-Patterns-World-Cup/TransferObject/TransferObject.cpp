#include "TransferObject.h"
#include<iomanip>



//输出所有的运动员
void outputAll(AudienceBO audienceObject)
{
	vector<AudienceVO> audienceList = audienceObject.getAllAudience();
	cout << endl;
	//cout << setw(50) << setfill(' ') << "------------------------------" << endl;
	cout << endl;
	cout << "观众信息：" << endl;
	cout << setiosflags(ios::left);
	for (vector<AudienceVO>::iterator iter = audienceList.begin(); iter != audienceList.end(); iter++) {
		cout << setw(35) << setfill(' ') << iter->getCountry() << iter->getAudienceNum() << endl;
	}
	//cout << setw(50) << setfill('-') << "------------------------------" << endl;
	cout << endl;
}



void testTransferObject() {
    AudienceBO audienceObject;

	//插入国家信息
	audienceObject.addAudience(AudienceVO("中国", 100860));
	audienceObject.addAudience(AudienceVO("阿根廷", 66176));
	audienceObject.addAudience(AudienceVO("葡萄牙", 7677));
	audienceObject.addAudience(AudienceVO("巴西", 88486));
	audienceObject.addAudience(AudienceVO("西班牙", 164513));
	audienceObject.addAudience(AudienceVO("德国", 41634));
	audienceObject.addAudience(AudienceVO("法国", 343146));

	cout << "输出全部国家信息：" << endl;
	outputAll(audienceObject);

	cout << endl << "更改部分国家信息：" << endl;
	audienceObject.updateAudience(AudienceVO("巴西", 666666));
	audienceObject.updateAudience(AudienceVO("中国", 6163453));
	audienceObject.updateAudience(AudienceVO("巴西", 77777));

	cout << endl << "删除部分国家信息：" << endl;
	audienceObject.deleteAudience(audienceObject.getAudience("西班牙"));
	audienceObject.deleteAudience(audienceObject.getAudience("德国"));
	audienceObject.deleteAudience(audienceObject.getAudience("法国"));

	cout << "再次输出全部国家信息：" << endl;
	outputAll(audienceObject);
}