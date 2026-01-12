#include "qapplication.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qpainter.h"
#include "qsplitter.h"
#include "qwidget.h"
#include "qframe.h"

class whogiWindow : public QWidget
{    
 public:
  whogiWindow( QWidget *parent=0);

 protected:
  void paintEvent (QPaintEvent *);

};

whogiWindow::whogiWindow(QWidget *parent )
  : QWidget(parent)
{
  setFixedSize(100,100);
}

void whogiWindow::paintEvent (QPaintEvent *)
{
  // Draw graphics on this object
  QPainter paint (this);
    
  paint.drawLine(10,10,190,140);
}

// void whogiWindow::paintEvent(QPaintEvent *)
// {
//   // Draw graphics on this object
//   QPainter paint (this);

//   paint.drawLine(10,10,190,140);
// }

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);

  QSplitter *splitter = new QSplitter(Qt::Horizontal);
  splitter->setCaption(QObject::tr("Splitter"));
  splitter->setGeometry(150,150,200,200);
  app.setMainWidget(splitter);
  splitter->show();

  QLabel *label = new QLabel("Hello from Qt!", splitter);
  label->show();

  QPushButton *button = new QPushButton("Quit", splitter);
  QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
  button->show();

  whogiWindow *window = new whogiWindow(splitter);
//   window->setGeometry(50,50,200,150);
  window->show();
  
  return app.exec();

}

// void SimpleExampleWidget::paintEvent()
//    {
//        QPainter paint( this );
//        paint.setPen( Qt::blue );
//        paint.drawText( rect(), AlignCenter, "The Text" );
//    }
