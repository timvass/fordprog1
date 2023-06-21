#include <iostream>
#include <string> 
using namespace std;
class DFA_illegal_character{}; 

class DFA { 
    public:
    bool IsAcceptable(const string &s){ 
        SetInitial();
        for(unsigned int i=0;i<s.size();i++)
            Step(s[i]);
        return IsFinal();    
    }
    
    private:
    unsigned int state; 
    
    void SetInitial(){ 
        state=0; 
    }
        
    void Step(const char c){
            if(state==0){
                if(c>='0'&&c<='9'){
                    state=1;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=2;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=3;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
                
            }else
            if(state==1){
                if(c>='0'&&c<='9'){
                    state=0;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=2;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=3;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==2){
                if(c>='0'&&c<='9'){
                    state=1;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=0;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=3;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==3){
                if(c>='0'&&c<='9'){
                    state=1;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=2;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=0;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==4){
                if(c>='0'&&c<='9'){
                    state=5;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=6;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=9;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==5){
                if(c>='0'&&c<='9'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=6;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=9;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==6){
                if(c>='0'&&c<='9'){
                    state=5;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=4;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=9;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==8){
                if(c>='0'&&c<='9'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }else
            if(state==9){
                if(c>='0'&&c<='9'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c>='a'&&c<='z'){
                    state=9;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='.'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;
                }else
                if(c=='@'){
                    state=8;
                    cout<<c<<" state: "<<state<<endl;    
                }else{
                    throw DFA_illegal_character();
                }
            }
            
        }
        
        bool IsFinal(){
            return state==2 || state==4;
        }

};

int main()
{
    string s;
    cout<<"Ird be a DFA-t \n";
    cin >> s; 

    try{
        if(DFA().IsAcceptable(s))
            cout<<"Accepted."<<endl; 
        else    
            cout<<"Rejected.\n";
    }catch(DFA_illegal_character){
        cerr<<"Illegal character. \n";
    }
    
    return 0;
}
