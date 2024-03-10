#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

class Person{
    public:
        string s;
        int a,b,c;
        Person(string s, int a, int b, int c){
            this->s=s;
            this->a=a;
            this->b=b;
            this->c=c;
        }
};

bool cmp(const Person &a, const Person &b){
    return make_tuple(a.a, a.b, a.c)>make_tuple(b.a, b.b, b.c);
}

int main() {
    vector<Person> v;
    int n,a,b,c;
    string s;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s>>a>>b>>c;
        v.push_back(Person(s,a,b,c));
    }

    sort(v.begin(), v.end(),cmp);

    for(int i=0;i<n;i++){
        cout<<v[i].s<<' '<<v[i].a<<' '<<v[i].b<<' '<<v[i].c<<'\n';
    }

    return 0;
}