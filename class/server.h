class Server
{
private:
	int port;
	int serverSocket;
	struct sockaddr_in server;
	struct sockaddr_in from;

	bool setServer()
	{
		bzero (&server, sizeof (server));
		bzero (&from, sizeof (from));
		 
		this->server.sin_family = AF_INET;	
		this->server.sin_addr.s_addr = htonl (INADDR_ANY);
		this->server.sin_port = htons (this->port);

		this->setSocket();
	}

	bool setSocket()
	{
		if((this->serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			return false;
		}

		return true;
	}
public:

	bool setPort(int port)
	{
		this->port = port;
		return true;
	}

	bool sBind()
	{
		if (bind (this->serverSocket, (struct sockaddr *) &this->server, sizeof (struct sockaddr)) == -1)
	    {
	      return false;
	    }
	    return true;
	}

	bool sListen()
	{
		if (listen (this->serverSocket, 200) == -1)
	    {
	      return false;
	    }
	    return true;
	}

	int sAccept()
	{
		socklen_t length = sizeof(this->from);
		return accept(this->serverSocket, (struct sockaddr*) &this->from, &length);
	}

	Server(int port)
	{
		this->setPort(port);
		this->setServer();
		this->sBind();
		this->sListen();
	}
	~Server();
	
};