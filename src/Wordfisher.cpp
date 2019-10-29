#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "../include/Wordfisher.h"
#include "../include/Targets.h"
#include "../include/SearchFile.h"
#include "../include/Viewer.h"
#include <fstream>
#include "../include/ViewerDialog.h"
#include "../include/SuccesfullyReplaced.h"
#include "../include/History.h"
#include <logmanager.h>
#include <projectmanager.h>

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<Wordfisher> reg(_T("Wordfisher"));
}

// constructor
Wordfisher::Wordfisher()
{

    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("Wordfisher.zip")))
    {
        NotifyMissingFile(_T("Wordfisher.zip"));
    }
}

// destructor
Wordfisher::~Wordfisher()
{
}

void Wordfisher::OnAttach()
{

    H = new History();
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void Wordfisher::OnRelease(bool appShutDown)
{
    delete H;
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

int Wordfisher::Execute()
{
    ProjectManager* P = Manager::Get()->GetProjectManager();

    Targets* T = new Targets();

   ViewerDialog dlg(Manager::Get()->GetAppWindow(), H);
    dlg.ShowModal();


   string fileName;
   fileName = dlg.ReturnFileName();
   //string searchName = dlg.ReturnSearchName();
   T->setSearch(dlg.ReturnSearchName());
   //string replaceName = dlg.ReturnReplaceName();
   T->setReplace(dlg.ReturnReplaceName());



 SearchFile s(fileName, T->getSearch(), T->getReplace());


   if(s.SearchReplace() == true)
   {
    H->add(T->getSearch(), T->getReplace());
    H->addFile(fileName);

    Manager::Get()->GetLogManager()->Log(_("Successfully Replaced"));
    P->AddFileToProject(dlg.ReturnFileNameWX(), P->GetActiveProject(), -1);
   }
   else
      Manager::Get()->GetLogManager()->Log(_("Failed"));

      delete T;

if(!IsAttached())
        return -1;
   Manager::Get()->GetLogManager()->Log(_(""));
   return 0;

}
