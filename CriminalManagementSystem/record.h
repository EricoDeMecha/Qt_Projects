#ifndef RECORD_H
#define RECORD_H

#include <QDialog>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLineEdit>

namespace Ui {
class Record;
}

class Record : public QDialog
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = nullptr);
    ~Record();

private:
    Ui::Record *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem* item;
    QImage image;
};

#endif // RECORD_H
