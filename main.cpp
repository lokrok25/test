#include <iostream>

using namespace std;

enum kolor_t
{
    czerwony=1,
    niebieski=2,
    zielony=3,
    nieznany=0
};

ostream& operator<<(ostream& os_, kolor_t  kolor_)
{
    string kolor="nieznany";

    switch(kolor_)
    {
    case czerwony:
        kolor="czerwony";
        break;
    case niebieski:
        kolor="niebieski";
        break;
    case zielony:
        kolor="zielony";
        break;
    }
    os_<<kolor;
    return os_;


}

class Vehicle
{
private:
    int nwhl;
protected:
    kolor_t kolor;
public:
    Vehicle(int nwhl_=4, kolor_t kolor_=nieznany):nwhl(nwhl_), kolor(kolor_){cout<<"New vehicle created"<<endl;}
    virtual ~Vehicle(){cout<<"The vehicle was destroyed"<<endl;}
    /*virtual*/ void Start(){cout<<"???"<<endl;}
    /*virtual*/ void Drive(){cout<<"????"<<endl;}
    /*virtual*/ void Stop(){cout<<"?????"<<endl;}
    void Repaint(kolor_t kolor_){kolor=kolor_;}
    void Journey()
    {
        Start();
        Drive();
        Stop();
    }

    friend ostream& operator<<(ostream& os_, Vehicle& veh_);


};

ostream& operator<<(ostream& os_, Vehicle& veh_)
{
    os_<<"The vehicle with "<<veh_.nwhl<<" wheels, color: "<< veh_.kolor;
    return os_;
}

class Auto: public Vehicle
{
public:
    Auto(kolor_t kolor_):Vehicle(4,kolor_){cout<<"New auto was created"<<endl;}
    ~Auto(){cout<<"The auto was destroyed"<<endl;}
    void Start(){cout<<"Wruuum"<<endl;}
    void Drive(){cout<<"Bziuuu"<<endl;}
    void Stop(){cout<<"Piiisk"<<endl;}
};

class Van: public Auto
{
public:
    Van(kolor_t kolor_):Auto(kolor_){cout<<"New van was created"<<endl;}
    ~Van(){cout<<"The van was destroyed"<<endl;}
    void Start(){cout<<"WRUUUM"<<endl;}
    void Drive(){cout<<"BZIUUU"<<endl;}
    void Stop(){cout<<"PIIISK"<<endl;}
};

void Journey(Vehicle* veh_)
{
    veh_->Start();
    veh_->Drive();
    veh_->Stop();
}

int main()
{
    Vehicle* volvo=new Auto(czerwony);
    Journey(volvo);
    volvo->Journey();
    cout<<*volvo<<endl;
    delete volvo;

    Auto *nysa=new Van(zielony);
    cout<<*nysa<<endl;
    nysa->Repaint(niebieski);
    cout<<*nysa<<endl;
    nysa->Journey();
    delete nysa;


    kolor_t mojkolor=czerwony;
    cout<<mojkolor<<endl;

    return 0;
}
