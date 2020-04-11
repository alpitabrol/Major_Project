#include <stdlib.h>
#include <iostream>
/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
 */
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using ::std::cout;
using ::std::endl;

int main(void) {
    cout << endl;
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");
        /* Connect to the MySQL test database */
        con->setSchema("nutrition_tracker");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * from eatable_details");
        cout << "Content-type:text/html\r\n\r\n";
        cout << "<html>\n";
        cout << "<head>\n";
        cout << "<title>CGI Environment Variables</title>\n";
        cout << "</head>\n";
        cout << "<body>\n";
        cout << "<table border = \"0\" cellspacing = \"2\">";
        cout << "<th>";
        cout << "<td>PLU Code</td>";
        cout << "<td>Commodity</td>";
        cout << "<td>Variety</td>";
        cout << "<td>Size</td>";
        cout << "<td>1 Lb Pieces</td>";
        cout << "<td>Portions</td>";
        cout << "<td>Portions/piece</td>";
        cout << "</th>\n";


        while (res->next()) {
            cout << "<tr>";
            cout << "<td>" << res->getString("plu_Code") << "</td>";
            cout << "<td>" << res->getString("commodity") << "</td>";
            cout << "<td>" << res->getString("variety") << "</td>";
            cout << "<td>" << res->getString("size") << "</td>";
            cout << "<td>" << res->getString("one_lb_pieces") << "</td>";
            cout << "<td>" << res->getString("portions") << "</td>";
            cout << "<td>" << res->getString("portions_per_piece") << "</td>";
            cout << "</tr>\n";
        }

        cout << "</table>\n";
        cout << "</body>\n";
        cout << "</html>\n";

        delete res;
        delete stmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return EXIT_SUCCESS;
}
