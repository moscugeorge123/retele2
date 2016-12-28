#include <mysql/mysql.h>

class mysql_connection
{
protected:
	bool isConnected;

	char* unix_socket;
	char[250] host;
	char[250] user;
	char[250] pass;
	char[250] dbname;
	unsigned int port;
	unsigned int flag;

	MYSQL *conn;

public:
	bool isConnected()
	{
		return isConnected;
	}

	mysql_connection(const char* host, const char* user, const char* pass, const char* dbname)
	{
		strcpy(this->host, host);
		strcpy(this->user, user);
		strcpy(this->pass, pass);
		strcpy(this->dbname, dbname);
		this->port = 3306;
		this->unix_socket = NULL;
		this->flag = 0;

		this->conn = mysql_init(NULL);

		MYSQL *connected;

		connected = mysql_real_connect( 
							this->conn,
							&this->host,
							&this->user,
							&this->pass,
							&this->dbname,
							&this->port,
							&this->unix_socket,
							&this->flag
					);

		if(connected == NULL){
			this->isConnected = false;
		}
		else {
			this->isConnected = true;
		}

	}
	~mysql_connection();
	
};