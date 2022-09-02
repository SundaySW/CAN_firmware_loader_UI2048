//
// Created by outlaw on 27.05.2022.
//

#ifndef CAN_FIRMWARE_LOADER_UI_FWTRANSPORTER_HPP
#define CAN_FIRMWARE_LOADER_UI_FWTRANSPORTER_HPP

#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/QLabel>
#include "DeviceHolder.hpp"
#include "protos_message.h"
#include "protos.h"

class FWLoader: public QObject
{
    Q_OBJECT
public:
    FWLoader();
    void transmitBlocks();
    void transmitBlock(uint UID);
    void ParseBootMsg(const ProtosMessage &msg);
    void cancelFWLoad(uint UID);
signals:
    void signalAckReceived();
    void signalNextBlock(uint delta, uint uid, uint addr);
    void signalFinishedOK(uint uid, int msecs);
    void signalBootData(uint UID);
    void signalError(const QString& error, uint uid);
public slots:
    void addDevice(const QString &fileName, uchar addr, uint uid, uchar uidT);

private:
    void removeDevice(uint uid, int msecs);
    QMap<uint32_t, DeviceHolder> deviceList;
    int adapterDelay;
    volatile bool busy;
};

#endif //CAN_FIRMWARE_LOADER_UI_FWTRANSPORTER_HPP
