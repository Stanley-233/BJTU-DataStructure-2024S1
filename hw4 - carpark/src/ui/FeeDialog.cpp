//
// Created by stanl on 24-10-19.
//

#include "FeeDialog.h"

#include <QtCharts/QPieSeries>
#include <QChartView>

FeeDialog::FeeDialog(const QVector<float> &fees) {
    auto *series = new QPieSeries();
    float totalFee = 0;
    for (float fee : fees) {
        totalFee += fee;
    }
    for (float fee : fees) {
        if (totalFee > 0) {
            auto slice = new QPieSlice();
            float percentage = fee / totalFee;
            slice->setLabel(QString::number(fee)
                .append("元"));
            slice->setLabelVisible(true);
            slice->setValue(percentage);
            series->append(slice);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);

    chart->setTitle("车辆收费统计");
    QFont titleFont = chart->titleFont();
    titleFont.setPointSize(14);
    chart->setTitleFont(titleFont);

    auto *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    auto *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);
    this->setMinimumSize(800,600);
}
