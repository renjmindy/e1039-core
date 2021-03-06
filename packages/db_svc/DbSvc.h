#ifndef __DB_SVC_H__
#define __DB_SVC_H__
#include <vector>
#include <string>
#include <sstream>
class TSQLServer;
class TSQLStatement;

class DbSvc {
 public:
  typedef enum { DB1, DB2, DB3, DB01, UIUC } SvrId_t;
  typedef enum { Guest, Prod } UsrId_t;

  DbSvc(const SvrId_t svr_id=DB1, const UsrId_t usr_id=Guest, const std::string my_cnf="");
  ~DbSvc();

  void UseSchema(const char*       name, const bool do_create=false, const bool do_drop=false);
  void UseSchema(const std::string name, const bool do_create=false, const bool do_drop=false) { UseSchema(name.c_str(), do_create, do_drop); }

  void DropTable  (const char* name);
  void DropTable  (const std::string name) { DropTable(name.c_str()); }
  bool HasTable(const char* name, const bool exit_on_false=false);
  bool HasTable(const std::string name, const bool exit_on_false=false) { return HasTable(name.c_str(), exit_on_false); }
  void CreateTable(const std::string name, const std::vector<std::string> list_var, const std::vector<std::string> list_type);
  void CreateTable(const std::string name, const int n_var, const char** list_var, const char** list_type);
  
  TSQLServer* Con() { return m_con; }
  TSQLStatement* Process(const char*       query);
  TSQLStatement* Process(const std::string query) { return Process(query.c_str()); }
  
 private:
  SvrId_t     m_svr_id;
  UsrId_t     m_usr_id;
  std::string m_svr;
  std::string m_my_cnf;
  TSQLServer* m_con;

  void SelectServer();
  void ConnectServer();
};
#endif // __DB_SVC_H__
