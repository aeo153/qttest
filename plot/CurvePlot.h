#ifndef CURVEPLOT_H
#define CURVEPLOT_H

#include <QMainWindow>
#include <qwt/src/qwt_plot.h>

class QwtPlotCurve;

class CurvePlotFrm : public QwtPlot
{
    Q_OBJECT

public:
    explicit CurvePlotFrm(QWidget *parent = 0);
    virtual ~CurvePlotFrm();

public slots:

public:
    void AddCurveData(const QString & curveName,
                      const std::vector<double> & xCoords,
                      const std::vector<double> & yCoords);

private:
    void InitCanvas();

private:
    //图例
    class QwtLegend * m_legend = nullptr;

    //网格
    class QwtPlotGrid * m_grid = nullptr;

    //平移
    class QwtPlotPanner * m_panner = nullptr;

    //图形缩放
    class QwtPlotMagnifier * m_zoomer = nullptr;

    std::list<QwtPlotCurve *> m_curveList;
};

#endif
