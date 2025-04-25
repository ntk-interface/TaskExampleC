#include <unistd.h>
#include <windows.h>
#include <oik/portable.h>
#include <oik/tmconn/tmconn.h>


// TODO задать наименование программы для трассировки
#define APPLICATION_NAME "TaskExampleC"

// TODO задать период задержки выполнения задачи, в мс
#define WORKER_DELAY 5000


int main(int argc, char *argv[]) {
    char server_host[80];
    char server_tm[80];
    char server_username[80];
    char server_password[80];

    HANDLE start_event, stop_event;
    DWORD  tm_cid;

    // подготовка библиотек ОИК
    cfsInitLibrary(NULL, NULL);

    // чтение аргументов дл¤ установки связи с сервером ОИК
    // ./TaskExampleC сервер_динамических_данных компьютер имя_пользователя пароль
    // пример запуска: ./TaskExampleC TMS 127.0.0.1 user password
    // при запуске в качестве внешней задачи параметры указывать не надо
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

    // подготовка к работе в качестве внешней задачи
    cfsPmonLocalRegisterProcess(argc, argv, &start_event, &stop_event);
    pR_SetEvent(start_event);

    // установка связи с сервером
    cfsSetUser(server_username, server_password);
    tm_cid = tmcConnect(server_host, server_tm, APPLICATION_NAME, NULL, NULL);

    // проверка связи
    char server_time[80];
    tmcSystemTime(tm_cid, server_time, NULL);
    if (tmcIsConnected(tm_cid) == 0) {
        e_printf("Не удалось соединиться с сервером\n");
        return (int) tmcGetLastError();
    }
    m_printf("Установлена связь с сервером\n");

    // обработка действий задачи
    // TODO написать свою логику
    do {
        // выводим в трассировку текущее время сервера
        tmcSystemTime(tm_cid, server_time, NULL);
        d_printf("Время на сервере %s\n", server_time);

        // получаем состояние сигнала #TC20:1:1 и записываем его в соседний #TC20:1:2
        short ts_value = tmcStatus(tm_cid, 20, 1, 1);
        tmcSetStatus(tm_cid, 20, 1, 2, (char) ts_value, NULL, 0);

        // получаем значение измерения #TT20:1:1 и записываем его в соседний #TT20:1:2
        float ti_value = tmcAnalog(tm_cid, 20, 1, 1, NULL, 0);
        tmcSetAnalog(tm_cid, 20, 1, 2, ti_value, NULL);

        // в цикле выставим всем сигналам из списка #TC20:1:1..10 признак недостоверности
        for (short i = 1; i <= 10; i++) {
            tmcSetStatusFlags(tm_cid, 20, 1, i, UNRELIABLE_HDW);
        }

        // в цикле снимем всем измерениям из списка #TT20:1:1..5 признак установки вручную
        for (short i = 1; i <= 5; i++) {
            tmcClrAnalogFlags(tm_cid, 20, 1, i, MANUALLY_SET);
        }
    } while (pR_WaitForSingleObject(stop_event, WORKER_DELAY) != pR_WAIT_OBJECT_0);

    tmcDisconnect(tm_cid);

    return 0;
}