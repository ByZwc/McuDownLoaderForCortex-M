#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>

class DownLoader : public QObject
{
    Q_OBJECT
public:
    explicit DownLoader(QObject *parent = nullptr);

    void DownLoader_Recv_Data(uint8_t *data, uint32_t length);

    void DownLoader_Event_Loop();
};

#endif // DOWNLOADER_H
