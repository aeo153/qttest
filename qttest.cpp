#include "qttest.h"
#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <iostream>
#include <QLocale>
#include <QRegExp>

QtTest::QtTest()
{

}

QtTest::~QtTest()
{

}

void QtTest::WriteXML()
{
    QString filePath = QCoreApplication::applicationDirPath();
    filePath += "/xmltest.xml";
    QFile file( filePath );
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        return;
    }

    QDomDocument document;
    QString strHeader( "version=\"1.0\" encoding=\"UTF-8\"" );
    document.appendChild( document.createProcessingInstruction("xml", strHeader) );

    QDomElement	root_elem = document.createElement( "XMLROOT" );
    document.appendChild( root_elem );

    QDomElement child_elem = document.createElement("Element1");
    child_elem.setAttribute("attribute11", 11);
    child_elem.setAttribute("attribute12", 12);
    child_elem.setAttribute("attribute13", "1three");
    root_elem.appendChild(child_elem);

    child_elem = document.createElement("Element2");
    child_elem.setAttribute("attribute21", 21);
    child_elem.setAttribute("attribute22", 22);
    child_elem.setAttribute("attribute23", "2three");
    root_elem.appendChild(child_elem);

    QDomElement sub_child_elem = document.createElement("Element21");
    sub_child_elem.setAttribute("attribute211", 211);
    sub_child_elem.setAttribute("attribute212", 212);
    sub_child_elem.setAttribute("attribute213", QStringLiteral("开始的分解"));
    child_elem.appendChild(sub_child_elem);

    QTextStream out( &file );
    out.setLocale(QLocale::system());
    document.save(out, 4);
    file.close();
}

void QtTest::testRegular()
{
    QRegExp reg("ROIPolyData_Tumor*Fuse");
    reg.setPatternSyntax(QRegExp::Wildcard);
    QString test_string("ROIPolyData_Tumor3Fuse");
    bool ret = reg.exactMatch(test_string);
    std::cout<<__func__<<" :"<<(ret ? "valid" : "invalid")<<std::endl;
}
