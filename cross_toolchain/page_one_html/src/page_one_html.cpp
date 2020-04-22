
#include<iostream>

using namespace std;
int main()

{
cout<< "<title>NUTRITIONAL TRACKER 1.0</title>"<<endl;
cout<< "Content-type: text/html; charset=utf-8 \n\n"<<endl;
cout<<"<style> "<<endl;
cout<<"html{ font-size: 10pt;} "<<endl;
cout<<"body{ background-image: url(https://www.forumhealthcentre.nhs.uk/UserFiles/Thumbnails/Wellness_Health_Lifestyle/shutterstock_67699489_1__h1000_w500.jpg);} "<<endl;
cout<<".loginform label{display: block; color: #999;}"<<endl;
cout<<".cf :before,"<<endl;
cout<<".cf:after{content:\"\";display: table;}"<<endl;
cout<<".cf:after{clear:both;}"<<endl;
cout<<".cf {*zoom:1;}"<<endl;
cout<<":focus{outline:0;}"<<endl;
cout<<".loginform{width:410px;margin:20px auto;padding:25px;background-color:#FFF8DC;border-radius:5px;box-shadow:0px 0px 5px 0px #DEB887;inset 0px 1px 0px 0px rgba(250,250,250,0.5);border:1px solid rgba(0,0,0,0.3);}"<<endl;
cout<<".loginform2 {width:700px;margin:20px auto;padding:25px;background-color:#FFF8DC;border-radius:5px;box-shadow:0px 0px 5px 0px #DEB887;inset 0px 1px 0px 0px rgba(250,250,250,0.5);border:1px solid rgba(0,0,0,0.3);}"<<endl;
cout<<".loginform ul{padding:0;margin:0;}"<<endl;
cout<<".loginform li{display:inline;style.c; float: left;}"<<endl;
cout<<".loginform input:not([type=submit]){padding:5px;margin-right:10px;border:1px solid rgba(0,0,0,0.3);border-radius:3px;box-shadow:inset 0px 1px 3px 0px rgba(0,0,0,0.1),0px 1px 0px 0px rgba(250,250,250,0.5);}"<<endl;
cout<<".loginform input[type=submit] {"
	<<"border: 1px solid rgba(0, 0, 0, 0.3);"
	<<"background: #64c8ef;"
	<<"background: -moz-linear-gradient(top,  #64c8ef 0%, #00a2e2 100%);"
	<<"background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,#64c8ef), color-stop(100%,#00a2e2));"
	<<"background: -webkit-linear-gradient(top,  #64c8ef 0%,#00a2e2 100%);"
	<<"filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#64c8ef', endColorstr='#00a2e2',GradientType=0 );"
	<<"color: #fff;	padding: 5px 15px;	margin-right: 0;margin-top: 15px;border-radius: 3px;text-shadow: 1px 1px 0px rgba(0, 0, 0, 0.3);}"<<endl;

cout<<"</style> "<<endl;
cout<< "<html><body>"<<endl;
cout<< "<h1 class=\"loginform cf\"align=\"center\" style=\"color: FireBrick;\"><font size=\"5\">NUTRITIONAL TRACKER 1.0</font> </h1>"<<endl;
cout<< "<h2 class=\"loginform2 cf\"align=\"center\" style=\"color: FireBrick;\"><font size=\"3\">Nutrtitional"
 <<"Tracker is the modern IOT product which promotes 5-a day strategy in our lives."
<<"<br>Consuming 5 portions of fruit & veg is healthy way to complete balanced diet."
<<"<br> This product keeps a track of your grocery bought and analyzes it for you in fraction of seconds."
<<"<br>For Details:<a target=\"_blank\"href=\"https://github.com/alpitabrol/NUTRITIONAL-TRACKER\"</font\">\"Click here\"</a></font> </h2>"<<endl;
cout<< "<h3 align=\"center\" style=\"color: Black;\"><font size=\"6\">Let's get your 5 portion of Vegetables & Fruits!</font> </h3>"<<endl;
cout<< "</div>"<<endl;
cout<< "<div class=\"loginform cf\">"<<endl;
cout << "<form name=\"login\" action=\"server_conn\" method=\"get\" accept-charset=\"utf-8\">"<<endl;
cout<< "<ul>"<<endl;
cout<< "<li>"<<endl;
cout<< "<label for=\"username\">Username</label>"<<endl;
cout<< "<input type=\"username\" name=\"username\" placeholder=\"Your Name\" required>"<<endl;
cout<< "</li>"<<endl;
cout<< "<input type=\"submit\" value=\"Start Shopping\">"<<endl;
cout<< "</li></ul></form></div>"<<endl;

cout<< "<div><a href=\"https://github.com/alpitabrol\"><img style=\"position: absolute;"
<<"top: 0; right: 0; border: 0;\" "
<<"src=\"https://camo.githubusercontent.com/"
<<"365986a132ccd6a44c23a9169022c0b5c890c387/68747470733a2f2f73332e616d617a6f6e6177732e636f6d2f6769746875622f726962"
<<"626f6e732f666f726b6d655f72696768745f7265645f6161303030302e706e67\" alt=\"Fork me on GitHub\""
<<" data-canonical-src=\"https://s3.amazonaws.com/github/ribbons/forkme_right_red_aa0000.png\"></a></div>" <<endl;
cout<<"<h5 align = \"right\" style= \"color: 9B1650\"><font size=\"5\">Thanks for using our Product.</font></h5>"<<endl;
cout<<"<h6 align = \"right\" style= \"color: 9B1650\">AB</h6>"<<endl;
cout<< "</body></html>";
return 0;
}





/*#include<iostream>

using namespace std;
int main()
{
cout<< "Content-type: text/html; charset=utf-8 \n\n"<<endl;
cout<<"<style> "<<endl;
cout<<"html{ font-size: 10pt;} "<<endl;
cout<<"body{ background-image: url(https://www.forumhealthcentre.nhs.uk/UserFiles/Thumbnails/Wellness_Health_Lifestyle/shutterstock_67699489_1__h1000_w500.jpg);} "<<endl;
cout<<".loginform label{display: block; color: #999;}"<<endl;
cout<<".cf :before,"<<endl;
cout<<".cf:after{content:\"\";display: table;}"<<endl;
cout<<".cf:after{clear:both;}"<<endl;
cout<<".cf {*zoom:1;}"<<endl;
cout<<":focus{outline:0;}"<<endl;
cout<<".loginform{width:410px;margin:50px auto;padding:25px;background-color:#FFF8DC;border-radius:5px;box-shadow:0px 0px 5px 0px #DEB887;inset 0px 1px 0px 0px rgba(250,250,250,0.5);border:1px solid rgba(0,0,0,0.3);}"<<endl;
cout<<".loginform ul{padding:0;margin:0;}"<<endl;
cout<<".loginform li{display:inline;style.c; float: left;}"<<endl;
cout<<".loginform input:not([type=submit]){padding:5px;margin-right:10px;border:1px solid rgba(0,0,0,0.3);border-radius:3px;box-shadow:inset 0px 1px 3px 0px rgba(0,0,0,0.1),0px 1px 0px 0px rgba(250,250,250,0.5);}"<<endl;
cout<<".loginform input[type=submit] {"
	<<"border: 1px solid rgba(0, 0, 0, 0.3);"
	<<"background: #64c8ef;"
	<<"background: -moz-linear-gradient(top,  #64c8ef 0%, #00a2e2 100%);"
	<<"background: -webkit-gradient(linear, left top, left bottom, color-stop(0%,#64c8ef), color-stop(100%,#00a2e2));"
	<<"background: -webkit-linear-gradient(top,  #64c8ef 0%,#00a2e2 100%);"
	<<"filter: progid:DXImageTransform.Microsoft.gradient( startColorstr='#64c8ef', endColorstr='#00a2e2',GradientType=0 );"
	<<"color: #fff;	padding: 5px 15px;	margin-right: 0;margin-top: 15px;border-radius: 3px;text-shadow: 1px 1px 0px rgba(0, 0, 0, 0.3);}"<<endl;

cout<<"</style> "<<endl;
cout<< "<html><body>"<<endl;
cout<< "<h1 align=\"center\" style=\"color: FireBrick;\">NUTRITIONAL TRACKER </h1>"<<endl;
cout<< "</div>"<<endl;
cout<< "<div class=\"loginform cf\">"<<endl;
cout << "<form name=\"login\" action=\"server_conn\" method=\"get\" accept-charset=\"utf-8\">"<<endl;
cout<< "<ul>"<<endl;
cout<< "<li>"<<endl;
cout<< "<label for=\"username\">Username</label>"<<endl;
cout<< "<input type=\"username\" name=\"username\" placeholder=\"Your Name\" required>"<<endl;
cout<< "</li>"<<endl;
cout<< "<input type=\"submit\" value=\"Track Nutrition\">"<<endl;
cout<< "</li></ul></form></div>"<<endl;


cout<< "</body></html>";
return 0;
}
*/
