#include "lab13_14.h"
#include "locatar.h"
#include "service.h"
#include "administrator.h"
#include "teste.h"
#include "model_locatarGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    test_all();
    {
        QApplication a(argc, argv);
        RepoLocatarFile repo{ "locatar.txt" };
        ValidatorLocatar val;
        Bloc srv{ repo, val };
        Administrator adm;
       
        MGUIbloc gui{ adm, srv };
        gui.show();

        MGUIcos cos{ adm, srv };
        cos.show();

        MGUIcosReadOnly img{ adm, srv };
        img.show();

        return a.exec();
    }
    return 0;
}
