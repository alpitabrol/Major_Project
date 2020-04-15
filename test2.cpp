
#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

int main(){

	char *value = getenv("REMOTE_ADDR");    // The remote IP address
	// cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
	   cout << html() << head() << title("LED Example") << head() << endl;
	   cout << body() << h1("Exploring RPi POST LED Example") << endl;;


	   cout << body() << html();
	   return 0;
}
