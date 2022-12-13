#ifndef RECYCLINGBINFINDER_H
#define RECYCLINGBINFINDER_H

#include <QWidget>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class RecyclingBinFinder; }
QT_END_NAMESPACE

class RecyclingBinFinder : public QWidget
{
    Q_OBJECT

public:
    RecyclingBinFinder(QWidget *parent = nullptr);
    ~RecyclingBinFinder();
    QStringList binList;


private slots:

    void on_manButton_clicked();

    void on_qnsButton_clicked();

    void on_bkButton_clicked();

    void on_bxButton_clicked();

    void on_siButton_clicked();

    void on_homeButton_clicked();

private:
    Ui::RecyclingBinFinder *ui;
    void loadFile();
};
#endif // RECYCLINGBINFINDER_H
