//
// Created by outlaw on 13.07.2022.
//

#ifndef CAN_FIRMWARE_LOADER_UI_DEVICEHOLDER_HPP
#define CAN_FIRMWARE_LOADER_UI_DEVICEHOLDER_HPP

#include <QtCore/QString>
#include <QtCore/QFile>
#include "QDataStream"
#include <Monitor/protos_message.h>
#include <Monitor/socket_adapter.h>
#include <Protos/protos.h>
#include <QtCore/QElapsedTimer>

#define BLOCK_SIZE_FLASH    (512)
#define BYTES_IN_PACKET     (8)
#define PACKETS_IN_BLOCK    (BLOCK_SIZE_FLASH/BYTES_IN_PACKET)

class DeviceHolder{
public:
    std::function<void(uint delta, uint uid, uint addr)> OnNextBlockSignal;
    std::function<void(uint UID)> readyToSendSignal;
    std::function<void(const QString& error, uint uid)> errorSignal;
    std::function<void(uint uid, int msecs)> finishedDevice;

    DeviceHolder() = default;
    DeviceHolder(const QString&, uchar, uint, uchar, uchar);
    bool transmitBlock();
    void ackReceived();
    void missedPackets(uint8_t from, uint8_t len, uint16_t targetBlockNum);
    void unvalidatedBlock(uint16_t targetBlockNum);
    void blockOK(uint receivedBlockNum);
    bool isLastBlock();
    void manageBlock(uint receivedBlockNum);
    uint getStatusBarData() const;
    void finishProcess();
    void restart();
    void sendJumpToBootmsg();
    void finishDevice();

protected:
private:
    uchar Address = 0;
    uint UID = 0;
    uchar UIDType = 0;
    uint currentBlock = 0;
    uint totalBlocks = 0;
    QFile* fwFile;
    QByteArray* BABuffer;
    QDataStream* fileDataStream;
    bool dataPending;
    QElapsedTimer elapsedTimer;
    uchar loadingSWVer = 0;

    bool setBlockSeekFile(uint16_t targetBlockNum, int nOfPackets = PACKETS_IN_BLOCK, int blockOffsetInPackets = 0);
    uint16_t calcCRC(int dataLen);
    void sendDataPackets(int len);
    void sendDatamsg(uint8_t *data, uint absByteNum);
    void sendBootmsg(uchar *data, uint32_t idBytes, uchar msgType);
    void sendAddrCRCmsg(int dataLen);
    void sendFinishFlashMsg();

    void sendStayInBootmsg();
    void processBlock(uint blockNum);
};

#endif //CAN_FIRMWARE_LOADER_UI_DEVICEHOLDER_HPP
