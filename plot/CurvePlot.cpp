#include "CurvePlot.h"
#include <qwt/src/qwt_plot_grid.h>
#include <qwt/src/qwt_point_data.h>
#include <qwt/src/qwt_plot_curve.h>
#include <qwt/src/qwt_legend.h>
#include <qwt/src/qwt_plot_magnifier.h>
#include <qwt/src/qwt_plot_panner.h>

CurvePlotFrm::CurvePlotFrm(QWidget *parent)
    :QwtPlot(parent)
{
    InitCanvas();
}

CurvePlotFrm::~CurvePlotFrm()
{
    delete m_legend;
    delete m_grid;
    delete m_panner;
    delete m_zoomer;

    for ( auto aCurve : m_curveList )
    {
        delete aCurve;
    }

    m_curveList.clear();
}

void CurvePlotFrm::InitCanvas()
{
    setPalette(QPalette(Qt::white));

    //网格
    m_grid = new QwtPlotGrid;
    m_grid->enableXMin(true);
    m_grid->enableYMin(true);
    m_grid->setMajorPen(QPen(QColor(40, 40, 40), 0, Qt::DotLine));
    m_grid->setMinorPen(QPen(Qt::gray, 0 , Qt::DotLine));
    m_grid->attach(this);

    //设置坐标轴的名称
    setAxisTitle(QwtPlot::xBottom, QStringLiteral("百分剂量"));
    setAxisTitle(QwtPlot::yLeft, QStringLiteral("百分体积"));

    //设置坐标轴的范围
    setAxisScale(QwtPlot::xBottom, 0, 300);
    setAxisScale(QwtPlot::yLeft, 0, 100);

    //设置右边标注
    m_legend = new QwtLegend;
    insertLegend(m_legend, QwtPlot::RightLegend);

    //使用滚轮放大/缩小
    m_zoomer = new QwtPlotMagnifier(canvas());

    //使用鼠标左键平移
    m_panner = new QwtPlotPanner(canvas());
}

void CurvePlotFrm::AddCurveData(const QString & curveName,
                                const std::vector<double> &xCoords,
                                const std::vector<double> &yCoords)
{
    QVector<double> xs = QVector<double>::fromStdVector(xCoords);
    QVector<double> ys = QVector<double>::fromStdVector(yCoords);

    //构造曲线数据
    QwtPointArrayData * data = new QwtPointArrayData(xs, ys);
    QwtPlotCurve * curve = new QwtPlotCurve(curveName);
    curve->setData(data);

    //直线形式
    curve->setStyle(QwtPlotCurve::Lines);

    //使曲线更光滑
    curve->setCurveAttribute(QwtPlotCurve::Fitted, true);

    //设置画笔
    curve->setPen(QPen(Qt::blue));

    //把曲线附加到plot上
    curve->attach(this);

    m_curveList.push_back(curve);
}
