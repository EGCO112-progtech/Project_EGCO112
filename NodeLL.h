//All Node stucture

#ifndef NodeLL_h
#define NodeLL_h

/*
========================================
   Stucture of Inheritance 22.04.2023
========================================

                    NODE
                     |
                  general
                  /     \ 
                 /       \
       consumable         appliance
       /        \         /      \
    food      drinks  dailyUse  SpecPur
     ||         ||       ||       ||
   LLFood    LLDrinks   LLDai   LLSpec
========================================
*/

// <------------- Node ------------->

/*Node*/
class NODE {
    private:
    protected:
        long NodeID;
    public:
        NODE();
        //~NODE();
        //void show_data();
        virtual ~NODE() = 0;
        virtual void show_data() = 0;
        virtual void insert(NODE*&) = 0;
        //void insert(NODE*&);
        //NODE* move_next();
};
/*general*/
class general:public NODE{
    private:
    protected:
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime, deliveryBy;
    public:
        general(string, string, string, long = 0);
        virtual ~general() = 0;
        virtual void show_data() = 0;;
};

/*consumable: general*/
class consumable:public general{
    private:
    protected:
        double weightAll;
        int quantityContainer, quantityEach;
    public:
        consumable();
        virtual ~consumable() = 0;
        virtual void show_data() = 0;
        virtual void insert(consumable*&) = 0;
        consumable* move_next();
};
/*food:consumable*/
class food:public consumable{
    private:
        food *next;
    protected:
        double weightEach;
    public:
        food();
        ~food();
        void show_data();
        void insert(food*&);
        food* move_next();
};
/*drinks: consumable*/
class drinks:public consumable{
    private:
        drinks *next;
    protected:
        double volumeEach;
    public:
        drinks();
        ~drinks();
        void show_data();
        void insert( drinks*&);
        drinks* move_next();
};

/*appliance: general*/
class appliance:public general{
    private:
    protected:
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
    public:
        appliance();
        virtual ~appliance() = 0;
        virtual void show_data() = 0;
        virtual void insert( drinks*&) = 0;
        appliance* move_next();
};
/*dailyUse: appliance*/
class dailyUse:public appliance{
    private:
        dailyUse *next;
    protected:
        string details;
    public:
        dailyUse();
        ~dailyUse();
        void show_data();
        void insert( drinks*&);
        dailyUse* move_next();
};
/*specificPurpose: appliance*/
class specificPurpose:public appliance{
    private:
        specificPurpose *next;
    protected:
        string caution;
    public:
        specificPurpose();
        ~specificPurpose();
        void show_data();
        void insert( drinks*&);
        specificPurpose* move_next();
};
/*
food{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime, deliveryBy;
        double weightAll;
        int quantityContainer, quantityEach;
        double weightEach;
}
drinks{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime, deliveryBy;
        double weightAll;
        int quantityContainer, quantityEach;
        double volumeEach;
}
dailyUse{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime, deliveryBy;
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
        string details;
}
specificPurpose{
        long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime, deliveryBy;
        string Usefor;
        double weightAll;
        int quantityContainer, quantityEach;
        string caution;
}
*/
// <------------- LL ------------->

class LL{
      NODE*hol;
      int size;
public:
       void add_node(NODE*&);
       void show_all();
       ~LL();
       LL();
      
};

#endif