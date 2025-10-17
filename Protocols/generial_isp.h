#ifndef GENERIAL_ISP_H
#define GENERIAL_ISP_H

#include <QObject>

typedef enum {
    ACK = 0x79,
    NACK = 0x1F
} Isp_Reply;

typedef enum {
    CMD_BAUDRATE_AUTOSET = 0x00,
    CMD_CANCEL_READ_PROTECT = 0x01,
    CMD_SET_READ_PROTECT = 0x02,
    CMD_CANCEL_WRITE_PROTECT = 0x03,
    CMD_SET_WRITE_PROTECT = 0x04,
    CMD_GET_SUPPORTED_COMMANDS = 0x05,
    CMD_GET_ID = 0x06,
    CMD_READ_MEMORY = 0x11,
    CMD_ERASE_ALL_MEMORY_V3 = 0x43,
    CMD_ERASE_ALL_MEMORY_V1 = 0x44,
    CMD_WRITE_MEMORY = 0x31,
    CMD_DOWNLOAD_CHECK_READ = 0x51,
    CMD_JUMP_ADDRESS_EXECUTE = 0x21
} Isp_Command;

class Generial_isp : public QObject
{
    Q_OBJECT
public:
    explicit Generial_isp(QObject *parent = nullptr);

signals:

private slots:
    //应答
    bool on_Ack_Nack_Reply(Isp_Reply Isp,);

    //从机波特率自动设置及连接
    void on_BaudRate_AutoSet_Send();
    //取消读保护
    void on_Cancel_Read_Protect_Send();
    //设置读保护
    void on_Set_Read_Protect_Send();
    //取消写保护
    void on_Cancel_Write_Protect_Send();
    //设置写保护
    void on_Set_Write_Protect_Send();
    //获取支持的指令
    void on_Get_Supported_Commands_Send();
    //获取ID
    void on_Get_ID_Send();
    //读存储器
    void on_Read_Memory();
    //MCU全片擦除V3版
    void on_Erase_All_Memory_Send_V3();
    //MCU全片擦除V1版
    void on_Erase_All_Memory_Send_V1();
    //写存储器
    void on_Write_Memory(const QByteArray &data, uint32_t length);
    //下载校验读取
    void on_Download_Check_Read();
    //跳转地址执行
    void on_Jump_Address_Execute_Send();

};

#endif // GENERIAL_ISP_H
