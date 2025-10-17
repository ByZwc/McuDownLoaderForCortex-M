#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>

class DownLoader : public QObject
{
    Q_OBJECT
public:
    explicit DownLoader(QObject *parent = nullptr);

signals:
};

#endif // DOWNLOADER_H
