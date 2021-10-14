#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Testing code: prints the description,vendor_id and product_id of all ports
     qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
     foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
       qDebug() << "Description: " << serialPortInfo.description() << "\n";
       qDebug() << "Has vendor_id: " << serialPortInfo.hasVendorIdentifier() << "\n";
       qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
       qDebug() << "Has product Id: " << serialPortInfo.hasProductIdentifier() << "\n";
       qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
     }

    return a.exec();
}
