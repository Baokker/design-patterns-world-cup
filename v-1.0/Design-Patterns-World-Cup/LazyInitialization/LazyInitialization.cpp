#include"LazyInitialization.h"

// ��Ϊ��̬����
map<string, Venue*> Venue::types;

Venue* Venue::getVenue(const string& name) {
	Venue*& v = types[name];   // ������map�л�ȡ ���û�о��½�һ��

	if (!v) {                   // �����NULL
		v = new Venue(name); // ���Գ�ʼ
	}
	return v;
}

/*
 * �鿴���
 */
void Venue::printCurrentTypes() {
	if (!types.empty()) {
		cout << "�ѽ��쳡��" << types.size() << "��" << endl;
		for (map<string, Venue*>::iterator iter = types.begin(); iter != types.end(); ++iter) {
			cout << (*iter).first << " ";
		}
		cout << endl;
	}
}

void testLazyInitialization() {
	Venue::getVenue("�������±�������������Ahmad Bin Ali Stadium��");
	Venue::printCurrentTypes();

	Venue::getVenue("������ (Al Bayt Stadium)");
	Venue::printCurrentTypes();

	Venue::getVenue("��Ŭ���� ��Al Janoub Stadium��");
	Venue::printCurrentTypes();

	return;
}