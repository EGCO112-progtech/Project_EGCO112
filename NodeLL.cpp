//All Node related function

#include "NodeLL.h"
#include "ctime"

// <------------- Node ------------->

/*Node*/
NODE::NODE(){
      static long x = 130000;
      NodeID = ++x;
      cout << "adding NodeID @ NODE : " << x << endl;
}
  NODE:: ~NODE(){
      cout << "NodeID " << NodeID << " is being deleted" << endl;
}
void  NODE:: show_data(){
         cout << "NodeID @ NODE : " << NodeID << endl;
 }

/*general*/
general::general(string inName, string inmfg, string inexp, long inLotNo):NODE(){
      static long x = 0, y = 500000;
      LotID = ++x;
      if(inLotNo) LotNo = ++y;
      name = inName;
      mfg = inmfg;
      exp = inexp;
      // time input
      time_t curr_time;
	curr_time = time(NULL);
      string realtime = ctime(&curr_time);
	cout << "Today is : " << realtime; //Tue Apr 25 12:31:25 2023

}
  general:: ~general(){
      cout << "NodeID " << NodeID << " is being deleted" << endl;
}
void  general:: show_data(){
         cout << "NodeID @ NODE : " << NodeID << endl;
 }
/*consumable: general*/
/*food:consumable*/
/*drinks: consumable*/
/*appliance: general*/
/*dailyUse: appliance*/
/*specificPurpose: appliance*/

// <------------- LL ------------->

LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
     NODE *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}

void LL::show_all(){
     NODE* t=hol;
     int i;
     cout << endl << "=== Show Linkedlist ==" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "=== End of Show Linkedlist ==" << endl;
}
void LL::add_node(NODE *&A){

          hol->insert(A);
          hol=A;

       size++;

 }