#include <iostream>
#include <string.h>
using namespace std;

class Driver{
private:
    char* name;
    int driver_id;
public:
    Driver(char* n = "Blank",int id = 0){
        unsigned long length = strlen(n);
        name = new char[length+1];
        strcpy(name,n);
        driver_id = id;
    };
    ~Driver(){
    delete [] name;
    };
    char* getdName(){
    return name;
    };
    void setdName(char* n){
        unsigned long length = strlen(n);
        name = new char[length+1];
        strcpy(name,n);
    };
    int getdID(){
    return driver_id;
    };
    void setdID(int id){
    driver_id = id;
    };
    bool operator ==(const Driver& d) {
        cout<<"checking ID...";
        if(driver_id == d.driver_id) {
            cout<<"ID matched"<<endl<<"checking name...";
            if(strcmp(name,d.name)==0){
            cout<<"name matched, both are equal";
            return true;
            }
            else{
            cout<<"name did not match, error";
            return false;
            }
         }
         return false;
      };
    Driver& operator=(const Driver& x){
        unsigned long length = strlen(x.name);
        name = new char[length+1];
        strcpy(name,x.name);
        driver_id = x.driver_id;
        return *this;
      }
};
class Taxi_Cab{
private:
    char* brand;//brand name of the car
    int license_number;//license number of the car
    Driver driv;//each Taxi_Cab is assigned a unique driver.
    Taxi_Cab *next;//linked list of Taxi cabs, each with unique driver.
public:
    Taxi_Cab(char* b ="EMPTY", int l = 0,int id=0, char* dn = "Blank"){
        brand = new char[strlen(b)+1];
        strcpy(brand,b);
        license_number = l;
        driv.setdID(id);
        driv.setdName(dn);
        next = NULL;
    };
    ~Taxi_Cab(){
    delete [] brand;
    };
    Taxi_Cab operator+(const Driver x){
    Taxi_Cab result = *this;
    result.setDriver(x);
    return result;
    };
    bool operator ==(const Taxi_Cab& t) {
        cout<<"checking brand...";
            if(strcmp(brand,t.brand)==0){
            cout<<"name matched"<<endl<<"checking license no...";
                if(license_number==t.license_number){
                cout<<"license number matched"<<endl<<"checking driver...";
                    if(driv==t.driv){
                    cout<<"driver matched";
                    return true;
                    }
                }
            }
         return false;
      };
    char* getBrand(){
    return brand;
    };
    void setBrand(char* b){
        brand = new char[strlen(b)+1];
        strcpy(brand,b);
    };
    int getLicense(){
    return license_number;
    };
    void setLicense(int l){
    license_number = l;
    };
    int getdID(){
    return driv.getdID();
    };
    void setdID(int d){
    driv.setdID(d);
    };
    Driver getDriver(){
    return driv;
    };
    void setDriver(Driver d){
    driv = d;
    };
    char* getdName(){
    return driv.getdName();
    };
    void setdName(char* d){
    driv.setdName(d);
    };
    Taxi_Cab* gettNext() const{
    return next;
    };
    void settNext(Taxi_Cab *t){
    next = t;
    };
    void copyCab(Taxi_Cab *c){
        if(this!=NULL){
            delete [] brand;
        }
        brand = new char[strlen(brand)+1];
        strcpy(brand,c->getBrand());
        license_number=c->getLicense();
        driv = c->driv;
        return;
    };
    void printCab(){
    cout << "\nTaxi Cab:\t\t"<<brand<<"\t\t"<<license_number<<"\t\t"<<driv.getdID()<<"\t\t"<<driv.getdName();
    };
    void printDriver(){
    cout << "\nDriver:\t\t\t"<<driv.getdID()<<"\t\t"<<driv.getdName();
    };
};
class Employer{
private:
    char* name;
    int Employer_ID;
    Employer *next;
    Taxi_Cab *thead;
    int capacity;//just a counter for how many drivers are under employment
public:
    Employer(char* n = "Blank", int ID = 0){
        name = new char[strlen(n)+1];
        strcpy(name,n);
        Employer_ID = ID;
        thead = NULL;
        next = NULL;
        capacity = 0;
    };//default constructor
    ~Employer(){
    removeAllTaxi_Cab();
    delete [] name;
    };
    Employer(const Employer& x){
        Taxi_Cab *etr, *xtr = x.thead;
        while(xtr){
            Taxi_Cab *ntr = new Taxi_Cab();
            if(!ntr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
            ntr->copyCab(xtr);
            if(!thead){thead=ntr;}
            else{etr->settNext(ntr);}
            etr=ntr;
            xtr=xtr->gettNext();
        }
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
        Employer_ID = x.Employer_ID;
        capacity = x.capacity;
    };
    Employer& operator=(const Employer& x){

    if(this == &x){return *this;}
        Taxi_Cab *ttr = thead;
        while(ttr){
            ttr=ttr->gettNext();
            delete thead;
            thead = ttr;
        }
        Taxi_Cab *xtr = x.thead;
        while(xtr){
            Taxi_Cab *ntr = new Taxi_Cab();
            if(!ntr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
        ntr->copyCab(xtr);
        if(!thead){thead=ntr;}
        else{ttr->settNext(ntr);}
        ttr=ntr;
        xtr=xtr->gettNext();
        }
        unsigned long length = strlen(x.name);
        name = new char[length+1];
        strcpy(name,x.name);
        Employer_ID = x.Employer_ID;
        capacity = x.capacity;
        return *this;

    };
    char* geteName(){
    return name;
    };
    void seteName(char* n){
        name = new char[strlen(n)+1];
        strcpy(name,n);
    };
    int geteID(){
        return Employer_ID;};
    void seteID(int ID){
        Employer_ID = ID;};
    Employer* geteNext() const{
        return next;};
    void seteNext(Employer* n){
        next = n;};
    Taxi_Cab* gettHead() const{
    return thead;
    };
    void settHead(Taxi_Cab* t){
    thead = t;
    };
    void removeAllTaxi_Cab(){
    Taxi_Cab* ttr = thead;
    while(ttr){
        ttr = ttr->gettNext();
        delete thead;
        thead = ttr;
    }
    capacity = 0;
    };//remove all taxi cab
    void copyEmployer(Employer *e){
        if(this!=NULL){
            delete [] name;
        }
        name = new char[strlen(name)+1];
        strcpy(name,e->geteName());
        Employer_ID=e->geteID();
        capacity = e->capacity;
        return;
    };
    void printEmployer(){
    //if(capacity==0){
    //    cout<<
    //}
    cout << "\nEmployer created:\t"<<name<<"\t\t"<<Employer_ID<<"\t\t"<<capacity;
    };
    void printCabList(){
        Taxi_Cab* tc=thead;
        if(tc==NULL){
            cout<<"\nEmpty list, could not be printed\n";
            return;
        }
        cout<<"\n"<<name<<"'s CabList:\t\tBrand\t\tLicense No.\tDriver ID\tDriver Name";
        while (tc)
        {
            tc->printCab();
            tc=tc->gettNext();
        }
        cout<<endl;
    };
    int getCap(){
    return capacity;
    };
    void setCap(int c){
    capacity = c;
    };
        void addCab(char* b = "Empty",int l=0, int ID=0,char* dn = "Blank"){
        Taxi_Cab *c = gettHead();
        if(thead==NULL){
            Taxi_Cab* temp = new Taxi_Cab(b,l,ID,dn);
            thead = temp;
            return;
        }
        int cond = 0;
        while(c){
            if(c->getdID()==ID){cond=1;}
            if(c->getLicense()==l){cond=1;}
            c=c->gettNext();
        }
        c = gettHead();
        if(cond==0){
            Taxi_Cab *temp= new Taxi_Cab(b,l,ID,dn);
            temp->settNext(c);
            this->thead=temp;
            }
    };
    inline void addCab(Taxi_Cab x){
    addCab(x.getBrand(),x.getLicense(),x.getdID(),x.getdName());
    };
};
class Taxi_Agency{
private:
    char* name;
    Employer *ehead;//linked list of all employers
    Taxi_Cab *thead;//linked list of all taxi cabs
public:
    Taxi_Agency(char* n = "Untitled"){
    name = new char[strlen(n+1)];
    strcpy(name,n);
    ehead = NULL;
    thead = NULL;
    };
    ~Taxi_Agency(){
    //removeAllData();
    delete ehead;
    delete thead;
    delete [] name;

    };
    Taxi_Agency(const Taxi_Agency& x){
    Employer *etr, *xtr = x.ehead;
    Taxi_Cab *ttr, *ytr = x.thead;
        while(xtr){
            Employer *ntr = new Employer();
            if(!ntr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
            ntr->copyEmployer(xtr);
            if(!ehead){ehead=ntr;}
            else{etr->seteNext(ntr);}
            etr=ntr;
            xtr=xtr->geteNext();
        }
        while(ytr){
            Taxi_Cab *mtr = new Taxi_Cab();
            if(!mtr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
            mtr->copyCab(ytr);
            if(!thead){thead=mtr;}
            else{ttr->settNext(mtr);}
            ttr=mtr;
            ytr=ytr->gettNext();
        }
    };
    Taxi_Agency& operator=(const Taxi_Agency& x){
    if(this == &x){return *this;}
        Employer *etr = ehead;
        Taxi_Cab *ttr = thead;
        while(etr){
            etr=etr->geteNext();
            delete ehead;
            ehead = etr;
        }
        while(ttr){
            ttr=ttr->gettNext();
            delete thead;
            thead = ttr;
        }
        Employer *xtr = x.ehead;
        Taxi_Cab *ytr = x.thead;
        while(xtr){
            Employer *ntr = new Employer();
            if(!ntr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
        ntr->copyEmployer(xtr);
        if(!ehead){ehead=ntr;}
        else{etr->seteNext(ntr);}
        etr=ntr;
        xtr=xtr->geteNext();
        }
        while(ytr){
            Taxi_Cab *mtr = new Taxi_Cab();
            if(!mtr){
                cerr<<"Allocation memory failure!\n";
                break;
            }
        mtr->copyCab(ytr);
        if(!thead)
            thead = mtr;
        else
            ttr->settNext(mtr);
        ttr=mtr;
        ytr=ytr->gettNext();
        }
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
        return *this;
    };
    Taxi_Agency operator+(const Taxi_Agency& x)const{
    Taxi_Agency temp;
    Employer* etr = ehead;
    Employer* xtr = x.ehead;
    Taxi_Cab* ttr = thead;
    Taxi_Cab* ytr = x.thead;
    Employer* ee;
    Taxi_Cab* tt;

    while(etr){
        Employer* ntr = new Employer();
        ntr->copyEmployer(etr);
        ntr->seteNext(NULL);
        if(!temp.ehead){
            temp.ehead = ntr;
            ee = ntr;
        }
        else{ee->seteNext(ntr);}
        ee = ntr;
        etr = etr->geteNext();
    }
    while(ttr){
        Taxi_Cab* mtr = new Taxi_Cab();
        mtr->copyCab(ttr);
        mtr->settNext(NULL);
        if(!temp.thead){
            temp.thead = mtr;
            tt = mtr;
        }
        else{tt->settNext(mtr);}
        tt = mtr;
        ttr = ttr->gettNext();
    }
    Employer *e;
    Taxi_Cab *t;

    while(xtr){
        e = temp.ehead;
        int cond1 = 0;
        while(e){

            if(e->geteID()==xtr->geteID()){cond1=1;}
            e=e->geteNext();
        }
        if(cond1==0){
            Employer* ntr=new Employer();
            ntr->copyEmployer(xtr);
            ntr->seteNext(NULL);
            if(!temp.ehead){
                temp.ehead=ntr;
                ee=ntr;
            }
            else{ee->seteNext(ntr);}
            ee = ntr;
        }
        xtr = xtr->geteNext();
    }
    while(ytr){
        t = temp.thead;
        int cond2 = 0;
        while(t){
            if(t->getdID()==ytr->getdID()){cond2=1;}
            t=t->gettNext();
        }
        if(cond2==0){
            Taxi_Cab* mtr=new Taxi_Cab();
            mtr->copyCab(ytr);
            mtr->settNext(NULL);
            if(!temp.thead){
                temp.thead=mtr;
                tt=mtr;
            }
            else{tt->settNext(mtr);}
            tt = mtr;
        }
        ytr = ytr->gettNext();
    }
    temp.setName(name);
    return temp;
    };//combining two Taxi_Agencies
    Taxi_Agency operator-(const Taxi_Agency& x){
    Taxi_Agency temp;
    Employer *xtr = x.ehead;
    Employer *wtr = ehead;
    Taxi_Cab *ytr = x.thead;
    Taxi_Cab *ztr = thead;
    Employer* ee;
    Taxi_Cab* tt;
    while(xtr){
        wtr = ehead;
        while(wtr){
            if(xtr->geteID()==wtr->geteID()){break;}
            wtr=wtr->geteNext();
        }
        if(wtr==NULL){
            Employer* ntr = new Employer();
            ntr->copyEmployer(xtr);
            ntr->seteNext(NULL);
            if(!temp.ehead){
                temp.ehead = ntr;
                ee = ntr;
            }
            else{ee->seteNext(ntr);}
            ee = ntr;
        }
        xtr = xtr->geteNext();
    }
    while(ytr){
        ztr = thead;
        while(ztr){
            if(ytr->getdID()==ztr->getdID()){break;}
            ztr=ztr->gettNext();
        }
        if(ztr==NULL){
            Taxi_Cab* mtr = new Taxi_Cab();
            mtr->copyCab(ytr);
            mtr->settNext(NULL);
            if(!temp.thead){
                temp.thead = mtr;
                tt = mtr;
            }
            else{tt->settNext(mtr);}
            tt = mtr;
        }
        ytr = ytr->gettNext();
    }
    temp.setName(name);
    return temp;
    };//from first list it removes any employee also present on the second list
    char* getName(){
    return name;
    };
    void setName(char* n){
    name = new char[strlen(n)+1];
    strcpy(name,n);
    };
    Employer* geteHead() const{
    return ehead;
    };
    Taxi_Cab* gettHead() const{
    return thead;
    };
    void removeAllEmployer(){
    Employer* etr = ehead;
    while(etr){
        etr = etr->geteNext();
        delete ehead;
        ehead = etr;
    }
    };//remove all employers
    void removeAllTaxi_Cab(){
    Taxi_Cab* ttr = thead;
    while(ttr){
        ttr = ttr->gettNext();
        delete thead;
        thead = ttr;
    }
    };//remove all taxi cab
    void removeAllData(){
    removeAllEmployer();
    removeAllTaxi_Cab();
    delete [] name;
    };//removeallemployer and removealltaxicab
    void printEmployerList(){
        Employer* e=ehead;
        if(e==NULL){
            cout<<"\nEmpty list, could not be printed\n";
            return;
        }
        cout<<"\nEmployerList created:\tName\t\tEmployer ID\tCapacity\n";
        while(e)
        {
            if((int)e&0x1){
                break;
            }
            e->printEmployer();
            if(e->gettHead()!=NULL){
                Taxi_Cab* t = e->gettHead();
                while(t){
                //cout<<"L ";
                e->printCabList();
                t = t->gettNext();
                }
            }//cout<<e->geteNext();
            e=e->geteNext();
        }
        cout<<endl;
    };
    void printTaxi_CabList(){
        Taxi_Cab* tc=thead;
        if(tc==NULL){
            cout<<"\nEmpty list, could not be printed\n";
            return;
        }
        cout<<"\n\nCabList created:\tBrand\t\tLicense No.\tDriver ID\tDriver Name\n";
        while (tc!=0)
        {
            tc->printCab();
            tc=tc->gettNext();
        }
        cout<<endl;
    };
    void printDriverList(){
        Taxi_Cab* tc=thead;
        if(tc==NULL){
            cout<<"\nEmpty list, could not be printed\n";
            return;
        }

        cout<<"\n\nDriverList created:\tDriver ID\tDriver Name\n";
        while (tc!=0)
        {
            tc->printDriver();
            tc=tc->gettNext();
        }
        cout<<endl;
    };
    void printAllData(){
    cout<<"\n=================================================================================================";
    cout<<endl<<"\t\t\t\t\tTaxi Agency: "<<name;
    cout<<"\n=================================================================================================";
    cout<<endl<<"\t\t\t\t\tEmployer list\n";
    printEmployerList();
    cout<<"\n=================================================================================================";
    cout<<endl<<"\t\t\t\t\tTaxi Cab list";
    printTaxi_CabList();
    cout<<"\n=================================================================================================";
    };
    void addCab(char* b = "Empty",int l=0, int ID=0,char* dn = "Blank"){
        Taxi_Cab *c = gettHead();
        if(thead==NULL){
            Taxi_Cab* temp = new Taxi_Cab(b,l,ID,dn);
            thead = temp;
            return;
        }
        int cond = 0;
        while(c){
            if(c->getdID()==ID){cond=1;}
            if(c->getLicense()==l){cond=1;}
            c=c->gettNext();
        }
        c = gettHead();
        if(cond==0){
            Taxi_Cab *temp= new Taxi_Cab(b,l,ID,dn);
            temp->settNext(c);
            this->thead=temp;
            }
    };
    inline void addCab(Taxi_Cab x){
    addCab(x.getBrand(),x.getLicense(),x.getdID(),x.getdName());
    };
    void addEmployer(char* n = "Blank",int eid = 0){
        Employer *e = geteHead();
        if(ehead==NULL){
            Employer* temp = new Employer(n,eid);
            ehead=temp ;
            temp->seteNext(NULL);
            return;
        }
        int cond = 0;
        while(e){
            if(e->geteID()==eid){cond=1;}
            e=e->geteNext();
        }
        e=geteHead();
        if(cond==0){

            Employer *temp= new Employer(n,eid);
            temp->seteNext(e);
            this->ehead=temp;

            }
    }
    void removeCab(int l) {
    Taxi_Cab* prev = thead;
    Taxi_Cab* current = thead->gettNext();
    if(prev->getLicense()==l){

        thead = current;
        delete prev;
        return;
    }
    while(current != NULL) {
        if(current->getLicense() == l) {
            break;
        }
        else {
            //cout << "Value " <<current->getLicense() << " does not match " << l << ".\n";
            prev = current;
            current = current->gettNext();
        }
    }
    if(current == NULL) {
        cout << "Can't remove value: no match found.\n";
    } else {
        //cout << "Deleting: " << current->getBrand() << "\n";
        prev->settNext(current->gettNext());
        delete current;
    }
};
    void removeEmployer(int eid) {
    Employer* prev = ehead;
    Employer* current = ehead->geteNext();
    if(prev->geteID()==eid){

        ehead = current;
        delete prev;
        return;
    }
    while(current != NULL) {
        if(current->geteID() == eid) {
            break;
        }
        else {
            //cout << "Value " <<current->geteID() << " does not match " << eid << ".\n";
            prev = current;
            current = current->geteNext();
        }
    }
    if(current == NULL) {
        cout << "Can't remove value: no match found.\n";
    } else {
        //cout << "Deleting: " << current->geteName() << "\n";
        prev->seteNext(current->geteNext());
        delete current;
    }
};
bool checkIfCab(int l){
Employer *e = ehead;

while(e){
    Taxi_Cab *t = e->gettHead();
    while(t){
        if(t->getLicense()==l){return true;}
        t=t->gettNext();
    }
    e=e->geteNext();
}

return false;
}

    void addCtoE(int l,int eid){
        if(checkIfCab(l)==1){cout<<"Cab already assigned to another Employer";return;}
    Taxi_Cab* t = new Taxi_Cab();
    Taxi_Cab* y = new Taxi_Cab();
    t = thead;
    while(t){
        if(t->getLicense()==l){
            y->copyCab(t);
            break;
        }
        else{
            cout<<t->getLicense()<<" does not match "<<l<<endl;
        }
        t=t->gettNext();
    }
    Employer* e = new Employer();
    e = ehead;
    while(e){
        if(e->geteID()==eid){
                if(e->gettHead()==NULL){
                    e->settHead(y);
                    e->setCap(e->getCap()+1);
                    break;
                }
                else{
                    Taxi_Cab *temp= new Taxi_Cab(y->getBrand(),y->getLicense(),y->getdID(),y->getdName());
                    temp->settNext(y);
                    this->thead=temp;
                    e->setCap(e->getCap()+1);
                        /*
                    t = thead;
                    Taxi_Cab *temp = new Taxi_Cab(y->getBrand(),y->getLicense(),y->getdID(),y->getdName());
                    temp->settNext(NULL);
                    if(t==NULL){t=temp;}
                    else{//cout<<"\nc->getnext="<<c->gettNext()<<"\ntemp->getnext="<<temp->gettNext();
                        while(t->gettNext()!=NULL){
                        t=t->gettNext();
                        }
                    t->settNext(temp);
                    }
                e->setCap(e->getCap()+1);
                */
                }
        }
        else{
            cout<<e->geteID()<<" does not match "<<eid<<endl;
        }
        e=e->geteNext();
    }};
    void printCabforEmp(int eid){
    Employer* e = ehead;
    while (e){
        if(e->geteID()==eid){
            e->printCabList();
            return;
        }
        e=e->geteNext();
    }
    cout<<"\nEmployer does not exist.\n";
    };
};

int main()
{

Taxi_Agency Uber("Uber");

Uber.addCab("booo",150900,12,"G");
Uber.addEmployer("b",103900);
Uber.addCab("bttttt",100900,1,"Bl");
Uber.addCab("buuuuu",102900,1);
Uber.addEmployer("juju",1);

Taxi_Agency Umer("Umer");
Umer.addCab("c",12345,33,"polo");
Umer.addEmployer("mm",1212);
Umer.addEmployer("nn",2121);
cout<<"\n\n\nTesting Taxi Cab and Driver relation\n\n\n";
Taxi_Cab A("br",124,123);
Driver PW("br",1234);
A.printCab();
A = A + PW;
A.printCab();
A.printDriver();
Uber.addCab(A);

Taxi_Agency Uner("Uner");
Uner = Uber;
Uber.addCtoE(150900,103900);

Uber.printAllData();

Uner.printCabforEmp(103900);
Uner.printEmployerList();

Uber.addCab("c",190090,2);
Taxi_Agency Uver = Uber + Umer;
Uver.addCab("c",3,3);
Uver.printAllData();


Uver.removeCab(150900);
Uver.printTaxi_CabList();

Uver.addEmployer("h",11);
Uver.addEmployer("h",12);
Uver.addEmployer("h",13);
Uver.addCtoE(3,11);
Uver.addCtoE(3,12);
Uver.printEmployerList();
Uver.printAllData();
Uver.printCabforEmp(11);
Uver.printCabforEmp(12);
Uver.removeEmployer(103900);
Uver.printEmployerList();

Uber = Uver - Uber;
Uber.printAllData();

Uber = Uver + Uber;
Uber.printAllData();

Uver.removeAllData();
Uver.printAllData();
Uber.removeAllEmployer();
Uber.printEmployerList();
Uber.printTaxi_CabList();
Uber.removeAllTaxi_Cab();
Uber.printAllData();



return 0;
}
