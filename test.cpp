#include <iostream>
#include <stdio.h>
#include <string.h>

#include "class/mysql_connection.h"
using namespace std;

int main()
{
	mysql_connection *sql = new mysql_connection("192.168.1.38", "geodasilva123", "Shinigami123", "game");

	sql->querry("insert into tabela values(5,6,7,8)");
	sql->querry("select * from tabela");
	sql->print();

	return 1;
}