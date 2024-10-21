#include "datachart.h"
// 静态成员变量的定义
QVector<double> dataChart::xData;
QVector<double> dataChart::yData;
// 在初始化时定义全局的追踪器和文本项
QCPItemTracer *tracer = nullptr;
QCPItemText *tracerText = nullptr;

dataChart::dataChart(Ui::MainWindow *myui)
{
    myUI=myui;

    myUI->chartView->addGraph();
    myUI->chartView->graph(0)->setPen(QPen(Qt::blue)); // 设置曲线颜色

    // 设置时间和浓度数据轴的标签
    myUI->chartView->xAxis->setLabel("数据时间");
    myUI->chartView->yAxis->setLabel("浓度 (mg/m3)");


    // 获取当前时间戳作为起始时间
    double currentTime = QDateTime::currentDateTime().toSecsSinceEpoch();

    // 设置x轴和y轴的初始范围
    myUI->chartView->xAxis->setRange(currentTime - 60, currentTime); // 显示最近60秒的数据
    myUI->chartView->yAxis->setRange(0, 100); // 设置浓度范围

    // 设置时间刻度格式
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("yyyy HH:mm:ss"); // 设置为"yyyy-HH:mm:ss"格式
    myUI->chartView->xAxis->setTicker(dateTimeTicker);

    // 初始化追踪器和文本
    tracer = new QCPItemTracer(myUI->chartView);
    tracer->setGraph(myUI->chartView->graph(0));
    tracer->setStyle(QCPItemTracer::tsCircle);
    tracer->setPen(QPen(Qt::red));
    tracer->setBrush(Qt::red);
    tracer->setSize(7);

    tracerText = new QCPItemText(myUI->chartView);
    tracerText->position->setType(QCPItemPosition::ptPlotCoords);
    tracerText->setPositionAlignment(Qt::AlignLeft | Qt::AlignBottom);
    tracerText->setText("数值：");
    tracerText->setColor(Qt::black);
    tracerText->setBrush(QBrush(Qt::white));
    tracerText->setPadding(QMargins(5, 5, 5, 5));

    // 绑定鼠标移动事件
    connect(myUI->chartView, &QCustomPlot::mouseMove, [=](QMouseEvent *event) {showDataAtMouse(event);});
//=====================================================================================
     myUI->originView->addGraph();
     myUI->originView->graph(0)->setPen(QPen(Qt::blue));
     myUI->originView->xAxis->setLabel("数据个数");
     myUI->originView->yAxis->setLabel("数据AD");
}

void dataChart::receiveConcentration2(const PUSHORT myoriginBuff,const float ConCTr)
{
    // 获取当前时间的时间戳（单位为秒）
    double currentTime = QDateTime::currentDateTime().toSecsSinceEpoch();

    // 模拟浓度数据（这里用随机数替代真实数据）
    double concentration = qrand() % 100;

    // 更新时间和数据
    xData.append(currentTime);
    yData.append(concentration);

    // 更新图表数据
    myUI->chartView->graph(0)->setData(xData, yData);

    // 调整x轴范围以实现滚动效果
    double timeRange = 60; // 显示最近60秒的数据
    myUI->chartView->xAxis->setRange(currentTime - timeRange, currentTime);
    // 使用 QCPAxisTickerDateTime 格式化时间标签
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("yyyy HH:mm:ss");
    myUI->chartView->xAxis->setTicker(dateTimeTicker);

    // 重新绘制图表
    myUI->chartView->replot();

 //====================================================

     myUI->originView->graph(0)->data()->clear();

    // 构建 x 轴和 y 轴的数据
    QVector<double> xData(10000), yData(10000);
    for (int i = 0; i < 10000; ++i) {
        xData[i] = i;                 // x轴为数据索引
        yData[i] = myoriginBuff[i];   // y轴为 myoriginBuff 的值
    }

    // 设置数据到图表
    myUI->originView->graph(0)->setData(xData, yData);

    // 设置 x 轴的范围（从 0 到 dataSize - 1）
    myUI->originView->xAxis->setRange(0, 9999);
    myUI->originView->xAxis->setLabel("数据索引");

    // 设置 y 轴的范围（根据 myoriginBuff 的最小和最大值）
    double minY = *std::min_element(yData.begin(), yData.end());
    double maxY = *std::max_element(yData.begin(), yData.end());
    myUI->originView->yAxis->setRange(minY, maxY);
    myUI->originView->yAxis->setLabel("myoriginBuff");

    // 重新绘制图表
    myUI->originView->replot();


};
void dataChart::showDataAtMouse(QMouseEvent *event)
{
    // 获取鼠标在绘图区域的坐标
    double x = myUI->chartView->xAxis->pixelToCoord(event->pos().x());
    double y = myUI->chartView->yAxis->pixelToCoord(event->pos().y());

    // 找到最近的点
    QCPGraph *graph = myUI->chartView->graph(0);
    if (!graph || graph->dataCount() == 0) return;

    double minDistance = std::numeric_limits<double>::max();
    double closestKey = 0, closestValue = 0;

    // 遍历数据点，找到最近的
    for (int i = 0; i < graph->dataCount(); ++i) {
        double key = graph->data()->at(i)->key;
        double value = graph->data()->at(i)->value;
        double distance = qSqrt(qPow(key - x, 2) + qPow(value - y, 2));

        if (distance < minDistance) {
            minDistance = distance;
            closestKey = key;
            closestValue = value;
        }
    }

    // 如果距离小于一个阈值，则显示追踪器和数值
    if (minDistance < 5) {
        tracer->setGraphKey(closestKey);
        tracer->updatePosition();

        // 设置文本项的位置
        tracerText->position->setCoords(closestKey, closestValue);

        // 设置文本内容
        QString timeStr = QDateTime::fromSecsSinceEpoch(static_cast<qint64>(closestKey)).toString("yyyy HH:mm:ss");
        QString valueStr = QString::number(closestValue, 'f', 2);
        tracerText->setText(QString("%1\n data: %2").arg(timeStr).arg(valueStr));
        tracerText->setVisible(true);

        // 调整小窗口位置，避免超出边界
        double xMargin = myUI->chartView->xAxis->range().size() * 0.07;  // x轴边界的5%作为边距
        double yMargin = myUI->chartView->yAxis->range().size() * 0.05;  // y轴边界的5%作为边距

        // 判断文本项是否超出右边界
        if (closestKey + xMargin > myUI->chartView->xAxis->range().upper) {
            tracerText->position->setCoords(closestKey - xMargin, closestValue);
            tracerText->setPositionAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 改为右对齐
        } else {
            tracerText->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);   // 左对齐
        }

        // 判断文本项是否超出上边界
        if (closestValue + yMargin > myUI->chartView->yAxis->range().upper) {
            tracerText->position->setCoords(closestKey, closestValue - yMargin);
            tracerText->setPositionAlignment(Qt::AlignHCenter | Qt::AlignTop);   // 改为上对齐
        } else if (closestValue - yMargin < myUI->chartView->yAxis->range().lower) {
            tracerText->position->setCoords(closestKey, closestValue + yMargin);
            tracerText->setPositionAlignment(Qt::AlignHCenter | Qt::AlignBottom);  // 改为下对齐
        }
    } else {
        tracerText->setVisible(false);
    }

    // 更新绘图
    myUI->chartView->replot();
}

