//
// Created by hbzhao on 2017/11/3.
//
#include <string>
#include <time.h>
#include <map>
using namespace std;

//535. Encode and Decode TinyURL
class Solution1{
private:
    map<string,string> short2long,long2short;
    string dict1 = "01qrstuvwxABCDEFGHIJKLMNOPe23456789abcdyzmnopfghijklQRSTUVWXYZ";
public:
    string encode(string longUrl){
        srand(time(NULL));
        string shorturl;
        for(int i=0;i<6;i++){
            shorturl+=this->dict1[rand()%62];
        }
        this->short2long.insert({shorturl,longUrl});
        this->long2short.insert({longUrl,shorturl});
        return "http://tinyurl.com/"+shorturl;
    }
    string decode(string shortUrl){
        string randurl;
        randurl=shortUrl.substr(shortUrl.find_last_of('/')+1);
        return this->short2long[randurl];
    }
};