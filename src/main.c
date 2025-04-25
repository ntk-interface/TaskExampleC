#include <unistd.h>
#include <windows.h>
#include <oik/portable.h>
#include <oik/tmconn/tmconn.h>


// TODO ������ ������������ ��������� ��� �����������
#define APPLICATION_NAME "TaskExampleC"

// TODO ������ ������ �������� ���������� ������, � ��
#define WORKER_DELAY 5000


int main(int argc, char* argv[]) {
    char server_host[80];
    char server_tm[80];
    char server_username[80];
    char server_password[80];

    HANDLE start_event, stop_event;
    DWORD  tm_cid;

	// ���������� ��������� ���
	cfsInitLibrary(NULL, NULL);

	// ������ ���������� ��� ��������� ����� � �������� ���
    // ./TaskExample ������_������������_������ ��������� ���_������������ ������
	// ������ �������: ./TaskExampleC TMS 127.0.0.1 user password
	// ��� ������� � �������� ������� ������ ��������� ��������� �� ����
	strcpy(server_host, "127.0.0.1");
	strcpy(server_tm, "TMS");
	strcpy(server_username, "");
	strcpy(server_password, "");
	if (argc > 1) {
		strcpy(server_tm, argv[1]);
	}
	if (argc > 2) {
		strcpy(server_host, argv[2]);
	}
	if (argc > 3) {
		strcpy(server_username, argv[3]);
	}
	if (argc > 4) {
		strcpy(server_password, argv[4]);
	}

	// ���������� � ������ � �������� ������� ������
	cfsPmonLocalRegisterProcess(argc, argv, &start_event, &stop_event);
	pR_SetEvent(start_event);

    // ��������� ����� � ��������
	cfsSetUser(server_username, server_password);
	tm_cid = tmcConnect(server_host, server_tm, APPLICATION_NAME, NULL, NULL);

    // �������� �����
    char server_time[80];
    tmcSystemTime(tm_cid, server_time, NULL);
	if (tmcIsConnected(tm_cid) == 0) {
		e_printf("�� ������� ����������� � ��������\n");
        return (int) tmcGetLastError();
	}
    m_printf("����������� ����� � ��������\n");

    // ��������� �������� ������
    // TODO �������� ���� ������
    do {
        // ������� � ����������� ������� ����� �������
        tmcSystemTime(tm_cid, server_time, NULL);
        d_printf("����� �� ������� %s\n", server_time);

        // �������� ��������� ������� #TC20:1:1 � ���������� ��� � �������� #TC20:1:2
        short ts_value = tmcStatus(tm_cid, 20, 1, 1);
        tmcSetStatus(tm_cid, 20, 1, 2, (char) ts_value, NULL, 0);

        // �������� �������� ��������� #TT20:1:1 � ���������� ��� � �������� #TT20:1:2
        float ti_value = tmcAnalog(tm_cid, 20, 1, 1, NULL, 0);
        tmcSetAnalog(tm_cid, 20, 1, 2, ti_value, NULL);

        // � ����� �������� ���� �������� �� ������ #TC20:1:1..10 ������� ���������������
        for (short i = 1; i <= 10; i++) {
            tmcSetStatusFlags(tm_cid, 20, 1, i, UNRELIABLE_HDW);
        }

        // � ����� ������ ���� ���������� �� ������ #TT20:1:1..5 ������� ��������� �������
        for (short i = 1; i <= 5; i++) {
            tmcClrAnalogFlags(tm_cid, 20, 1, i, MANUALLY_SET);
        }
    } while (pR_WaitForSingleObject(stop_event, WORKER_DELAY) != pR_WAIT_OBJECT_0);

	tmcDisconnect(tm_cid);

	return 0;
}