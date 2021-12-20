#include "ClassA.h"
#include "CodeSegment.h"
#include <memory.h>
#include <iostream>
#include <chrono>
#include <QUuid>
#include <QDebug>
#include <typeinfo>
#include "UtilsDef.h"
#include <sstream>

void CodeSegment::testMem()
{
    char arr[10] = {1, 2, 3,4,5,6,7,8,9,10 };
    for ( auto d : arr )
    {
        std::cout<<__func__<<" "<< (int)d<<std::endl;
    }

    memset(arr, 1, sizeof(char) * 10);
    for ( auto d : arr )
    {
        std::cout<<__func__<<" "<< (int)d<<std::endl;
    }
}

void CodeSegment::testArrayInit()
{
    const unsigned int sz = 100000;
//    unsigned char * arr = new unsigned char[sz]();
//    for ( unsigned int i = 0; i < sz; i++ )
//    {
//        std::cout<<__func__<<":"<<(unsigned int)(arr[i])<<std::endl;
//    }

    START_TIMER;
    int dArr1[sz];
    std::cout<<__func__<<" 10="<<dArr1[10]<<std::endl;
    STOP_TIMER("");

    START_TIMER_NODEF
    int dArr2[sz];
    for ( uint32_t i = 0; i < sz; ++i )
    {
        dArr2[i] = 0;
    }

    std::cout<<__func__<<" 10="<<dArr2[10]<<std::endl;
    STOP_TIMER_NODEF("");

//    for ( int i = 0; i < sz; i++ )
//    {
//        std::cout<<__func__<<" double :"<<dArr[i]<<std::endl;
    //    }
}

void CodeSegment::initCharArray()
{
    const unsigned int sz = 10000;
    char * pch = new char[sz];
    //int pch[100000] = {};
    memset(pch, 128, sizeof(char) * sz);
    for ( uint32_t i = 0; i < sz; i += 100)
    {
        std::cout<<i<<" "<<short(pch[i])<<std::endl;
    }
}

QString CodeSegment::Uuid()
{
    //{1e3f65f9-f3c1-427c-aa41-da32a26d4649}->1ef342aada32
    QString uid = QUuid::createUuid().toString();
    qDebug()<<uid;
    QString retStr = uid.mid(1, 2);
    int idx = 0;
    for ( int i =0; i < 4; ++i )
    {
        idx = uid.indexOf("-", idx+1);
        retStr += uid.mid(idx + 1, i < 3 ? 2 : 4);
    }

    return retStr;
}

void CodeSegment::testTypeid()
{
    SubClassA * sub = new SubClassA;
    ClassA * pSub = sub;
    std::cout<<typeid(sub).name()<<" " <<typeid(pSub).name()<<std::endl;

}


//2014-07-31:从"_[0-9]"截断
//QString fileName("myfileName_sds_321lks");
//QString title = fileName;
//QRegExp regExp("_[0-9]", Qt::CaseInsensitive, QRegExp::Wildcard);
//int idx = fileName.indexOf(regExp);
//qDebug()<<idx;
//if ( idx > 0 )
//{
//    title = fileName.left(idx);
//}

//qDebug()<<title;
//myfileName_sds

//2014-06-24:创建目录
//QString dirPath = "E:/work/socketttss\\socketttsstt\\t1/t2/t3/t4.edf/t5\\";
//QString errmsg;
//if ( !CreatePath(dirPath, errmsg) )
//{
//    qDebug()<<errmsg;
//}
//else
//{
//    qDebug()<<"create successfully";
//}

//2014-02-27:在指定目录下创建子目录
//QString pPath = "e:/temp";
//QDir aDir(pPath);
//if ( !aDir.exists("d1/d2") )
//{
//    aDir.mkpath("d1/d2");//d1前不能带/或\路径分隔符
//}
//qDebug()<<aDir.exists("d1/d2");
//aDir.mkpath("f1");

//2014-02-27:检测.edf位置
//QString taskPath = "//asdff.com/platformfile/test/ora_asdfgh/project/P70281386832828895/D1/N4d811386912125614/sdfsdaf_7624.edf/557787669da7/1//edfres.txt";
//QString myPath;
//QRegExp aRegExp(".edf", Qt::CaseSensitive, QRegExp::Wildcard);
//int idx = taskPath.indexOf(aRegExp);
//if ( idx >= 0 )
//{
//    idx = taskPath.lastIndexOf("/", idx);
//    if ( idx >= 0 )
//    {
//        myPath = taskPath.right(taskPath.length() - idx - 1);
//    }
//}

//qDebug()<<myPath;

//截取:12341_7624.edf
//    QString taskPath = "//dfggdsfd/project/P70281386832828895/D1/N4d811386912125614/12341_7624.edf/";
//    QString myPath = taskPath;
//    QRegExp aRegExp(".edf", Qt::CaseSensitive, QRegExp::Wildcard);
//    int idx1 = taskPath.indexOf(aRegExp);

//    //项目文件夹*.edf,
//    QString projPath;
//    if ( idx1 >= 0 )
//    {
//        int idx2 = taskPath.lastIndexOf("/", idx1);
//        if ( idx2 >= 0 )
//        {
//            myPath = taskPath.right(taskPath.length() - idx2 - 1);
//            idx2 = myPath.indexOf("/");
//            if ( idx2 >= 0 )
//            {
//                projPath = myPath.left(idx2);
//            }
//        }
//    }

//    qDebug()<<projPath;

//2014-02-26:创建文件夹
//QDir aDir("E:\\Temp");
//if ( !aDir.exists("mkdirtest") )
//{
//    aDir.mkdir("mkdirtest");
//}
//2014-02-24:启动程序,路径带空格
//QProcess * aProcess = new QProcess;
//    aProcess->setWorkingDirectory("E:\\work\\socketttss\\socketttsstt\\manitor");
//    aProcess->start("E:\\work\\socketttss\\socketttsstt\\manitor\\manitor.exe");
//aProcess->setWorkingDirectory("D:/Program Files/Adapted Solutions/Partenus 5.2");
//aProcess->start("\"D:/Program Files/Adapted Solutions/Partenus 5.2/Partenus.exe\"");
//QProcess::startDetached("D:/Program Files/Adapted Solutions/Partenus 5.2/Partenus.exe");

//2014-02-21:Partenus窗口消息
//QString msgStr = "20066: The symbol (SINE.OUT) could not be linked. Please check output definition and model parameters. 02091: Error on preparing the simulation. Simulation aborted. 234 error(s). 23 warning(s).";
//QRegExp aRegExp("error(s)", Qt::CaseSensitive, QRegExp::Wildcard);
//int idx2 = msgStr.indexOf(aRegExp);
//if ( idx2 > 0 )
//{
//    int i = 3;
//    int idx1 = idx2 - i;
//    QString spaceStr = msgStr.mid(idx1, 1);
//    while ( spaceStr != " " && idx1 > 0 )
//    {
//        i++;
//        idx1 = idx2 - i;
//        spaceStr = msgStr.mid(idx1, 1);
//    }

//    if ( idx1 >= 0 )
//    {
//        QString errnum = msgStr.mid(idx1 + 1, idx2 - idx1 - 2);
//        qDebug()<<errnum;
//    }
//}

//QRegExp warnRegExp("warning(s)", Qt::CaseSensitive, QRegExp::Wildcard);
//idx2 = msgStr.indexOf(warnRegExp);
//if ( idx2 > 0 )
//{
//    int i = 3;
//    int idx1 = idx2 - i;
//    QString spaceStr = msgStr.mid(idx1, 1);
//    while ( spaceStr != " " && idx1 > 0 )
//    {
//        i++;
//        idx1 = idx2 - i;
//        spaceStr = msgStr.mid(idx1, 1);
//    }

//    if ( idx1 >= 0 )
//    {
//        QString warnnum = msgStr.mid(idx1 + 1, idx2 - idx1 - 2);
//        qDebug()<<warnnum;
//    }
//}

//2014-02-17:测试函数内的静态变量
//CMyObject aObj;
//aObj.fun3();
//aObj.fun3();
//aObj.fun3();

//2014-02-14:Map中的列表操作
//QMap<QString, QStringList> aMap;
//QStringList a1;
//aMap.insert("a1", a1);
//QStringList b1;
//aMap.insert("b1", b1);


//aMap["a1"].append("v2");
//aMap["b1"].append("z2");
//qDebug()<<aMap;

//QMap<QString, QList<int>> mapList;
//mapList["key1"].append(1);
//mapList["key1"].append(2);
//mapList["key2"].append(9);
//mapList["key2"].append(0);
//qDebug()<<mapList;
//QMap(("key1", (1, 2) ) ( "key2" ,  (9, 0) ) )

//2013-12-31:字符串组合index
//QString str("//lkdjger43/project/Pd6a91387508383708/D1/N817f1387508386973/ltsb1_19141.efd/557787669da7/1");
//int idx = str.indexOf(".efd");
//qDebug()<<str.right(str.length() - idx - 4);

//2013-12-20 QHash迭代器
//QHash<int, QString> aHash;
//aHash.insert(1, "string1");
//aHash.insert(2, "string2");
//aHash.insert(3, "string3");
//aHash.insert(4, "string4");

//QHashIterator<int, QString> iter(aHash);
//while ( iter.hasNext() )
//{
//    iter.next();
//    qDebug()<<iter.key()<<iter.value();
//}

//2013-12-20
//QString str = "matrix(12 43 432 32 43 534)";
//int idx = str.indexOf("(");
//qDebug()<<str;
//qDebug()<<str.mid(idx +1, str.length() -idx -2);

//2013-07-03
//QStringList list1;
//list1<<"string1"<<"string2"<<"string0"<<"string3";
//qDebug()<<list1.join("|||");
//list1.clear();
//list1<<"string1";
//qDebug()<<list1.join("|||");

//2013-04-18:测试OpenGL窗口加滚动条,分栏显示
//    MyMainWin mainWin;
//    mainWin.showMaximized();

//2013-03-27:删除字符
//QString str("(afada),(32154.245)");
//QRegExp regExp("[()]");
//str.remove(regExp);
//qDebug()<<str;//"afada,32154.245"

//2013-03-27:分隔符
//QString str("axisName[unit]");
//int idx1 = str.indexOf("[");
//int idx2 = str.indexOf("]", idx1);
//QString name = str.left(idx1);
//QString unit = str.mid(idx1+1, idx2 - idx1 -1);
//qDebug()<<name<<unit;

//2013-03-26:输入一个字符
//char ch = 'a';
//while ( !(ch == 'c' || ch == 'e') )
//{
////        printf("---press key, \'c\' to continue, \'e\' to exit:");
////        scanf("%c", &ch);
////        qDebug()<<endl;
//    std::cout<<"---press key, \'c\' to continue, \'e\' to exit:";
////        std::cin>>ch;
//    ch = getche();
//    qDebug()<<endl;
//}

//2013-03-05:用户临时目录
//QDir dir = QDir::temp();
//qDebug()<<dir.path()<<QDir::tempPath();

//2013-02-22:数值转字符串
//QString str = QString::number(2.023045423, 'e', 4);
//qDebug()<<str;

//2012-11-16:启动浏览器,打开指定链接
//QUrl myLink = QUrl("www.asdff.com");
//QDesktopServices::openUrl(myLink);

//2012-11-06:正则表达式分离字符串
//QRegExp regExp("[,; ]{1}");
//QString cName = "dfjsld,lskfjdk;3234.545 4239.5443";
//QStringList nameList = cName.split(regExp);
//foreach (QString aname, nameList )
//{
//    qDebug()<<aname;
//}

//2012-10-30:测试字符串是否包含指定字符串
//    QRegExp regExp("*[]}{[\\]*", Qt::CaseSensitive, QRegExp::Wildcard);
//    qDebug()<<regExp.pattern();
//    qDebug()<<"da[tere"<<QString("da[tere").contains(regExp);
//    qDebug()<<"aa]aab"<<QString("aa]aab").contains(regExp);
//    qDebug()<<"dsdk}lj"<<QString("dsdk}lj").contains(regExp);
//    qDebug()<<"56\\32"<<QString("5\\63.2").contains(regExp);
//    qDebug()<<"56{32"<<QString("5{63.2").contains(regExp);

//    QRegExp regExp("^[\babs\b\bcos\b\bsin\b\bexp\b\bint\b\bln\b\blog10\b\bnormalize\b\bsqrt\b]",
//                       Qt::CaseInsensitive, QRegExp::RegExp);


//    QString cName = "sin([45] + [abs(int(232.5)+2)])";
//    qDebug()<<cName;
//    if ( !cName.contains(regExp) )
//    {
//        cName = QString("(%1)").arg(cName);
//    }
//    qDebug()<<cName;

//2012-10-10:测试文件读取量
//QFile file("E:\\Temp\\curves\\other\\is1.dat");
//file.open(QIODevice::ReadOnly);
//QTextStream textStr(&file);
//QString str;
//qint64 totalSize = file.bytesAvailable();
//QTime timer;
//timer.start();
//while( !textStr.atEnd() )
//{
//    str = textStr.readLine();
//    qDebug()<<totalSize<<file.pos()<<str;
//}
//qDebug()<<timer.elapsed();

//QFile file("E:\\Temp\\curves\\other\\is1.dat");
//file.open(QIODevice::ReadOnly);
//QTextStream textStr(&file);
//QString str;
//qint64 totalSize = file.bytesAvailable();
//QTime timer;
//qint64 counter = 0, counter1 = 0;
//timer.start();
//while( !textStr.atEnd() )
//{
//    str = textStr.readLine();
//    QByteArray byte = str.toAscii();
//    counter += byte.size();
//    counter1 += str.size();
//    qDebug()<<totalSize<<counter<<counter1<<str;
//}
//qDebug()<<timer.elapsed();

//2012-10-10:数值精度
//QString str = QString::number(2.02304, 'g', 4);
//qDebug()<<str;

//2012-09-13:测试字符序列化顺序
//QString str = QString("Second(%2) VS First(%1)").arg("1", "2");
//qDebug()<<str;//Second(2) VS First(1)

//2012-09-13:测试取double的整数和小数部分
//double aa = 12.34209;
//double bb = -12.34209;
//double zsbf, xsbf;
//xsbf = modf(aa, &zsbf);
//qDebug()<<aa<<zsbf<<xsbf;//12 0.36209
//xsbf = modf(bb, &zsbf);
//qDebug()<<bb<<zsbf<<xsbf;//-12 -0.36209

//2012-09-12:颜色字符串分隔
//QString colorStr("120,2,45,200");
//int idx1 = colorStr.indexOf(",");
//if ( idx1 <= 0 )
//{
//    return 1;
//}

//int idx2 = colorStr.indexOf(",", idx1+1);
//if ( idx2 <= idx1 )
//{
//    return 1;
//}

//int idx3 = colorStr.indexOf(",", idx2+1);
//if ( idx3 <= idx2 )
//{
//    return 1;
//}

//QString str = colorStr.left(idx1);
//qDebug()<<str;
//str = colorStr.mid(idx1+1, idx2 - idx1 -1);
//qDebug()<<str;
//str = colorStr.mid(idx2+1, idx3 - idx2 -1);
//qDebug()<<str;
//str = colorStr.right(colorStr.length() - idx3 - 1);
//qDebug()<<str;

//2012-07-27:测试自定义类
//QScriptEngine engine;
//QStringList strList;
//strList<<"str1"<<"str2"<<"str3"<<"str4";
//EMScriptList scpList;
//foreach( QString str, strList ) { scpList.append(str); }
//QScriptValue scVal = engine.newQObject(&scpList);
//engine.globalObject().setProperty("strList", scVal);
//engine.evaluate("a = strList.value(2); print(a);");

//2012-06-07:测试ceil函数
//qDebug()<<ceil(-1.0);
//qDebug()<<ceil(1.1);
//qDebug()<<ceil(-2.1);
//-1
//2
//-2

//2012-06-06:单个QStringList拼接
//QStringList testList;
//testList<<"123";
//qDebug()<<testList;
//QString merged = testList.join(",");
//qDebug()<<merged;
//merged = testList.join("\',\'");
//merged.prepend("\'");
//merged.append("\'");
//qDebug()<<merged;

//2012-02-24:密码
//QString pwd = "develop";
//QByteArray encode;
//int len = EasiCrypt::encodeAsciiToHex(pwd.toAscii(), encode);
//qDebug()<<len<<encode;

//2012-02-24:日期时间格式
//QString str = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//qDebug()<<QDateTime::currentDateTime().toString(Qt::SystemLocaleShortDate);
//QDateTime dt = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
//QVariant var(dt.toString(Qt::ISODate));
//QDateTime dt1 = var.toDateTime();
//qDebug()<<dt1.toString(Qt::ISODate);

//2012-02-24:脚本测试
//QScriptEngine engine;
//CBase * pObj = new CBase();
//pObj->setObjectName("BaseObject");

//CSub * pSubObj = new CSub(pObj);
//pSubObj->setObjectName("SubObject");

////    CSub * pSubObj = new CSub(pObj);
////    pSubObj->setObjectName("SubObject");

//QScriptValue spVal = engine.newQObject(pObj);
//engine.globalObject().setProperty("myObject", spVal);
//qDebug()<<engine.evaluate("myObject.bVisiable").toBool();
//engine.evaluate("myObject.bVisiable = false");
//qDebug()<<engine.evaluate("myObject.bVisiable").toBool();
//qDebug()<<engine.evaluate("myObject.Add(3,5)").toInt32();

//QScriptValue handler = engine.evaluate("(function(a) { print(a); })");
//qScriptConnect(pObj, SIGNAL(MySignal(int)), QScriptValue(), handler);
//engine.evaluate("myObject.EmitSignal(100)");

//qScriptRegisterMetaType(&engine, toScriptValue, fromScriptValue);
//CMyObject myNonQObj;
//myNonQObj.setNumber(10);
//QScriptValue ctor = engine.toScriptValue(myNonQObj);
//engine.globalObject().setProperty("myNonQObj", ctor);
//engine.evaluate("myNonQObj.fun1()");

//engine.globalObject().setProperty("Add", engine.newFunction(AddScript));
//qDebug()<<"cpp fun in script:"<<engine.evaluate("Add(45, 50)").toInt32();

//qDebug()<<engine.evaluate("myObject.SubObject.width").toNumber();

//2012-01-11:取文件名和目录路径
//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
//QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
//QString str = "E:\\work\\3dms\\3dmscore\\jfdie.esc";
//int idx = str.lastIndexOf("\\");
//int idx1 = str.lastIndexOf(".");
//qDebug()<<str.mid(idx+1, str.length() - idx-1);//fileName.ext
//qDebug()<<str.mid(idx+1, idx1 - idx-1);//fileName
//qDebug()<<str.right(str.length() - idx1 - 1);//ext
//qDebug()<<str.left(idx+1);//filePath
//"jfdie.esc"
//"jfdie"
//"esc"
//"E:\work\3dms\3dmscore\"

//QString str("[asdf]*[ghjk]+[lopiiuo]");
//int idx = str.indexOf("[");
//int idx1;
//while (idx != -1 )
//{
//    idx1 = str.indexOf("]", idx);
//    qDebug()<<str.mid(idx, idx1-idx+1);
//    idx = str.indexOf("[", idx1);
//}
//qDebug()<<str.mid(10, str.length()-11);

//QwtLog10ScaleEngine log10Engine;
//double sMin = 10.0, sMax = 1000.0;
//int j = (int)log10(sMax);
//int i = (int)log10(sMin);

//QwtScaleDiv scaleDiv = log10Engine.divideScale(sMin, sMax, 3, 4);
//QList<double> minortic = scaleDiv.ticks(QwtScaleDiv::MinorTick);
//QList<double> majortic = scaleDiv.ticks(QwtScaleDiv::MajorTick);
//qDebug()<<"low margin"<<log10Engine.lowerMargin();
//qDebug()<<"hight margin"<<log10Engine.upperMargin();
//QList<double> tics;
//tics<<minortic<<majortic;
//qSort(tics);
//qDebug()<<"minor"<<minortic;
//qDebug()<<"major:"<<majortic;
//qDebug()<<"whole:"<<tics;

//2011-11:取文件名"file"
//QString str("dfd/lsdfj/lfksjf/file.txt");
//int idx = str.lastIndexOf("/");
//int idx1 = str.lastIndexOf(".");
//qDebug()<<str.mid(idx+1, idx1 - idx-1);

//2011-09-28:结果在fun2中调用子类CSub的函数fun1
//CBase * pBase = new CSub;
//pBase->fun2();
//delete pBase;

//QStringList list1;
//list1<<"string1"<<"string2"<<"string0"<<"string3";
//QStringList list2;
//list2<<"string2"<<"string1"<<"string3"<<"string0";
//list2.sort();
//list1.sort();
//qDebug()<<"list1:"<<list1;
//qDebug()<<"list2:"<<list2;
//qDebug()<<(list1==list2);//true

//QByteArray btArr;
//QDataStream out(&btArr, QIODevice::WriteOnly);
//out<<12;
//out<<"message";
////out<<"E:\\Project\\qttest-build-desktop\\debug\\qttest.exe exited with code -1073741510";
//qDebug()<<btArr.size();

//QDir dir;
//qDebug()<<dir.rmpath("E://ftp//sub1//sub2//sub3");


void CodeSegment::SprintfTest()
{
    //结论：sprintf效率更高
    int a = 1, b =2, c = 3;
    std::string dirpath("abcdefghijklmnopqestuvwxyz");
    int num = 100000;

    START_TIMER;
    for ( int i = 0; i < num; ++i )
    {
        char chrarr[30];
        sprintf(chrarr, "%s_%d_%d_%d", dirpath.data(), a, b, c);
        if ( i %10000 == 0 )
        {
            std::cout<<chrarr<<std::endl;
        }
    }
    STOP_TIMER("sprintf");//SprintfTest 607 sprintf elasped:11

    START_TIMER_NODEF;
    for ( int i = 0; i < num; ++i )
    {
        std::string str(dirpath);
        str = dirpath + ("_"+std::to_string(a)+"_"+std::to_string(b)+"_"+std::to_string(c));
        if ( i %10000 == 0 )
        {
            std::cout<<str<<std::endl;
        }
    }
    STOP_TIMER_NODEF("string+");//SprintfTest 619 string+ elasped:42

    START_TIMER_NODEF;
    for ( int i = 0; i < num; ++i )
    {
        std::stringstream sstr;
        sstr<<dirpath<<"_"<<a<<"_"<<b<<"_"<<c;
        std::string str = sstr.str();
        if ( i %10000 == 0 )
        {
            std::cout<<str<<std::endl;
        }
    }
    STOP_TIMER_NODEF("stringstream+");//SprintfTest 633 stringstream+ elasped:73
}

void CodeSegment::loopvar()
{
    int num = 1e6;
    START_TIMER;
    double sqrt2  = sqrt(2.0) / 2;
    double sin05 = sin(0.5);
    double val;
    for ( int i = 0; i < num; ++i )
    {
        val = sqrt2 * i * sin05;
    }

    STOP_TIMER(val);

    START_TIMER_NODEF;
    for ( int i = 0; i < num; ++i )
    {
        val = sqrt(1 + i * 2.0) / 2 * i * sin( i * 0.5);
    }

    STOP_TIMER_NODEF(val);
}

constexpr unsigned int jch(unsigned int n)
{
    //COUT_FUNC_INFO(n);
    // #pragma message( "Compiling"__FILE__ )
    return n == 1 ? 1 : n * jch(n-1);
}

enum E_code
{
    e_type1,
    e_type2,
    e_type3
};

void CodeSegment::testConstexpr()
{
    //COUT_FUNC_INFO( jch(10) )
    double type = e_type1;
    std::cout<<typeid(type).name()<<" "<<type<<std::endl;
}
