#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person{
    public:
        string name;
        int height;
        int weight;

        Person(string name, int height, int weight){
            this->name=name;
            this->height=height;
            this->weight=weight;
        }
};

bool cmp(const Person &a, const Person &b){
    return a.height<b.height;
}

vector<Person> v;

int main() {
    int n,a,b;
    string s;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        v.push_back(Person(s,a,b));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<v[i].name<<" "<<v[i].height<<" "<<v[i].weight<<'\n';
    }

    return 0;
}