#include "recyclingbinfinder.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include <QApplication>

int main(int argc, char *argv[])
{
   try
   {
   QApplication a(argc, argv);
   RecyclingBinFinder w;
   w.show();
   return a.exec();
   }
   catch(int num)
   {
        return 0;
   }
}
