#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plotarea.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_seg_clicked();

    void on_poly_clicked();

    void cut(int x1, int y1, int x2, int y2);

private:
    Ui::MainWindow *ui;
    PlotArea *area;
    void ProcessSegments();
    void ProcessPoly();
    void ClipAfterLine(std::vector<QPointF>& polygon, int cord, int bit);
    int getCode(qreal x, qreal y) const;
    int getCode(const QPointF& p) const;
};
#endif // MAINWINDOW_H
