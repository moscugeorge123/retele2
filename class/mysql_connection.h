#include <mysql/mysql.h>

class mysql_connection
{
protected:
	bool Connected;

	char* unix_socket;
	char host[250];
	char user[250];
	char pass[250];
	char dbname[250];
	unsigned int port;
	unsigned int flag;

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

public:
	mysql_connection(const char* host, const char* user, const char* pass, const char* dbname)
	{
		strcpy(this->host, host);
		strcpy(this->user, user);
		strcpy(this->pass, pass);
		strcpy(this->dbname, dbname);
		this->port = 3306;
		this->unix_socket = NULL;
		this->flag = 0;
		this->connect();
	}

	MYSQL_RES *querry(const char* query)
	{
		mysql_query(this->conn, query);
		if(!(this->res = mysql_store_result(this->conn)))
		{
			this->Error();
			return NULL;
		}
		else return this->res;
	}

	void print()
	{
		while(this->row = mysql_fetch_row(this->res))
		{
			printf("%s\t %s\t %s\t %s\n", this->row[0], this->row[1], this->row[2], this->row[3]);
		}
		mysql_free_result(this->res);
	}

	bool connect()
	{
		this->conn = mysql_init(NULL);

		MYSQL *connected;

		connected = mysql_real_connect( 
							this->conn,
							this->host,
							this->user,
							this->pass,
							this->dbname,
							this->port,
							this->unix_socket,
							this->flag
					);

		if (connected){
			this->Connected = true;
			return true;
		}
		else {
			this->Connected = false;
			this->Error();
			return false;
		}
	}

	mysql_connection()
	{
		this->unix_socket = NULL;
		this->flag = 0;
	}


	bool isConnected()
	{
		return Connected;
	}

	void setUser(const char* user)
	{
		strcpy(this->user, user);
	}

	void setPass(const char* pass)
	{
			strcpy(this->pass, pass);
	}

	void setDBName(const char* dbname)
	{
			strcpy(this->dbname, dbname);
	}

	void setHost(const char* host)
	{
			strcpy(this->host, host);
	}

	void setPort(int port)
	{
		this->port = port;
	}

	void Error()
	{
		if(mysql_errno(this->conn)){
			fprintf(stderr, "MYSQL[%d] %s\n",  mysql_errno(this->conn), mysql_error(this->conn));
			exit(2);
		}
	}

	void closeSQL()
	{
		mysql_close(this->conn);
	}

	~mysql_connection();
};