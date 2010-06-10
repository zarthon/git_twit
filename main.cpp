#include<iostream>
#include<curl/curl.h>
#include<string>
#include<cstring>
#include<curses.h>
using namespace std;

void input_user(string &user){
	cout<<"Enter Username: ";
	cin>>user;
	return;
}

void input_pass(string &pass){
	char ch[100];
	initscr();
	printw("Enter Password: ");
	noecho();
	getstr(ch);
	pass = ch;
	echo();
	endwin();
}
int main(){
	string msg,user,pass,final="";
	string status = "";
	char *fina, *sta;

	input_user(user);
	input_pass(pass);

	cout<<"Enter the message: ";
	getline(cin,msg);
	getline(cin,msg);
	if(msg.size()>140){
		msg.erase(140);
	}

	status += "status="+msg;
	final += "http://"+user+":"+pass+"@twitter.com/statuses/update.json";
	
	fina = new char[final.size()+1];
	sta=new char[status.size()+1];
	strcpy(fina,final.c_str());
	strcpy(sta,status.c_str());
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();

	
	if(curl){
		curl_easy_setopt(curl,CURLOPT_URL,fina);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,sta);
		res=curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	return 0;
}
