#include "qudpsocket.h"
#include <QtCore>
#include <QUdpSocket>
#include <QFile>
#include <QDataStream>

class UdpSender : public QObject {
    Q_OBJECT

public:
    UdpSender() {
        // 设置UDP套接字
        socket = new QUdpSocket(this);
        destinationAddress = QHostAddress("127.0.0.1");  // 接收端的IP地址
        destinationPort = 12345;  // 接收端的端口
    }

    void sendWavFile(const QString &filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning() << "无法打开文件:" << filePath;
            return;
        }

        QByteArray fileData = file.readAll();
        int totalSize = fileData.size();
        int packetSize = 1024;  // 每个数据包的大小

        // 将文件数据分割成多个包并发送
        int totalPackets = (totalSize + packetSize - 1) / packetSize;  // 计算需要的包数
        for (int i = 0; i < totalPackets; ++i) {
            QByteArray packetData = fileData.mid(i * packetSize, packetSize);
            QByteArray packet;
            QDataStream stream(&packet, QIODevice::WriteOnly);

            // 包含包的索引、总包数和数据
            stream << i << totalPackets << packetData;

            socket->writeDatagram(packet, destinationAddress, destinationPort);
            qDebug() << "发送数据包" << i + 1 << "/" << totalPackets;
        }

        file.close();
    }

private:
    QUdpSocket *socket;
    QHostAddress destinationAddress;
    quint16 destinationPort;
};

