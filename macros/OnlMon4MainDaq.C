/// OnlMon4MainDaq.C:  Macro to launch an online-monitor client for MainDaq.
R__LOAD_LIBRARY(libinterface_main)
R__LOAD_LIBRARY(libonlmonserver)

int OnlMon4MainDaq()
{
  OnlMonClient* omc = new OnlMonMainDaq();
  omc->StartMonitor();
  return 0;
}
