#include <QApplication>
#include "CirconscriptionGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);
  CirconscriptionGUI Fenetreprincipal;
  Fenetreprincipal.show();
  

  // create and show your widgets here

  return app.exec ();
}
