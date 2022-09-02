//
// Created by outlaw on 01.06.2022.
//
#pragma once
#ifndef SA_PICO_CAN_BOOTLOADER_PROTOS_BOOT_MSG_HPP
#define SA_PICO_CAN_BOOTLOADER_PROTOS_BOOT_MSG_HPP

#include "ican_device.h"
#include "protos_msg.h"

namespace Protos
{
    class BootMsg
    {
    public:
        BootMsg() {
        }

        BootMsg(const Protos::Msg& msg)
        {
            Dlc = msg.Dlc;
            ExtId.Bytes = msg.Id.Ext;
            for (int i = 0; i < Dlc; i++)
                Data[i] = msg.Data[i];
        }

        union
        {
            struct
            {
                unsigned long ServiceByte2  : 8;  ///< 24-bit Offset or UID
                unsigned long ServiceByte1  : 8;
                unsigned long ServiceByte0  : 8;
                unsigned long MsgType	    : 3;  ///< type of boot msg
                unsigned long BootLoader    : 1;  ///< BootLoader Id
                unsigned long Protocol	    : 1;  ///< Protos or RAW-protocol
            } bit;
            unsigned long Bytes;
            unsigned char Tab[4];
        } ExtId;

        unsigned char GetMSGType() const
        {
            return (ExtId.bit.MsgType);
        }

        uint16_t GetFlowCMDCode() const
        {
            return (Data[3] + (Data[4] << 8));
        }

        uint16_t GetCRC16() const {
            return (Data[0] + (Data[1] << 8));
        }

        uint32_t GetPacketNum() const {
            return (ExtId.Tab[0] + (ExtId.Tab[1] << 8) + (ExtId.Tab[2] << 16));
        }

        unsigned char GetDestID() const
        {
            return Data[2];
        }

        enum { DATA_SIZE = 8 };
        unsigned char Dlc;
        unsigned char Data[DATA_SIZE];
    };
}

#endif //SA_PICO_CAN_BOOTLOADER_PROTOS_BOOT_MSG_HPP
