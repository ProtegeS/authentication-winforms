#pragma once

namespace authenticationwinforms {

	using namespace System;
	using namespace MySql::Data::MySqlClient; // sql database connection

	ref class DB
	{
		// Create SqlConnection
		String^ constr = "Server=127.0.0.1;Uid=root;Pwd=;Database=database";
		MySqlConnection^ con = gcnew MySqlConnection(constr);

	public: void openConnection() {
		if (con->State == System::Data::ConnectionState::Closed)
			con->Open(); // open the connection
	}

	public: void closeConnection() {
		if (con->State == System::Data::ConnectionState::Open)
			con->Close(); // close the connection
	}

	public: MySqlConnection^ getConnection() {
		return con;
	}
	};

}