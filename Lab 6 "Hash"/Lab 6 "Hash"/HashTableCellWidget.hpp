#ifndef HASHTABLECELLWIDGET_H
#define HASHTABLECELLWIDGET_H

#include <QWidget>

#include "HashTable.hpp"

namespace Ui {
class HashTableCellWidget;
}

class HashTableCellWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HashTableCellWidget(QWidget *parent = nullptr);
    ~HashTableCellWidget();

    int key() const;
    QString value() const;

public slots:
    void setKey(int key);
    void setValue(const QString &value);

signals:
    void valueChanged(HashTableCellWidget *item);

private:
    Ui::HashTableCellWidget *ui;
};

#endif //HASHTABLECELLWIDGET_H
