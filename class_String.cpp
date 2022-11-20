#include <iostream> 
#include <string.h> 
 
using namespace std; 
 
class String 
{  
    char *str; 
    int len; 
     
public: 
 
    String(int l = 0);//+ 
    String(const char *);//+ 
    String(String &);//+ 
 
    ~String()    
    { 
         if(str)  
            delete []str;  
        str = NULL;  
    } 
 
    int Len();//+ 
 
    String & operator = (const String &);//+ 
 
    char &operator [](int);//+ 
 
    bool operator == (String &);//+ 
    bool operator != (String &);//+ 
 
    String operator + (const String &);//+ 
    String & operator += (const String &);//+ 
 
    friend istream & operator >> (istream &, String &);//+ 
    friend ostream & operator << (ostream &, String &);//+ 
 
    int BMH_search(String &);//+- 
}; 
 
int String::BMH_search(String& ptr) 
{ 
    int table[256]; 
 
    for(int i = 0; i < 255; i++) 
    { 
       table[i] = ptr.len; 
    } 

    for(int i = 0; i < ptr.len - 1; i++)
    {
        table[ptr.str[i]] = ptr.len - 1 - i;
    }

    for(int i = 0; i < ptr.len; i++){
        cout<<" "<<table[ptr[i]];
    }
 
    int i = ptr.len - 1;
    int j = ptr.len - 1;
    int k = ptr.len - 1;

    while(i < len)
    {
        if(j < 0) return i + 1 - ptr.len;

        k = i;
        j = ptr.len - 1;

        while(j >= 0)
        {
            if(str[k] == ptr.str[j]){
                j--;
                k--;
            }else{
                cout<<table[str[i]];
                i = i + table[str[i]];
                
                j = ptr.len - 1;
                break;
            }
        }
    }

    if(j >= 0) return (-1);
    else return i + 1 - ptr.len;

}
 
bool String::operator!=(String& s) 
{ 
    if(len != s.len) return true; 
 
    for(int i = 0; i < len; i++){ 
        if(str[i] != s.str[i])  
            return true; 
    } 
    return false; 
} 
 
bool String::operator==(String& s) 
{ 
    if(len != s.len) return false; 
 
    for(int i = 0; i < len; i++) 
        if(str[i] != s.str[i]) 
            return false; 
     
    return true; 
} 
 
istream& operator>>(istream& in, String& str) 
{ 
    cout<<"(cin)Set len, then write str."<<endl; 
    in >> str.len; 
 
    delete[] str.str; 
     
    str.str = new char[str.len]; 
    for(int i = 0; i < str.len; i++) 
    { 
        in >> str.str[i]; 
    } 
    return in;  
} 
 
ostream& operator<<(ostream& out, String& str) 
{ 
    for(int i = 0; i<str.len; i++) 
        out << str.str[i]; 
    return out; 
} 
 
char& String::operator[](int i) 
{ 
    //нужно проверять индексы чтобы не выходили за границы
    return str[i]; 
} 
 
int String::Len() 
{ 
    int lenght = 0; 
    while(str) lenght++; 
    return lenght; 
} 
 
String& String::operator=(const String& s) 
{ 
    if(this != &s) 
    { 
        delete[] str; 
        len = s.len; 
        str = new char[s.len + 1]; 
        for(int i = 0; i < s.len; i++) 
            str[i] = s.str[i]; 
    } 
    str[s.len + 1] = '\0'; 
    return *this; 
} 
 
String String::operator+(const String& s) 
{ 
    String str_plus(len + s.len + 1); 
 
    for(int i = 0; i < len; i++) 
    { 
        str_plus[i] = str[i]; 
    } 
 
    for(int i = 0; i < len + s.len; i++) 
    { 
        str_plus[i + len] = s.str[i]; 
    } 
    // term null
    return str_plus; 
} 
 
String& String::operator+=(const String& s) 
{ 
    int new_lenght = len + s.len; 
    char *new_str = new char[new_lenght + 1]; 
 
    for(int i = 0; i < len; i++) 
        new_str[i] = str[i]; 
     
    for(int i = 0; i < s.len; i++) 
        new_str[len + i] = s.str[i]; 
 
    delete[] str; 
    str = new_str; 
    len = new_lenght; 
    // term null
    return *this; 
} 
 
String::String(String& s) 
{ 
    str = new char[s.Len() + 1]; 
    for(len = 0; str[len] = s.str[len]; len++); 
} 
 
String::String(const char* s) 
{ 
    str = new char[strlen(s) + 1]; 
    for(len = 0; str[len] = s[len]; len++); 
} 
String::String(int l) 
{ 
    str = new char[l]; 
    len = l; 
    str[0] = '\0'; 
} 
 
 
int main() 
{ 
    String s1("Hello, World"); 
    String s12("Hello, World"); 
    String s2(" Vsem privet"); 
    String s3; 
    s3=s1; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<"cout"<<endl; 
    cout<<s3<< endl; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cin>>s3; 
    cout<<s3<< endl; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<" operator == "<<endl; 
    if(s1 == s12) 
        cout<<"Same";
else 
        cout<<"Not Same"; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<" operator != "<<endl; 
    if(s1 != s12) 
        cout<<"Not same"; 
    else 
        cout<<"Same"; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<" operator + "<<endl; 
    String s5; 
    s5=s1+s2; 
    cout<<s5; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<" operator += "<<endl; 
    String s6("123"); 
    String s7("4567"); 
    s6 += s7; 
    cout<<s6; 
    cout<<"\n------------------------------------------------------------"<<endl; 
    cout<<" BMH search \n"; 
    String s100("aabbc"); 
    String s101("abb"); 
    int enter = s100.BMH_search(s101); 
    cout<<"enter = "<<enter<<endl; 
    cout<<"\n------------------------------------------------------------"<<endl;
    return 0; 
}